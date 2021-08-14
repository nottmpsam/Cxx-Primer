#include <iostream>

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
void display1 (student st){
	std::cout << "Fullname: " << st.fullname << 
	std::endl << "Hobby: " << st.hobby << 
	std::endl << "OOP level: " << st.ooplevel
	<< std::endl;
}
void display2(const student* ps)
{
	std::cout << "Fullname: " << ps->fullname << 
	std::endl << "Hobby: " << ps->hobby << 
	std::endl << "OOP level: " << ps->ooplevel
	<< std::endl;
}
void display3(const student pa[], int n) 
{
	std::cout << "Display3" << std::endl;
	for (int i = 0; i < n; ++i) 
	{
		display2(&pa[i]);
	}
}
unsigned int getInfo(student a[], int n)
{
	unsigned int countStudents = 0;
	for (; countStudents < n; ++countStudents) {

		std::cout << "Enter fullname of student: ";
		std::cin.getline(a[countStudents].fullname, SLEN);
		if ((a[countStudents].fullname)[0] == '\0') {
			break;
		}
		std::cout << "Enter hobby of " << a[countStudents].fullname << std::endl;
		std::cin.getline(a[countStudents].hobby, SLEN);
		std::cout << "Enter OOPLEVEL of " << a[countStudents].fullname << std::endl;
		(std::cin >> a[countStudents].ooplevel).get();
	}
	return countStudents;
}

int main()
{
	std::cout << "Enter class size: ";
	int class_size;
	std::cin >> class_size;
	while (std::cin.get() != '\n') continue;
	std::cout << class_size << std::endl;
	student* ptr_stu = new student[class_size];
	unsigned int entered = getInfo(ptr_stu, class_size);
	for (int i = 0; i < entered; ++i) {
		std::cout << "**********" << std::endl;
		display1(ptr_stu[i]);
		std::cout << "**********" << std::endl;
		display2(&ptr_stu[i]);
	}
	std::cout << "**********" << std::endl;
	display3(ptr_stu, entered);
	std::cout << "**********" << std::endl;
	delete [] ptr_stu;
	std::cout << "Done\n" << std::endl;

	return 0;
}
