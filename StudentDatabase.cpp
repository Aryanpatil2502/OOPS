#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;

    // Static member to keep count of students
    static int studentCount;

public:
    // Default constructor
    Student() {
        name = "";
        rollNumber = 0;
        studentClass = "";
        division = 'A';
        dob = "";
        bloodGroup = "";
        contactAddress = "";
        telephoneNumber = "";
        drivingLicense = "";
        studentCount++;
    }

    // Parameterized constructor
    Student(string name, int roll, string cls, char div, string dob, string bloodGroup, string address, string tel, string license) {
        this->name = name;
        this->rollNumber = roll;
        this->studentClass = cls;
        this->division = div;
        this->dob = dob;
        this->bloodGroup = bloodGroup;
        this->contactAddress = address;
        this->telephoneNumber = tel;
        this->drivingLicense = license;
        studentCount++;
    }

    // Copy constructor
    Student(Student &obj) {
        name = obj.name;
        rollNumber = obj.rollNumber;
        studentClass = obj.studentClass;
        division = obj.division;
        dob = obj.dob;
        bloodGroup = obj.bloodGroup;
        contactAddress = obj.contactAddress;
        telephoneNumber = obj.telephoneNumber;
        drivingLicense = obj.drivingLicense;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Friend class declaration
    friend class StudentInfo;

    // Inline function to display student data
    inline void displayData() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    // Static function to display student count
    static void showStudentCount() {
        cout << "Total Students: " << studentCount << endl;
    }

    // Function to input student data
    void inputData() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // To consume the newline character left in the input buffer
        cout << "Enter Class: ";
        getline(cin, studentClass);
        cout << "Enter Division: ";
        cin >> division;
        cin.ignore(); // To consume the newline character
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        cout << "Enter Contact Address: ";
        getline(cin, contactAddress);
        cout << "Enter Telephone Number: ";
        getline(cin, telephoneNumber);
        cout << "Enter Driving License: ";
        getline(cin, drivingLicense);
    }
};

// Initializing static member
int Student::studentCount = 0;

// Friend class definition
class StudentInfo {
public:
    void displayStudentInfo(Student & s) {
        s.displayData();
    }
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // To consume the newline character

    Student *students = new Student[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].inputData();
    }

    // Display data for each student
    StudentInfo info;
    for (int i = 0; i < numStudents; i++) {
        cout << "\nDetails of Student " << i + 1 << ":\n";
        info.displayStudentInfo(students[i]);
    }

    // Display total student count
    Student::showStudentCount();

    // Clean up dynamically allocated memory
    delete[] students;
    
    cout << "\nStudents after deletion :";
    Student::showStudentCount();

    return 0;
}
