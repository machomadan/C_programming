// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};
void print_list(struct Node *);

void delete_duplicate(struct Node* head){
    struct Node *current=head;
    struct Node * runner , *prev_runner;
    //printf("In Duplicate\n");
    print_list(current);
    if(current==NULL){
       printf("empty linked list");
       return;
    }
    //printf("current=%x",current);

    while(current!=NULL){
        prev_runner = current;
        runner = current->next;
        //printf("current->data=%d,runner->data=%d",current->data,runner->data);
        while(runner!=NULL){
            if(current->data==runner->data){
               // printf("current->data=%d,runner->data=%d",current->data,runner->data);
                prev_runner->next=runner->next;
                struct Node* temp = runner;
                runner = runner->next;
          free(temp);
         }
         else {
             prev_runner = runner;
             runner=runner->next;
             }
     }
     current=current->next;
    }
  }
  
void reverse(struct Node **head){
    struct Node * current=*head;
    struct Node * previous=NULL;
    struct Node * new_val=NULL;
    //printf("current->data=%d\n",current->data);
    
    while(current!=NULL){
        new_val=previous;
        previous=current;
        current=current->next;
        previous->next=new_val;
        //printf("current->data=%d previous->data=%d new->data=%d\n",current->data, previous->data,new_val->data);
    }
    *head=previous;
    //return *head;
}

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to print the linked list
void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver program to test the deletion function
int main() {
    struct Node* head = NULL;

    // Build the list: 5 -> 4 -> 3 -> 2 -> 1
    
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 4);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 5);
    //head = insert(head, 2);

    printf("Initial Linked List: ");
    print_list(head);
    delete_duplicate(head);
    printf("After deleting duplicate: ");
    print_list(head);
    reverse(&head);
    printf("After reversing the linked List:");
    print_list(head);
    return 0;
}