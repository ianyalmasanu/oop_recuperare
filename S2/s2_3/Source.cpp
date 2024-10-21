#include <iostream>

using namespace std;
//function header declaration
int test_local_var(int some_imput_var);
//global variable declaration
int var_1 = 12;

//main function
int main(){
	int result_data = test_local_var(45);
}

int test_local_var(int some_imput_var) {
	int var_1 = 16;
	var_1 += 12;
	return var_1;
}
