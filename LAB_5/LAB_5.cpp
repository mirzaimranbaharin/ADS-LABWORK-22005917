/*
NAME: MIRZA IMRAN BIN BAHARIN
ID: 22005917
LAB: 5
*/
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void Push(string val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void Peek() {
        if (head == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Last Element of the stack: " << head->data << endl;
    }

    void Pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    bool IsEmpty() {
        return head == nullptr;
    }

    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }
};

int main() {
    Stack stack;
    int choice;
    string value;

    do {
        cout << "\nStack Menu" << endl;
        cout << "1. Push node" << endl;
        cout << "2. Peek Stack" << endl;
        cout << "3. Pop Stack" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            stack.Push(value);
            break;
        case 2:
            stack.Peek();
            break;
        case 3:
            if (!stack.IsEmpty()) {
                cout << "Deleting ";
                stack.Peek();
                stack.Pop();
                cout << "Deleted" << endl;
            }
            else {
                cout << "Stack is empty, nothing to delete." << endl;
            }
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
