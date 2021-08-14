#include <iostream>
const int M = 12;
const int Y = 3;
int main(void)
{
	   const char* month[M] 
	   {
  	    "January",
  	    "February",
  	    "March",
  	    "April",
        "May",
	      "June",
	      "Jule",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    int sells[M][Y];
    int total_sum = 0;
       
    for (int i = 0; i < M; ++i)
   	{
      std::cout << "How many books did you sell in last 3 (2001 - 2003) years in " << *(month + i) << "?" << std::endl;
      for (int j = 0; j < Y; ++j)
      {
         std::cout << "Enter how many books were selled in this year: 200"  << j+1 << std::endl;
   			 std::cin >> sells[i][j];
         total_sum += sells[i][j];
      } 
    }
   
    for (int j = 0; j < Y; ++j)
    {
      int total_per_year = 0; 
      for(int i = 0; i < M; ++i)
      {
        total_per_year += sells[i][j];  
      } 
      std::cout << "In 200" << j + 1 <<  " year "  << total_per_year << " books were selled! "<< std::endl;  
    }
   	
   	std::cout << "Total sells in 2001-2003 years are: " << total_sum <<" books " << std::endl;

	return 0;
}
