#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum Party {
    Undefined,
    Independent,
    Democrat,
    Republican
};

class ElectionCandidate {
private:    
    Party party = Undefined;
    char* name = nullptr;
    int votes = 0;
    const string region = "";
    static int totalCandidates;
    const static int noCharReq;

public:

    ElectionCandidate() {
    }

    void setName(const char* name) {
        if (this->name != nullptr) delete[] this->name;
        if (strlen(name) >= ElectionCandidate::noCharReq) {
            this->name = new char[strlen(name) + 1];
            strcpy_s(this->name, strlen(name) + 1, name);
        }
        else throw("Error: Name does not contain the minimum lenght.");
    }
    char* getName() {
        return this->name;
    }

    ElectionCandidate(const char* name, Party party, int votes, const string region): region(region) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->party = party;
        this->votes = votes;
        ElectionCandidate::totalCandidates+=1;
        //cout << "Constructor called. No. of candidates: " << ElectionCandidate::totalCandidates << endl;
    }

    ~ElectionCandidate(){
        delete[] this->name;
        this->name = nullptr;
        ElectionCandidate::totalCandidates-=1;
        //cout << "Destructor called. No. of candidates: " << ElectionCandidate::totalCandidates << endl;
    }

    ElectionCandidate(const ElectionCandidate& copy): region(copy.region) {
        if (copy.name) {
            this->name = new char[strlen(copy.name) + 1];
            strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
        }
        else this->name = nullptr;
        this->party = copy.party;
        this->votes = copy.votes;
        ElectionCandidate::totalCandidates+=1;
        //cout << "Copy constructor called. No. of candidates: " << ElectionCandidate::totalCandidates << endl;

    }

    static int getTotalCandidates() {
        return ElectionCandidate::totalCandidates;
    }

    const ElectionCandidate& operator=(const ElectionCandidate& other) {
        if (this != &other) {  // Avoid self-assignment
            if (other.name) {  // Only copy if other.name is valid
                // Deallocate current name and allocate new memory
                delete[] this->name;
                this->name = new char[strlen(other.name) + 1];
                strcpy_s(this->name, strlen(other.name) + 1, other.name);
                this->party = other.party;
                this->votes = other.votes;
            }
            else {
                // Do nothing if other.name is invalid
                cout << "Error: Invalid name in the source object. No changes made." << endl;
            }
        }
        return *this;  // Return reference to the current object
    }

    friend ostream &operator << (ostream& output, ElectionCandidate &candidate);

    void operator==(const ElectionCandidate& check) {
        if (this->name != nullptr && check.name != nullptr) {
            string chkName = string(check.name);
            string name = string(this->name);
            if (chkName == name && this->party == check.party){
            //if (strcmp(this->name, check.name) == 0 &&
            //    this->party == check.party) {
                cout << "Members name and party match." << endl;
            }
            else   cout << "Members name and party do not match." << endl;
        }
        else cout << "Error: Invalid objects data in name field. "<< endl;
    }

    ElectionCandidate operator++() {
        this->votes += 1;
        return*this;
    }

    ElectionCandidate operator++(int) {
        ElectionCandidate temp = *this;
        this->votes += 1;
        return temp;
    }

    bool checkName(string teststring) {
        string name = string(this->name);
        if (teststring == this->name) return true;
        else return false;
    }


};

int ElectionCandidate::totalCandidates = 0;
const int ElectionCandidate::noCharReq = 3;

ostream& operator << (ostream& output, ElectionCandidate& candidate) {
    output << "Name of candidate: " << candidate.name << " Party: " << candidate.party << " No. of votes: " << candidate.votes << " Region: " << candidate.region << endl;
    return output;
}



int main()
{
    ElectionCandidate obj1("Test", Independent, 5, "UE");
    obj1.setName("John");
    cout << "starting program" << endl;
    cout << "Initial object name: " << obj1.getName() << endl;
    //cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;

    ElectionCandidate* obj2 = new ElectionCandidate("Maria", Democrat, 10, "UE");
    cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;
    cout << "Candidate name in heap: " << obj2->getName() << endl;
    delete obj2;
    cout << "Number of candidates after second object deletion: " << ElectionCandidate::getTotalCandidates() << endl;

    ElectionCandidate obj3 = obj1;

    cout << "Copied object name: " << obj3.getName() << endl;
    //cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;

    cout << "Attempting to copy name from obj 1 to obj4: " << endl;
    ElectionCandidate obj4 = obj1; //copy constructor
    cout << "Name of obj 1: " << obj1.getName() << endl;
    cout << "Name of obj 4: " << obj4.getName() << endl;

    obj4.setName("Ted");

    cout << "Names after change of obj4, and before calling the = operator: " << endl;
    cout << "Name of obj 1: " << obj1.getName() << endl;
    cout << "Name of obj 4: " << obj4.getName() << endl;

    obj4 = obj1; //= operator

    cout << "Names after change of obj4, and after calling the = operator: " << endl;
    cout << "Name of obj 1: " << obj1.getName() << endl;
    cout << "Name of obj 4: " << obj4.getName() << endl;

    ElectionCandidate obj5("Maria", Republican, 30, "AC");
    ElectionCandidate obj6("Domingo", Republican, 34, "AD");

    cout << "Name of obj 5: " << obj5.getName() << endl;
    cout << "Name of obj 6: " << obj6.getName() << endl;

    obj6 = obj1; //= operator chain (last value is the source for all previous values)
    obj5 = obj6;
    cout << "Number of generated objects: " << ElectionCandidate::getTotalCandidates() << endl;
    cout << "Name of obj 5: " << obj5.getName() << endl;
    cout << "Name of obj 6: " << obj6.getName() << endl;

    cout << obj6;
    cout << obj5;
    obj5 == obj6;

    ElectionCandidate noName;
    obj5 == noName;
    obj6 = noName;
    cout << obj6;
    obj6 == noName;


    //cout << ElectionCandidate::getTotalCandidates() << endl;
  
   
    cout << "New testing starts here" << endl;
    cout << obj1;
    ++obj1;
    cout << obj1;
    obj6 = obj1++;
    cout << obj6 << obj1;
    
    if(obj1.checkName("lol")) cout<<"Name match."<<endl;
    else cout<<"Name does not match."<<endl;

    //cin.get();
}

