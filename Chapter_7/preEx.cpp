/*
   void function(int*a, int range, int temp) {
   		*(a + i) = temp;
   }
	void function_2(int* begin, int* end, int t) {
		for(int pt = begin; begin != end; ++pt) {
			*pt = value;
		}
	}
	double function_3(const double* arr, int range) {
		double max = arr[0];
		for (int i = 1; i < range; ++i ){
			if (max > arr[i]) {
				max = arr[i];
			}
			//max = (max > arr[i] ? arr[i] : continue); 
		}
		return max;
	}
	6. т.к. создается копия объектов => исходные данные уже защищены
	7. char*, "", []
	8. int replace (char* str, char c1, char c2) { 
		int count  = 0;
		while (*str) {
			if (*str == c1) {
				*str == c2;
				++count;
			}
			++str;
		}
		return count;
	}
	9. строковая константа - то же самое, что и адрес массива
	11. int judge (int (*pointer)(const char) ); // prototype
		int	(*pointer) (const char);
	12. void show(applicant* pointer) {
			std::cout << pointer->name;
			std::cout << std::endl;
			for (int i = 0; i < 3; ++i) {
				std::cout << pointer->credit_ratings[i] << " ";
			}
			std::cout << std::endl;
		}
	13. 
		
		void f1(applicant *a);
		const char * f2 (const applicant * a1, const applicant * a2);
		typedef void (*pp1) (apllicant *);
		pp1 p1 = f1;
		typedef const char *(*pp2) (const apllicant*, const applicant*);
		pp2  p2 = f2;
		//const char *(*(p2[5])) (const applicnt *, const applicant* ) = p1;
		pp1 ap[5]; массив из пяти указателей
		pp2	lol(*pa)[10]; //указатель на масиив из десяти ууказателей того же типа
		
*/
