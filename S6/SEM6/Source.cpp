#include <iostream>

using namespace std;

enum BUDGET_TYPE {
	TAX = 1,
	BUDGET = 2
};

class Student {
private:	
	char* name;
	string address;
	int age;
	int id;

public:
	//constructor
	Student() {
		this->name = nullptr;
		this->address = "";
		this->age = -1;
		this->id = -1;
	}
	
	Student(char* name, string address, int id, int age) {
		this->id = id;
		this->age = age;
		this->address = address;
		//this->name = name; shallow copy, see deep copy below:
		this->name = new char[strlen(name) + 1]; //allocate memory
		strcpy_s(this->name, strlen(name) + 1, name); //deep copy
	}

	void setName(char* name) {
		this->name = new char[strlen(name) + 1]; //allocate memory
		strcpy_s(this->name, strlen(name) + 1, name); //deep copy
	}

	char* getName() {
		return this->name;
	}

	void setAddress(string address) {
		this->address = address;
	}

	string getAddress() {
		return this->address;
	}


	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return this->age;
	}


	void setId(int id) {
		this->id = id;
	}

	int getId() {
		return this->id;
	}

	//copy constructor
	//default copy constructor only provides shallow copy
	//for deep copy we need to define the copy constructor as per below:

	Student(const Student& copy) { //const is mandatory to prevent data modification inside the source class!
		this->id = copy.id;
		this->age = copy.age;
		this->address = copy.address;
		this->name = new char[strlen(copy.name) + 1]; //allocate memory
		strcpy_s(this->name, strlen(copy.name) + 1, copy.name); //deep copy
	}

};


int main() {
	Student s1;
	//s1.id = -1;
	Student s2((char*)"Iany Almasanu", "Bucharest", 192305, 33);
	Student s3 = s2; //the equal sign will always trigger by default a copy constructor!
	Student s4(s2);
}