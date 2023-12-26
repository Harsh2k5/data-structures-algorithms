#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    printf("Elements:");
    while(ptr!=NULL){
        
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}

struct Node* insertAtEnd(struct Node* head, int data ){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;

    while(p->next != NULL){
        p = p->next;

    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data ){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
    
}

struct Node* deleteFirst(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;

}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;

    for(int i= 0; i<index-1; i++){
        p = p->next;
        q= q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node* deleteAtEnd(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;

    while( q->next != NULL){
        p = p->next;
        q= q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}



int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;


    //Allocate memory for nodes in the linked list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 18;
    third->next = fourth;
    
    fourth->data = 33;
    fourth->next = NULL;

    linkedListTraversal(head);

    head = insertAtFirst(head, 30);
    printf("\nInsert 30 at beginning: \n");
    linkedListTraversal(head);
    
    head = insertAtIndex(head,33,2);
    printf("\nInsert 33 at index 2: \n");
    linkedListTraversal(head);
    printf("\n");
    
    head = insertAfterNode(head, second, 45);
    printf("Insert 45 after 11 :\n");
    linkedListTraversal(head);
     printf("\n\n");

    head = deleteFirst(head);
    linkedListTraversal(head);
    printf("\nRemoved first element from linked list\n");

    head = deleteAtIndex(head, 3);
    linkedListTraversal(head);
    printf("\nRemoved 3rd index element\n");

    head = deleteAtEnd(head);
    linkedListTraversal(head);
    printf("\nRemoved element from end\n");
}   