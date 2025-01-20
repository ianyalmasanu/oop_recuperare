#include <iostream>
using namespace std;

class Car
{
	const int id;
	char* make;
	string model;
	string serial_number;
	static int number_of_instances;
	bool ready;
public:
	Car() :id(0)
	{
		make = nullptr;
		model = "";
		serial_number = "";
		number_of_instances++;
		ready = false;
	}
	Car(const int id, const char* make, string model, string serial_number, bool ready) :id(id), model(model), serial_number(serial_number), ready(ready)
	{
		this->make = new char[strlen(make) + 1];
		strcpy_s(this->make, strlen(make) + 1, make);
		Car::number_of_instances++;
	}

	Car(const Car& copy) :Car(copy.id, copy.make, copy.model, copy.serial_number, copy.ready) {}

	static int how_many_instances()
	{
		return Car::number_of_instances;
	}

	Car& operator= (const Car& copy)
	{
		if (this == &copy)
			return *this;
		if (this->make != nullptr)
			delete this->make;
		this->make = new char[strlen(copy.make) + 1];
		strcpy_s(this->make, strlen(copy.make) + 1, copy.make);
		number_of_instances++;

		this->model = copy.model;
		this->serial_number = copy.serial_number;
		this->ready = copy.ready;

		return *this;
	}

	friend ostream& operator <<(ostream& os, const Car& car) //FRIEND has access to private members of a class
	{
		os << "Make: " << car.make << endl;
		os << "Model: " << car.model << endl;
		os << "Serial No: " << car.serial_number << endl;
		return os;
	}

	friend void operator >> (istream& is, Car& car) //FRIEND has access to private members of a class
	{

		char make[128], model[128], serial_number[128];

		int id;

		cout << "Make (max length is 128): ";
		is >> make;

		cout << "Model (max length is 128): ";
		is >> model;

		cout << "Serial number (max length is 128): ";
		is >> serial_number;

		cout << "Id: ";
		is >> id;
		Car* new_car = new Car(id, make, model, serial_number, true);
		car = *new_car;
	}

	bool operator!() //toggles the value from TRUE to FALSE and viceversa
	{
		this->serial_number = "";
		return true;
		//this->ready = !this->ready;
		//return this->ready;
	}

	//++ pre
	Car operator++()
	{
		//modify
		return *this;
	}

	//++ post
	Car operator++(int i)
	{
		Car copy = *this;
		//modify
		return copy;
	}

	//operator +
	Car operator+(int value)
	{
		Car copy = *this;
		//modify
		return copy;
	}

	//index operator
	int& operator[](int index)
	{
		//check index and return value
		throw exception("index invalid");
	}

	//explicit cast to int
	explicit operator int()
	{
		return id;
	}

	~Car()
	{
		delete this->make;
		number_of_instances--;
	}
};

int Car::number_of_instances = 0;

int main()
{
	cout << Car::how_many_instances() << endl;

	Car c1(1, "Ford", "Focus", "WIUD7683JHG8798JHKJH89798JH", true);

	!c1;

	Car c2 = c1;

	Car* c3 = new Car(c2);

	cout << Car::how_many_instances() << endl;

	delete c3;

	cout << Car::how_many_instances() << endl;

	cout << c1 << c2;

	Car c4;
	cin >> c4;

	cout << c4;

	c1 = c2 = *c3 = c4;
}
