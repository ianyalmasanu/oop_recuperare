#include <iostream>
#include <string>

using namespace std;

enum karma {
	POSITIVE,
	NEGATIVE
};

class Characters {
	char* name = nullptr;
	int hp = 100;
	string specialPower = "";
	karma km = POSITIVE;
	static int TOTAL_CHAR;
	static const int MINIMUM_CHAR_NAME;

public:

	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		if (strlen(name) >= Characters::MINIMUM_CHAR_NAME) {
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else {
			throw("ERROR: Invalid name lenght.");
		}
	}

	char* getName() {
		return this->name;
	}

	Characters(const char* name, int hp, string specialPower, karma km){
		this->setName(name);
		this->hp = hp;
		this->specialPower = specialPower;
		this->km = km;
		Characters::TOTAL_CHAR += 1;
	}

	~Characters() {
		delete[] this->name;
		this->name = nullptr;
		Characters::TOTAL_CHAR -= 1;
	}

	Characters& operator+=(int x) {
		this->hp += x;
		return *this;
	}

	void setHp(int hp) {
		this->hp = hp;
	}

	int getHp() {
		return this->hp;
	}

	bool operator>=(const Characters& other) {
		if (this->hp >= other.hp) return true;
		else return false;
	}

	friend string operator+(Characters& c, const string& str) {
		return c.name + str;
		cout << endl;
	}


	Characters& operator=(const Characters& copied) {
		if (this != &copied) {
			this->name = new char[strlen(copied.name) + 1];
			strcpy_s(this->name, strlen(copied.name) + 1, copied.name);
			this->hp = copied.hp;
			this->specialPower = copied.specialPower;
			this->km = copied.km;
		}
		else cout << "Could not self-assign values, ignoring operator=." << endl;
		return *this;
	}

	friend ostream& operator<<(ostream& output, Characters& character);

	//copy constructor:
	Characters(const Characters& copy) {
		if (copy.name) {
			delete[] this->name;
			this->name = nullptr;
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
			this->hp = copy.hp;
			this->specialPower = copy.specialPower;
			this->km = copy.km;
			Characters::TOTAL_CHAR += 1;
		}
	}

	bool operator==(const Characters& compare) {
		string thisName = (string)this->name;
		string compareName = (string)compare.name;
		if (thisName==compareName && this->hp == compare.hp && this->specialPower == compare.specialPower && this->km == compare.km)return true;
		else return false;
	}

	void swapKarma() {
		if (this->km == POSITIVE) this->km = NEGATIVE;
		else this->km = POSITIVE;
	}

	friend istream& operator>>(istream& input, Characters& inputCharacter);

};

int Characters::TOTAL_CHAR = 0;
const int Characters::MINIMUM_CHAR_NAME = 3;

ostream& operator<<(ostream& output, Characters& character){
	output << "Printing character details: " << endl;
	output << character.name << " " << character.hp << " " << character.specialPower << " ";
	output << (character.km == POSITIVE ? "POSITIVE" : "NEGATIVE") << endl;
	return output;
}

istream& operator>>(istream& input, Characters& inputCharacter) {
	const int MAX_NAME_LENGHT = 100;
	char tempName[MAX_NAME_LENGHT];
	cout << "Enter character name: ";
	input.getline(tempName, MAX_NAME_LENGHT);
	inputCharacter.setName(tempName);
	cout << "Enter special power: ";
	getline(input, inputCharacter.specialPower);
	return input;

}



int main() {
	Characters c1("Great Jeones", 100, "Stun", POSITIVE);
	Characters c2("Brave Nicholas", 120, "Charge", NEGATIVE);

	cout << "c1 HP before buff: " << c1.getHp() << endl;
	cout << "c2 HP (no buff): " << c2.getHp() << endl;

	c1 += 20;
	cout << "c1 HP after buff: " << c1.getHp() << endl;
	cout << "________________bool test______________________" << endl;
	if (c1 >= c2) cout << "Bigger or equal hp!" << endl;
	else cout << "Lower HP!" << endl;

	cout << "_____________invalid name test_________________" << endl;
	Characters c3("Etc", 45, "Magnetic Pull", NEGATIVE);

	Characters c4 = c1;
	cout << c1<<c2<<c3<<c4;

	c1 += 45;
	cout << "new test _________" << endl;
	cout << c1 <<c2 << c3;
	c1 = c2 = c3;
	cout << c1 <<c2 << c3;
	cout << "self assign test _________" << endl;
	c1 = c1;

	cout << "___new test___printing c2 and c3 values__________" << endl;
	cout << c2 << c3;

	if (c2 == c3) cout << "All variables are equal between the compared objects." << endl;
	else cout << "At least one of the variables is differen between the compared objects." << endl;

	cout << "____________test overload+________________________" << endl;

	cout << c1 + " kek" << endl;
	cout << c1 << endl;
	c1.swapKarma();
	cout << c1 << endl;

	//Characters* danglingP = new Characters("Test dangling", 130, "N/A", NEGATIVE);
	//delete danglingP;
	
	//cout << danglingP;

	Characters tempobj = c1;

	cin >> tempobj;
	cout << tempobj;

}
