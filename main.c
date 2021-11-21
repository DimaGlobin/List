#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node ;

Node* Insert(int new_data, Node* elem){

    Node* new_elem = calloc(sizeof(Node), 1);
    assert(new_elem != 0);

    new_elem -> data = new_data;

    if(elem == NULL)
        return new_elem;

    new_elem -> next = elem -> next;
    elem -> next = new_elem;
    return new_elem;
}

int DelNode(Node* elem){
    int SaveData = (elem -> next) -> data;

    Node* NextAdress = elem -> next;
    elem -> next = (elem -> next) -> next;

    free(NextAdress);
    return SaveData;
}

void NodeDump(Node* elem){
    printf("Node [0x%p] {\n", elem);
    printf("Data: %d\n", elem -> data);
    printf("Next: 0x%p\n", elem -> next);
    printf("}\n\n");
}

void ListDump(Node* head){
    printf("List [0x%p] {\n", head);
    Node* elem = head;
    int i = 0;
    while (elem != NULL){
        printf("Number: %d is: ", i);
        NodeDump(elem);
        elem = elem -> next;
        i++;
    }
    printf("}\n\n");
}

int main() {
    Node* head = Insert(10, NULL);
    Node* elem1 = Insert(20, head);
    Node* elem2 = Insert(30, elem1);
    Node* elem3 = Insert(40, elem2);
    Node* elem4 = Insert(25, elem1);
    DelNode(elem4);
    ListDump(head);
    return 0;
}
