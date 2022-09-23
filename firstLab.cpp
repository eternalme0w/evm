#include <iostream>
#include <cmath>
#if (defined(linux) || defined(__MACH__))
#define CLS system("clear")
#else
#define CLS system("cls")
#endif 


void infPrint(unsigned char x) {

	CLS;

	printf("\nASCII code for '%c': %d \n\n", x, x);
	printf("'%c' in machine code: \n\n", x);

}

void menuPrint() {

	std::cout << "\n\n	menu\n";
	std::cout << "\n1)Change bites\n2)Enter another char\n3)exit\n\nEnter your choice: ";

	
}


void binPrint(unsigned char x) {	

	unsigned char bit;
	short int i;

	bit = 128;

	std::cout << " 7   6   5   4   3   2   1   0";
	std::cout << "\n ↓   ↓   ↓   ↓   ↓   ↓   ↓   ↓" << std::endl;

	for (i = 0; i < 8; i++) {

		std::cout << "[" << ((x & bit) ? 1 : 0) << "]"  << " ";
		bit = bit >> 1;
	}

	std::cout << std::endl << std::endl;
}


int main() {

	unsigned char x;
	unsigned char mask;
	char choice = -1;
	int bit;
	bool value;

	CLS;
	std::cout << "Enter a char: ";
	std::cin >> x;


	while (choice != '1' && choice != '2' && choice != '3') {

		infPrint(x);
		binPrint(x);
		menuPrint();

		std::cin >> choice;


		if (choice == '2') {

			CLS;
			choice = -1;
			std::cout << "Enter a char: ";
			std::cin >> x;
		}

		else if (choice == '3') {

			exit(0);
		}

		else {

			CLS;
			choice = -1;
			binPrint(x);
			
			std::cout << "Enter number of bit you want to change: ";
			std::cin >> bit;

			mask = pow(2, bit);

			std::cout << "Enter value: ";
			std::cin >> value;

			if (value == 1) {

				x = x | mask;

			} else {

				mask = ~mask;
				x = x & mask;
			}


		}
	}



	


	return 0;
}