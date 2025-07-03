/*
NAME: MIRZA IMRAN BIN BAHARIN
ID: 22005917
LAB: 6
CIRCULAR QUEUE*/

#include <iostream>
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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void Enqueue(string val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
            rear->next = front; // Circular link
        }
        else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular link
        }
        cout << "Enqueued: " << val << endl;
    }

    void Peek() {
        if (front == nullptr) {
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front);
        cout << "(back to front)" << endl;
    }

    void Dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) {
            cout << "Deleted: " << front->data << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        }
        else {
            Node* toDelete = front;
            cout << "Deleted: " << front->data << endl;
            front = front->next;
            rear->next = front; // Maintain circular link
            delete toDelete;
        }
    }

    ~Queue() {
        while (front != nullptr) {
            Dequeue();
        }
    }
};

int main() {
    Queue queue;
    int choice;
    string value;

    do {
        cout << "\nQueue Menu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Display" << endl;
        cout << "3. Dequeue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add: ";
            cin >> value;
            queue.Enqueue(value);
            break;
        case 2:
            queue.Peek();
            break;
        case 3:
            queue.Dequeue();
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
