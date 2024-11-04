#include <iostream>
using namespace std;

//struct - a way to group several related variables into one place

struct Student
{
	int id = -1;
	char* name = nullptr;
	char* address = nullptr;
	char* phone = nullptr;
	char* email = nullptr;

public:

	void display_name()
	{
		cout << endl << "Type the name: " << name << endl;
	}

	void set_id(int id)
	{
		this->id = id;
	}

	int get_id()
	{
		return this->id;
	}
	void set_name(char* _name)
	{
		this->name = _name; ///NO!!! --- this is a shallow copy

		this->name = new char[strlen(_name) + 1];        /// YES!!! --- this is the deep copy
		strcpy_s(this->name, strlen(_name) + 1, _name);
		///there are two different options of copying a value: deep copy and shallow copy
	}

	void get_name()
	{
		//return this->name; ///NO!!!!
	}
};

int main()
{
	Student first_student;

	first_student.set_id(12);
	first_student.name = new char[32];
	strcpy_s(first_student.name, strlen("Popescu Ionut") + 1, "Popescu Ionut");

	first_student.address = new char[32];
	strcpy_s(first_student.address, strlen("Bucuresti") + 1, "Bucuresti");

	first_student.email = new char[32];
	strcpy_s(first_student.email, strlen("popescui@gmail.com") + 1, "popescui@gmail.com");

	first_student.phone = new char[32];
	strcpy_s(first_student.phone, strlen("+40 761 234 5678") + 1, "+40 761 234 5678");



	Student s2;
	char tmp[128];


	cout << "Type the name: ";
	cin.getline(tmp, 128);

	s2.name = new char[strlen(tmp) + 1];
	strcpy_s(s2.name, strlen(tmp) + 1, tmp);


	cout << "Type the address: ";
	cin.getline(tmp, 128);

	s2.address = new char[strlen(tmp) + 1];
	strcpy_s(s2.address, strlen(tmp) + 1, tmp);


	cout << "Type the email: ";
	cin.getline(tmp, 128);

	s2.email = new char[strlen(tmp) + 1];
	strcpy_s(s2.email, strlen(tmp) + 1, tmp);


	cout << "Type the phone: ";
	cin.getline(tmp, 128);

	s2.phone = new char[strlen(tmp) + 1];
	strcpy_s(s2.phone, strlen(tmp) + 1, tmp);

	return 0;
}