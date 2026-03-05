#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

class Patient
{
private:
    int id;
    string name;
    int age;
    char gender;
    string bloodGroup;
    string contact;
public:
    Patient(
        int ID = 1,
        string Name = "N/A",
        int Age = 21,
        char Gender = 'N',
        string BloodGroup = "N/A",
        string Contact = "N/A"
    ) {
        id = ID;
        name = Name;
        age = Age;
        gender = Gender;
        bloodGroup = BloodGroup;
        contact = Contact;
    }
    ~Patient() {}

    string serialize() const {
        string line;
        line.append(to_string(id));
        line.push_back('|');
        line.append(name);
        line.push_back('|');
        line.append(to_string(age));
        line.push_back('|');
        line.push_back(gender);
        line.push_back('|');
        line.append(bloodGroup);
        line.push_back('|');
        line.append(contact);
        line.push_back('\n');

        return line;
    }

    static bool deserialize(const string & line, Patient & out) {
        string mLine = line;
        stringstream sLine(mLine);
        string temp;

        try
        {
            getline(sLine, temp, '|'); out.id = stoi(temp);
            getline(sLine, temp, '|'); out.name = temp;
            getline(sLine, temp, '|'); out.age = stoi(temp);
            getline(sLine, temp, '|'); out.gender = temp[0];
            getline(sLine, temp, '|'); out.bloodGroup = temp;
            getline(sLine, temp, '|'); out.contact = temp;
        }
        catch(const exception & e)
        {  
            return false;
        }
        return true;
    }

    void printRow(ostream & os) const {
        os << "| " << setw(3) << id << "| " << setw(21) << name;
        os << "| " << setw(4) << age << "| " << gender;
        os << " | " << setw(7) << bloodGroup << "| " << setw(14) << contact << "|";
    }

    static void printHeader(ostream & os) {
        os << "| " << setw(3) << "ID" << "| " << setw(21) << "Name";
        os << "| " << setw(4) << "Age" << "| " << "G";
        os << " | " << setw(7) << "Blood" << "| " << setw(14) << "Contact" << "|";
    }
};

bool appendPatientToFile(const string & fileName, const Patient &p) {
    ofstream out(fileName, ios::app);
    if (!out) return false;
    out << p.serialize();
    return static_cast<bool>(out);
}

int loadAllPatients(const string &fileName, Patient arr[], int maxCount) {
    ifstream in(fileName);
    if (!in) return 0;

    int count = 0;
    string sTemp;

    while (count < maxCount && getline(in, sTemp)) {
        if (sTemp.empty()) continue;

        Patient temp;
        if (Patient::deserialize(sTemp, temp)) {
            arr[count] = temp;
            count++;
        }
    }

    return count;
}

int main() {
    string fileName = "PATIENTS.txt";
    ofstream clearFile(fileName);

    Patient Farhan(207, "Farhan Kabir", 22, 'M', "O+", "013########");
    Patient Eusha(203, "IbruhHim Yuusha", 21, 'M', "GL", "017########");

    appendPatientToFile(fileName, Farhan);
    appendPatientToFile(fileName, Eusha);

    Patient pArr[2];
    int totalLoaded = loadAllPatients(fileName, pArr, 2);

    Patient::printHeader(cout); cout << endl;
    for (int i = 0; i < totalLoaded; i++) {
        pArr[i].printRow(cout);
        if (i + 1 < totalLoaded) cout << endl;
    }
}
