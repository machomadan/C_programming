// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};
void print_list(struct Node *);
void merge_two_linked_lists(struct Node *first, struct Node *second){
    struct Node new_node;
    struct Node * another=&new_node;
    new_node.next=NULL;
    while(first && second){
        if(first->data<=second->data){
            another->next=first;
            first=first->next;
        }
        else{
            another->next=second;
            second=second->next;
        }
        another=another->next;
    }
    another->next=(first!=NULL)?first:second;
    printf("\nMerged Node:\n");
    print_list(new_node.next);
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
    struct Node *second=NULL;

    // Build the list: 5 -> 4 -> 3 -> 2 -> 1
    
    //head = insert(head, 1);
    head = insert(head, 9);
    head = insert(head, 7);
    head = insert(head, 5);
    head = insert(head, 3);
    head = insert(head, 1);
    
    second = insert(second, 10);
    second = insert(second, 8);
    second = insert(second, 6);
    second = insert(second, 4);
    second = insert(second, 2);

    printf("First Linked List: ");
    print_list(head);
    printf("\nSeocnd Linked List: ");
    print_list(second);
    //find_middle_node(head);
    merge_two_linked_lists(head,second);
    return 0;
}