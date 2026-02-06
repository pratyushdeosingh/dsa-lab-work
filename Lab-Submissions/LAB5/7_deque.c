#include <stdio.h>
#define MAX 10

int dq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX-1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront() {
    int x;
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    scanf("%d", &x);

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    dq[front] = x;
}

void insertRear() {
    int x;
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    scanf("%d", &x);

    if (rear == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    dq[rear] = x;
}

void deleteFront() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d\n", dq[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d\n", dq[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void peekFront() {
    if (isEmpty())
        printf("Empty\n");
    else
        printf("%d\n", dq[front]);
}

void peekRear() {
    if (isEmpty())
        printf("Empty\n");
    else
        printf("%d\n", dq[rear]);
}

void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) insertFront();
        else if (ch == 2) insertRear();
        else if (ch == 3) deleteFront();
        else if (ch == 4) deleteRear();
        else if (ch == 5) peekFront();
        else if (ch == 6) peekRear();
        else if (ch == 7) display();
        else break;
    }
    return 0;
}
