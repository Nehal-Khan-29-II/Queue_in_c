#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }
    else if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    
}

int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return 0;
    }
    value = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
    return 1;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\n");
    }
    else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n\n-------------------------------\n\n");
    }
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
