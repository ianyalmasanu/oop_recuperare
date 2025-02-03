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

    void setName(char* name) {
        if (this->name != nullptr) delete[] this->name;
        if (strlen(name) > ElectionCandidate::noCharReq) {
            this->name = new char[strlen(name) + 1];
            strcpy_s(this->name, strlen(name) + 1, name);
        }
        else throw("Error: Name does not contain the minimum lenght.");
    }
    char* getName() {
        return this->name;
    }

    ElectionCandidate(char* name, Party party, int votes, const string region): region(region) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
        this->party = party;
        this->votes = votes;
        ElectionCandidate::totalCandidates++;
    }

    ~ElectionCandidate(){
        delete[] this->name;
        this->name = nullptr;
        ElectionCandidate::totalCandidates--;
    }

    ElectionCandidate(const ElectionCandidate& copy): region(copy.region) {
        if (copy.name) {
            this->name = new char[strlen(copy.name) + 1];
            strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
        }
        else this->name = nullptr;
        this->party = copy.party;
        this->votes = copy.votes;
        ElectionCandidate::totalCandidates++;

    }

    static int getTotalCandidates() {
        return ElectionCandidate::totalCandidates;
    }

};

int ElectionCandidate::totalCandidates = 0;
const int ElectionCandidate::noCharReq = 3;


int main()
{
    ElectionCandidate obj1((char*)"Test", Independent, 5, "UE");
    obj1.setName((char*)"John");
    cout << "starting program" << endl;
    cout << "Initial object name: " << obj1.getName() << endl;
    cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;

    ElectionCandidate* obj2 = new ElectionCandidate((char*)"Maria", Democrat, 10, "UE");
    cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;
    cout << "Candidate name in heap: " << obj2->getName() << endl;
    delete obj2;
    cout << "Number of candidates after second object deletion: " << ElectionCandidate::getTotalCandidates() << endl;

    ElectionCandidate obj3 = obj1;

    cout << "Copied object name: " << obj3.getName() << endl;
    cout << "Number of candidates: " << ElectionCandidate::getTotalCandidates() << endl;

}

