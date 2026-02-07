// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// Define the Node structure
struct Node {
    char data;
    struct Node* next;
};
void print_list(struct Node *);
void palyndrome_check(struct Node *head){
     struct Node * temp=head;
     char check[256]={0};
     int i=0;
     while(temp!=NULL){
         check[i]=temp->data;
         i++;
         temp=temp->next;
     }
     check[i]='\0';
     i=0;
     int j=strlen(check)-1;
     //printf("j=%d",strlen(check));
     while(i<j){
         //printf("check[i]=%c check[j]=%c",check[i],check[j]);
         if(check[i]!=check[j]){
             //printf("check[i]=%c check[j]=%c",check[i],check[j]);
             printf("Not palyndrome");
             return;
         }
         i++;
         j--;
     }
     printf("It is Palyndrome");
     return;
}

struct Node* insert(struct Node* head, char data) {
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
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver program to test the deletion function
int main() {
    struct Node* head = NULL;
   // struct Node *second=NULL;

    // Build the list: 5 -> 4 -> 3 -> 2 -> 1
    
    //head = insert(head, 1);
    head = insert(head, 'm');
    head = insert(head, 'a');
    head = insert(head, 'd');
    head = insert(head, 'a');
    head = insert(head, 'm');
    //head = insert(head, 'h');
    

    printf("First Linked List: ");
    print_list(head);
    //find_middle_node(head);
    palyndrome_check(head);
    return 0;
}