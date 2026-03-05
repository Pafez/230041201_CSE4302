#include<iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class patient{
    private:
    int id;
    string name;
    int age;
    char gender;
    string bloodGroup;
    string contact;
    public:
    patient(){
        id=0;
        name="";
        age=0;
        gender=' ';
        bloodGroup="";
        contact="";
    }
    ~patient(){
        cout<<"Destructor called for patient with id: "<<id<<endl;
    }
    string serialize() const{
        return to_string(id) + "|" + name + "|" + to_string(age) + "|" + string(1, gender) + "|" + bloodGroup + "|" + contact;
    }
    static bool deserialize(const string &line, patient &out){
        size_t pos = 0;
        size_t prev_pos = 0;
        int field_count = 0;
        while ((pos = line.find('|', prev_pos)) != string::npos) {
            string field = line.substr(prev_pos, pos - prev_pos);
            switch (field_count) {
                case 0: out.id = stoi(field); 
                        break;
                case 1: out.name = field; 
                        break;
                case 2: out.age = stoi(field); 
                        break;
                case 3: out.gender = field[0]; 
                        break;
                case 4: out.bloodGroup = field; 
                        break;
                case 5: out.contact = field; 
                        break;
            }
            prev_pos = pos + 1;
            field_count++;
        }
        if (field_count == 6) {
            return true;
        }
        return false;
    }
    void printRow(ostream &os) const
    {
        os  << left
            << setw(8)  << id
            << setw(20) << name
            << setw(6)  << age
            << setw(8)  << gender
            << setw(12) << bloodGroup
            << setw(15) << contact
            << endl;
    }
    void static printHeader(ostream &os)
    {
        os << left
        << setw(8)  << "ID"
        << setw(20) << "Name"
        << setw(6)  << "Age"
        << setw(8)  << "Gender"
        << setw(12) << "BloodGroup"
        << setw(15) << "Contact"
        << endl;

        os << string(69, '-') << endl;
    }   
    bool appendPatientToFile(const string &fileName, const patient &p)
    {
    ofstream outFile(fileName, ios::app); 

    if (!outFile)  
        return false;

    p.printRow(outFile); 

    outFile.close();
    return true; 
    }
    int loadAllPatients(const string &fileName, patient arr[], int maxCount)
    {
        ifstream inFile(fileName);
        if (!inFile) {
            return 0;
        }
        int count = 0;
        string line;
        while (getline(inFile, line) && count < maxCount) {
            patient p;
            if (patient::deserialize(line, p)) {
                arr[count++] = p;
            }
        }
        inFile.close();
        return count;
    }

};

int main (){
    patient p1;
    p1.appendPatientToFile("patients.txt", p1);
    patient p2;
    p2.appendPatientToFile("patients.txt", p2);
    
    const int MAX_PATIENTS = 100;
    patient patients[MAX_PATIENTS];
    int count = p1.loadAllPatients("patients.txt", patients, MAX_PATIENTS);

    if (count > 0) {
        patient::printHeader(cout);
        for (int i = 0; i < count; i++) {
            patients[i].printRow(cout);
        }
    } else {
        cout << "No patients found in the file." << endl;
    }

    return 0;
}