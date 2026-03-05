#include <iostream>

using namespace std;
class Person
{
private:
    string name;
    int age;
    const int personID;
    static int countID;
public:
    Person():personID(++countID) {
        name = "John Doe";
        age = 0;
    }
    Person(string Name, int Age):personID(++countID) {
        name = Name;
        age = Age;
    }
    ~Person() {
        cout << "~Person()  is called" << endl;
    }

    string getName() const {
        return name;
    };
    int getAge() const {
        return age;
    };
    int getPersonID() const {
        return personID;
    };

    void setName(string Name) {
        name = Name;
    };
    void setAge(int Age) {
        age = Age;
    };

    void displayDetails() const {
        cout << name << ", Age: " << age << ", P_ID: " << personID;
    }

    bool operator==(const Person & other) {
        if (name == other.name && age == other.age) return true;
        else return false;
    }
}; 
int Person::countID = 0;

class Student : public Person
{
private:
    int sid;
public:
    Student() {
        sid = -1;
    }
    Student(string Name, int Age, int sID) {
        setName(Name);
        setAge(Age);
        sid = sID;
    }

    int getSID() const {
        return sid;
    }

    void setSID(int Sid) {
        sid = Sid;
    }

    friend ostream & operator<<(ostream & out, const Person & person) {
        person.displayDetails();
        return out;
    }

    ~Student() {}
};

class Faculty : public Person
{
private:
    string designation;
public:
    Faculty() {
        setName("Mr. X");
        setAge(22);
        designation = "Lecturer";
    }
    Faculty(string Name, int Age, string Designation) {
        setName(Name);
        setAge(Age);
        designation = Designation;
    }

    ~Faculty() {
        cout << "~Faculty() is called" << endl;
    }

    string getDesignation() const {
        return designation;
    }

    void setDesignation(string Designation) {
        designation = Designation;
    }
};

class Visitor : private Person
{
private:
    string visitingPurpose;
public:
    Visitor() {
        visitingPurpose = "N/A";
    }
    Visitor(string purpose) {
        visitingPurpose = purpose;
    }
    ~Visitor() {}

    string getVisitingPurpose() const {
        return visitingPurpose;
    }

    void setVisitingPurpose(string purpose) {
        visitingPurpose = purpose;
    }
};

void TestPerson()
{
    Person p1, p2("Faisal",30);

    if(p1.getName()=="John Doe" && p1.getAge() == 0 &&p1.getPersonID()==1) cout<< "Zero Arg Constructor - Passed"<<endl;
    else  cout<< "Zero Arg Constructor - Failed!!!!"<<endl;

    if(p2.getName()=="Faisal" && p2.getAge() == 30 &&p2.getPersonID()==2) cout<< "Argumented Constructor - Passed"<<endl;
    else  cout<< "Argumented Constructor - Failed!!!!"<<endl;

    if(p1==p1) cout<< " operator == - Passed"<<endl;
    else cout<< " operator == - Failed!!!!"<<endl;

}

void TestStudent(){
    Student s1;
}
void TestFaculty(){
    Faculty f;
    if(f.getName()=="Mr. X"&&f.getAge()==22&&f.getDesignation()=="Lecturer") cout<< "Zero Arg Constructor Faculty - Passed"<<endl;
    else cout<< "Zero Arg Constructor Faculty - Failed!!!!"<<endl;
}
void TestVisitor()
{
    Visitor v;
}

int main()
{
    TestPerson();
    TestStudent();
    TestFaculty();
    TestVisitor();
}

