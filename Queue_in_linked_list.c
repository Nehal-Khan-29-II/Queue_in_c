#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return (front == NULL);
}

void enqueue(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (isEmpty()) {
        front = temp;
        rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue() {
    int value;
    Node* temp;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return 0;
    }

    temp = front;
    value = temp->data;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }

    return value;
}

void display() {
    Node* temp = front;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n-------------------------------\n\n");
}

int main() {
    int val;
    while (1>0){
    printf("1. Enqueue \n");
    printf("2. Dequeue \n");
    printf("3. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &val);

    if (val == 1) {
        int input;
        int inputval;
        int no;
        printf("Enter number of elements to add in queue: ");
        scanf("%d", &input);
        printf("Enter elements: \n");
        for (no = 0; no < input; no++) {
            scanf("%d", &inputval);
            enqueue(inputval);
        }
        display();
    }
    else if (val == 2) {
        dequeue();
        display();
    }
    else if (val == 3) {
        return 0;
    }
    else {
        printf("Invalid option.\n");
    }
  }
    return 0;
}
