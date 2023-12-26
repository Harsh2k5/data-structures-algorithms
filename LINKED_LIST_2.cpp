#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->next = NULL;
    }

    Node(int data) {
        this->next = NULL;
        this->data = data;
    }
};

int Findlength(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertNodeAtBeginning(Node*& head, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertNodeAtTail(Node* &head, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
       
    }
    else {
        Node* current = head;
        while(current->next!=NULL){
            current=current->next;
        }
        Node* newNode = new Node(data);
        current->next = newNode;
        current = newNode;
    }
}

void insertNodeAtPosition(Node* &head, int data, int position) {
    if (head == NULL || position <= 0) {
        insertNodeAtBeginning(head, data);
    }
    else if (position >= Findlength(head)) {
        insertNodeAtTail(head, data);
    }
    else {
        Node* newNode = new Node(data);
        Node* currentNode = head;
        Node* prevNode = NULL;
        while (position > 0) {
            position--;
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next = newNode;
        newNode->next = currentNode;
    }
}

void PrintLL(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertNodeAtBeginning(head, 30);
    insertNodeAtBeginning(head, 20);
    insertNodeAtBeginning(head, 10);
    insertNodeAtTail(head, 50);
    insertNodeAtBeginning(head, 00);

    cout << "Original Linked List:\n";
    PrintLL(head);

    insertNodeAtPosition(head, 25, 2);
    
    cout << "\nLinked List after inserting at position 2:\n";
    PrintLL(head);

    return 0;
}
