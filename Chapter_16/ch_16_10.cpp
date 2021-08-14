// vect3.cpp -- using STL functions
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
struct Review {
    std::string title;
    int rating;
    double price;
};

bool titleCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
void ShowReview(const std::shared_ptr<Review> &rr);
bool FillReview(Review &rr);
bool ratingCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);
bool priceCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2);

int main()
{
    using namespace std;
    vector<shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp)) {
        shared_ptr<Review> ptr(new Review(temp));
        books.push_back(ptr);
    }
    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n" 
            << "Rating\tBook\tPrice\n";

        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sorted by title:\nRating\tBook\tPrice\n";
        sort(books.begin(), books.end(), titleCompare);
        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sorted by rating:\nRating\tBook\tPrice\n";
        sort(books.begin(), books.end(), ratingCompare);
        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sorted by price:\nRating\tBook\tPrice\n";
        sort(books.begin(), books.end(), priceCompare);
        for_each(books.begin(), books.end(), ShowReview);
        cout << "Reverse by price:\n";
        for_each(books.rbegin(), books.rend(), ShowReview);
    }
    return 0;
}

bool titleCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->title == r2->title && r1->rating == r2->rating
            && r1->price < r1->price)
        return true;
    else
    return false;
}
bool ratingCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->rating < r2->rating)
        return true;
    return false;
}
bool priceCompare(const std::shared_ptr<Review> &r1, const std::shared_ptr<Review> &r2)
{
    if (r1->price < r2->price)
        return true;
    return false;
}
bool FillReview(Review &rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin,rr.title);
    if (rr.title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    while (!(std::cin >> rr.rating)) {
        std::cin.clear();
        while (std::cin.get() != '\n') {
                continue;
        }
        std::cout << "Enter book rating again: ";
        continue;
    }
    //or with ignore
    std::cin.clear();
    while (std::cin.get() != '\n') 
        continue;

    std::cout << "Enter book price: ";
    while (!(std::cin >> rr.price)) {
        std::cin.clear();
        while (std::cin.get() != '\n') {
                continue;
        }
        std::cout << "Enter book price again: ";
        continue;
    }
    // get rid of rest of input line
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
    return true;
}
void ShowReview(const std::shared_ptr<Review> & rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t"<< rr->price << "$" 
       << std::endl; 
}

