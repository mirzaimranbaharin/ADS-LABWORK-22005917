#include <iostream>
using namespace std;


int main() {

    struct Student {
        int ID;
        string Name;
        int PhoneNumber;
        string Email;
    };
    Student student[5];

    for (int i = 0; i < 5; i++) {

        cout << "Student ID: ";
        cin >> student[i].ID;

        cin.ignore();

        cout << "Student name: ";
        cin >> student[i].Name;

        cout << "Student Phone Number: ";
        cin >> student[i].PhoneNumber;

        cin.ignore();

        cout << "Student Email: ";
        cin >> student[i].Email;

    }

    cout << "\n|STUDENT RECORD|\n";

    for (int j = 0; j < 5; j++) {
        cout << "Student ID: " << student[j].ID << "\n";
        cout << "Name: " << student[j].Name << "\n";
        cout << "Phone number: " << student[j].PhoneNumber << "\n";
        cout << "Student Email: " << student[j].Email << "\n";
    }

    return 0;

}