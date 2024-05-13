#include <iostream>
#include <unordered_set>

using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to remove duplicates from the list
    void removeDuplicates() {
        unordered_set<int> seen;
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (seen.find(curr->data) != seen.end()) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
    }

    // Function to display the elements of the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    int numLists;
    cin >> numLists;

    for (int i = 0; i < numLists; ++i) {
        LinkedList list;
        int size, val;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            cin >> val;
            list.insert(val);
        }
        list.removeDuplicates();
        list.display();
    }

    return 0;
}
