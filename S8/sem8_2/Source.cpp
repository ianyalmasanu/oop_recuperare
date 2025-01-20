#include <iostream>
using namespace std;
class Ticket {
	const int id=0;
	static int no_of_tickets; // this is the total number of tickets initialized outside the class, and used on all objects generated.
	char* event_title = nullptr;
	string date = "";
	string location = "";
	int price = 0;
	int* price_history = nullptr;
	int history_size = 0;

	//to-do
	//default constructor
public:
	Ticket(){
	}

	//constructor with params
	Ticket(const int id, char* event_title, string date, string location, int price): id(id)
	{
		no_of_tickets++; //this is a static variable that grows with each object creation, and it must be initialized OUTSIDE of the class
		this->event_title = new char[strlen(event_title) + 1];
		strcpy_s(this->event_title, strlen(event_title) + 1, event_title);
		this->date = date;
		this->location = location;
		this->price = price;
		this->history_size = 1;
		this->price_history = new int[history_size];
		this->price_history[0] = price;
	}


	//copy constructor
	Ticket(const Ticket& copy) : id(copy.id) {
		no_of_tickets++;
		this->event_title = new char[strlen(copy.event_title) + 1];
		strcpy_s(this->event_title, strlen(copy.event_title) + 1, copy.event_title);
		this->date = copy.date;
		this->location = copy.location;
		this->price = copy.price;
		this->history_size = copy.history_size;
		if (copy.price_history) {
			this->price_history = new int[copy.history_size];
			for (int i=0; i<history_size; i++)
				this->price_history[i] = copy.price_history[i];
		}
	}

	//operator =

	//setters

	void setEventTitle(char* event_title) {
		this->event_title = new char[strlen(event_title) + 1];
		strcpy_s(this->event_title, strlen(event_title) + 1, event_title);
	}

	void setDate(string date) {
		this->date = date;
	}

	void setLocation(string location) {
		this->location = location;
	}

	void setPrice(int price) {
		this->price = price;

		int* temp = new int[history_size + 1];
		for (int i = 0; i<history_size; i++) {
			temp[i] = price_history[i];
		}
		temp[history_size] = price;
		delete[] this->price_history;
		this->price_history = temp;
		history_size++;
	}

	//getters

	int getId() {
		return this->id;
	}

	char* getEventTitle(){
		return this->event_title;
	}

	string getDate() {
		return this->date;
	}

	string getLocation() {
		return this->location;
	}

	int getPrice() {
		return this->price;
	}

	void displayPriceHistory() const {
		if (history_size == 0) cout << "No valid price history"<<endl;
		else {
			cout << "Price history for ticket: ";
			for (int i = 0; i < history_size; i++) {
				if (i < history_size-1) cout << price_history[i] << ", ";
				else cout << price_history[i] << ".";
			}
			cout << endl;
		}
	}

	//operator ! which deletes the price history
	void operator!() {
		delete[] this->price_history;
		this->price_history = nullptr;
		this->history_size = 0;
		cout << "Price history for ticket deleted." << endl;
	}


	//destructor
	~Ticket() {
		delete this->event_title;
		delete[] this->price_history;
		no_of_tickets--;
	}
};

int Ticket::no_of_tickets = 0;


int main() {
	Ticket t1(3, (char*)"LA Noir", "2024-11-27", "Hall A", 35);
	Ticket t2 = t1;
	cout << t2.getId() << endl << t2.getEventTitle() << endl << t2.getDate() << endl << t2.getLocation() << endl << t2.getPrice() << endl;
	t2.setPrice(38);
	cout << "Price change, new price: " << t2.getPrice() << endl;
	t2.displayPriceHistory();
	t2.setPrice(40);
	cout << "Price change, new price: " << t2.getPrice() << endl;
	t2.displayPriceHistory();
	!t2;
	t2.setPrice(35);
	cout << "Price reverted, new price: " << t2.getPrice() << endl;
	t2.displayPriceHistory();
}