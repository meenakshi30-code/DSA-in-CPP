#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int id;
    string name;
    int age;
    int nos;
    int* gpa;

public:
    // Default Constructor
    Student()
    {
        cout << "Student default ctor called" << endl;
        id = 0;
        age = 0;
        nos = 0;
        name = "NA";
        gpa = nullptr;
    }

    // Parameterized Constructor
    Student(int id, int age, string name, int nos, int gpa)
    {
        cout << "Parameterized ctor called" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new int(gpa);
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& srcobj)
    {
        cout << "Student copy ctor called" << endl;
        id = srcobj.id;
        age = srcobj.age;
        name = srcobj.name;
        nos = srcobj.nos;
        gpa = (srcobj.gpa != nullptr) ? new int(*srcobj.gpa) : nullptr;
    }

    // Copy Assignment Operator (Rule of 3)
    Student& operator=(const Student& srcobj)
    {
        if (this == &srcobj)
            return *this;

        delete gpa;

        id = srcobj.id;
        age = srcobj.age;
        name = srcobj.name;
        nos = srcobj.nos;
        gpa = (srcobj.gpa != nullptr) ? new int(*srcobj.gpa) : nullptr;

        return *this;
    }

    // Destructor
    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete gpa;
    }

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    int getGpa() const { return (gpa != nullptr) ? *gpa : 0; }

    // Behaviors
    void study() const
    {
        cout << name << " is studying" << endl;
    }

    void sleep() const
    {
        cout << name << " is sleeping" << endl;
    }

    void bunk() const
    {
        cout << name << " is bunking" << endl;
    }
};

int main()
{
    // Stack objects
    Student A(1, 15, "Ranu", 6, 9);
    Student B(2, 13, "Rahul", 4, 8);

    A.study();
    B.sleep();

    // Copy constructor
    Student C = A;
    cout << C.getName() << " GPA: " << C.getGpa() << endl;

    // Dynamic allocation
    Student* ptr = new Student(3, 14, "Kirti", 7, 10);
    cout << ptr->getName() << " Age: " << ptr->getAge() << endl;
    ptr->study();

    delete ptr;

    return 0;
}
