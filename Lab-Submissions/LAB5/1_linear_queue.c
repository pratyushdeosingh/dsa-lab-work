#include <stdio.h>
#define MAX 10

int q[MAX];
int front = -1, rear = -1;

void enqueue() {
    int x;
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    scanf("%d", &x);
    rear++;
    q[rear] = x;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
        return;
    }
    printf("Deleted %d\n", q[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
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
