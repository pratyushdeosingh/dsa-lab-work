#include <stdio.h>
#define MAX 10

int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    int x;
    if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
        return;
    }
    scanf("%d", &x);
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    q[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d\n", q[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", q[i]);
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
        if (ch == 1) enqueue();
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else break;
    }
    return 0;
}
