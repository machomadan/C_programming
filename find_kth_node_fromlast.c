// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};
void print_list(struct Node *);
struct Node * find_kth_node(struct Node *head, int k){
    struct Node * slow=head;
    struct Node *fast=head;
    if(slow==NULL || k<=0){
        return head;
    }
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        for(int i=0;i<k;++i){
            fast=fast->next;
        }
    }
    return slow->next;
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
    struct Node *result=NULL;
    int a;

    // Build the list: 5 -> 4 -> 3 -> 2 -> 1
    
    //head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 5);
    head = insert(head, 2);

    printf("Initial Linked List: ");
    print_list(head);
    printf("Provide the kth value to be retrieved:");
    scanf("%d",&a);
    result=find_kth_node(head,a);
    printf("kth node value is %d",result->data);
    return 0;
}