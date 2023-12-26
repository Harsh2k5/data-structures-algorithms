#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next=NULL;

     Node()
    {
        // cout << "I am nside default constructor:";
        this->next = NULL;
    }

    Node(int data)
    {
        // cout << " I am inside parameterized constructor";
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeginning(Node* &head, int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode; 
    }
    else{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}}

void printLL(Node* &head ){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << "->" ;
        temp = temp->next;
    }
}

void reverseList(Node* &head){

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

Node*middleNode(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL ){
        fast = fast->next;

        if(fast != NULL){
              fast = fast->next;
              slow = slow->next;
        }
    }
    cout<<slow->data;
    return slow;
    
    
}

int main(){
    Node* head = NULL;

    insertAtBeginning( head, 40);
    insertAtBeginning( head, 30);
    insertAtBeginning( head, 20);
    insertAtBeginning( head, 10);


    cout<<"LINKED LIST : ";
    printLL(head);
    cout<<endl;

    cout<<"REVERSE LINKED LIST : ";
    reverseList(head);
    printLL(head);
    cout<<endl;

    cout<<"MIDDLE NODE : ";
    middleNode(head);

}