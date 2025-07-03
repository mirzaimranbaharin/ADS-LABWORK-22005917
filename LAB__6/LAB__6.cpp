/*
NAME: MIRZA IMRAN BIN BAHARIN
ID: 22005917
LAB:6
QUEUE
*/


#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name, Node* next_ptr = nullptr) {
        this->name = name;
        this->next_ptr = next_ptr;
    }
};

class Queue {
private:
    Node* front_ptr;
    Node* rear_ptr;

public:
    Queue() {
        front_ptr = nullptr;
        rear_ptr = nullptr;
    }

    void enqueue(string name) {
        Node* new_node = new Node(name);
        if (rear_ptr == nullptr) {
            front_ptr = new_node;
            rear_ptr = new_node;
        }
        else {
            rear_ptr->next_ptr = new_node;
            rear_ptr = new_node;
        }
        cout << "Enqueued: " << name << endl;
    }

    string dequeue() {
        if (front_ptr == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return "";
        }
        Node* temp = front_ptr;
        string dequeued_name = temp->name;
        front_ptr = front_ptr->next_ptr;

        if (front_ptr == nullptr) {
            rear_ptr = nullptr;
        }
        delete temp;
        return dequeued_name;
    }

    string peek() {
        if (front_ptr == nullptr) {
            cout << "Queue is empty. No element to peek." << endl;
            return "";
        }
        return front_ptr->name;
    }

    bool isEmpty() {
        return front_ptr == nullptr;
    }

    void display_queue() {
        if (front_ptr == nullptr) {
            cout << "Queue is empty."


#include <iostream>
#include <string>

                using namespace std;

            class Node {
            public:
                string name;
                Node* next_ptr;

                Node(string name, Node* next_ptr = nullptr) {
                    this->name = name;
                    this->next_ptr = next_ptr;
                }
            };

            class Queue {
            private:
                Node* front_ptr;
                Node* rear_ptr;

            public:
                Queue() {
                    front_ptr = nullptr;
                    rear_ptr = nullptr;
                }

                void enqueue(string name) {
                    Node* new_node = new Node(name);
                    if (rear_ptr == nullptr) {
                        front_ptr = new_node;
                        rear_ptr = new_node;
                    }
                    else {
                        rear_ptr->next_ptr = new_node;
                        rear_ptr = new_node;
                    }
                    cout << "Enqueued: " << name << endl;
                }

                string dequeue() {
                    if (front_ptr == nullptr) {
                        cout << "Queue is empty. Cannot dequeue." << endl;
                        return "";
                    }
                    Node* temp = front_ptr;
                    string dequeued_name = temp->name;
                    front_ptr = front_ptr->next_ptr;

                    if (front_ptr == nullptr) {
                        rear_ptr = nullptr;
                    }
                    delete temp;
                    return dequeued_name;
                }

                string peek() {
                    if (front_ptr == nullptr) {
                        cout << "Queue is empty. No element to peek." << endl;
                        return "";
                    }
                    return front_ptr->name;
                }

                bool isEmpty() {
                    return front_ptr == nullptr;
                }

                void display_queue() {
                    if (front_ptr == nullptr) {
                        cout << "Queue is empty."