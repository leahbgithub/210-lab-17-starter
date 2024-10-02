// 210 - Lab 17 - Leah Balakrishnan
#include <iostream>
using namespace std;

struct Node {
    float value;
    Node *next;
};

// Function prototypes
void output(Node *);
void addNodeToFront(Node *&, float);
void addNodeToTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteEntireList(Node *&);

int main() {
    Node *head = nullptr;
    const int SIZE = 7;
    
    // Create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        float tmp_val = rand() % 100;
        addNodeToFront(head, tmp_val);  // Adds nodes to the front
    }

    output(head);

    // delete node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    output(head);

    // node inserted
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // list will delete
    deleteEntireList(head);
    output(head);

    return 0;
}

// list is outputted
void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// node will be added to front of list
void addNodeToFront(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

// node will be added to tail of the list
void addNodeToTail(Node *&head, float val) {
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
}

// specific node must be deleted
void deleteNode(Node *&head, int position) {
    if (!head) return;

    Node *current = head, *prev = nullptr;

    if (position == 1) {
        head = current->next;  // Remove the head node
        delete current;
        return;
    }

    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) return;

    prev->next = current->next;
    delete current;
}

// node is inserted after the position
void insertNode(Node *&head, int position, float val) {
    Node *newNode = new Node;
    newNode->value = val;

    if (position == 0) {  // this inserts it at the head
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    for (int i = 1; current != nullptr && i < position; i++) {
        current = current->next;
    }

    if (current == nullptr) return;

    newNode->next = current->next;
    current->next = newNode;
}

// linked list is deleted
void deleteEntireList(Node *&head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
