#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *next;
};

struct Node *stNode;

void createList(int);
void showLinkedList(int);
void reverseLinkedList(int);

int main() {
    int nodes;

    printf("Number of nodes: ");
    scanf("%d", &nodes);

    createList(nodes);
    showLinkedList(nodes);

    return 0;
}

void createList(int size) {
    struct Node *tmp, *nNode;

    stNode = (struct Node *) malloc(sizeof(struct Node));

    if(stNode == NULL) {
        printf("Error: no enough memory.\n");
    }
    else {
        printf("Number for the node 1: ");
        scanf("%d", &stNode->num);
        stNode->next = NULL;
        tmp = stNode;

        for(int i = 2; i <= size; i++) {
            nNode = (struct Node *) malloc(sizeof(struct Node));
            printf("Number for the node %d: ", i);
            scanf("%d", &nNode->num);
            nNode->next = NULL;
            tmp->next = nNode;
            tmp = tmp->next;
        }
    }
}
void showLinkedList(int size) {
    struct Node *tmp = stNode;

    for(int i = 0; i < size; i++) {
        printf("Node %d: %d\n", i + 1, tmp->num);
        tmp = tmp->next;
    }
}
void reverseLinkedList(int size) {
    struct Node *tmp, *aux;

    tmp = stNode;

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {

        }
    }
}
