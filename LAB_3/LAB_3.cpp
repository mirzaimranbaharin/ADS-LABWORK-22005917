/*NAME: MIRZA IMRAN BIN BAHARIN
ID: 22005917
LAB: 3
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

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList(Node* head = nullptr) {
        this->head = head;
        this->tail = head;
        if (head) head->next_ptr = nullptr;
    }

    void add_element(Node* node) {
        if (!node) return;

        node->next_ptr = nullptr;

        if (!head) {
            head = node;
            tail = node;
        }
        else {
            tail->next_ptr = node;
            tail = node;
        }
    }

    void display_list() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }

        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(string val) {
        if (!head) return;

        if (head->name == val) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
            if (!head) tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next_ptr && current->next_ptr->name != val) {
            current = current->next_ptr;
        }

        if (current->next_ptr) {
            Node* temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;
            if (temp == tail) tail = current;
            delete temp;
        }
    }

    void delete_second_node() {
        if (!head || !head->next_ptr) {
            cout << "No second node to delete." << endl;
            return;
        }

        Node* second = head->next_ptr;
        head->next_ptr = second->next_ptr;

        if (second == tail) {
            tail = head;
        }

        delete second;
        cout << "\n" << endl;
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    LinkedList list;

    list.add_element(new Node("Imran"));
    list.add_element(new Node("Edrina"));
    list.add_element(new Node("Natasha"));

    cout << "Before deleting :" << endl;
    list.display_list();

    list.delete_second_node();

    cout << "After deleting :" << endl;
    list.display_list();

    return 0;
}