#include <iostream>

using namespace std;

void func_1(int x);
char* func_2(char* name);
void func_3(int* y);

int main() {
	int z = 3;
	func_1(z);

	char* name = nullptr;
	name = new char[strlen("ionut") + 1];
	strcpy_s(name, strlen("ionut") + 1, "ionut");
	//delete name; //removing delete and trying to copy a string of chars that is longer than the space allocated prior to it
	//will result in an error.
	//name = new char[strlen("Iany") + 1]; //memory leak here if we don't use delete. always clear the memory before allocating new memory.
	name = func_2(name);

	delete name;

	int* y = new int[3];
	y[0] = 12;
	y[1] = 16;
	y[2] = 22;

	func_3(y);
}

void func_1(int x) {
	x = 7;
	x = 9;
	x++;
}

/*void func_1(int z) {
	z = 7;
	z = 9;
	z++;
}*/

char* func_2(char* name) {
	//name = (char*)5; //forcing type; this will not modify the address in main, not usable if we define it again in the function
					   //as this will generate a new address

	//name = new char[strlen("Iany") + 1]; //this doesn't work, same as before, using new inside the function will override the saved address;
	strcpy_s(name, strlen("Iany") + 1, "Iany"); //this works
	return name;
}

void func_3(int* y) {

}