/*
NAME: MIRZA IMRAN BIN BAHARIN
STUDENT ID: 22005917
LAB: 4*/

#include <iostream>
using namespace std;

class Node {
public:
    string Data;
    Node* Next;

    Node(string value) {
        Data = value;
        Next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* Tail;

public:
    CircularLinkedList() {
        Tail = nullptr;
    }

    void addNode(string value) {
        Node* newNode = new Node(value);
        if (Tail == nullptr) {
            Tail = newNode;
            Tail->Next = Tail;
        }
        else {
            newNode->Next = Tail->Next;
            Tail->Next = newNode;
            Tail = newNode;
        }
    }

    void display() {
        if (Tail == nullptr) {
            cout << "The list is currently empty." << endl;
            return;
        }

        Node* temp = Tail->Next;
        cout << "Current List: ";
        do {
            cout << temp->Data << " -> ";
            temp = temp->Next;
        } while (temp != Tail->Next);
        cout << "(Back to the start)" << endl;
    }

    void deleteByValue(string value) {
        if (Tail == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = Tail->Next;
        Node* previous = Tail;

        do {
            if (current->Data == value) {
                if (current == Tail && current == Tail->Next) { // Only one node
                    delete current;
                    Tail = nullptr;
                }
                else {
                    previous->Next = current->Next;
                    if (current == Tail) {
                        Tail = previous;
                    }
                    delete current;
                }
                cout << "Successfully deleted." << endl;
                return;
            }
            previous = current;
            current = current->Next;
        } while (current != Tail->Next);

        cout << "Value not found in the list." << endl;
    }
};

int main() {
    CircularLinkedList myList;
    int userChoice;
    string inputValue;

    do {
        cout << "Menu for Circular Singly Linked List" << endl;
        cout << "1. Add a node" << endl;
        cout << "2. Show the list" << endl;
        cout << "3. Remove a node by value" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Please enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1:
            cout << "Enter the value to add: ";
            cin >> inputValue;
            myList.addNode(inputValue);
            break;
        case 2:
            myList.display();
            break;
        case 3:
            cout << "Enter the value to remove: ";
            cin >> inputValue;
            myList.deleteByValue(inputValue);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid selection, please try again." << endl;
        }

    } while (userChoice != 4);

    return 0;
}
