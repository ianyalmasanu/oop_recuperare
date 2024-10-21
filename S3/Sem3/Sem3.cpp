#include <iostream>

using namespace std;

int test_var = 10; //global value
int function_test_2(); //header / function definition
void ptr_ex_1();

int main()
{
	function_test_2();
	ptr_ex_1();

}

int function_test_2() {
	return 0;
}

void ptr_ex_1() {
	int test_var = 7;
	int x = 3;
	char y = 'c';
	double d = 2.5;
	int v1[111] = { 0 };

	int* ptr_test_var = &test_var;
	int* ptr_x = &x;
	char* ptr_y = &y;
	double* ptr_d = &d;
	x++;

	int a = 3 + x++;
	int b = 3 + ++x;
	ptr_x++;
	ptr_y++;
	ptr_d++;
	//int* ptr_v1 = &v1;
}