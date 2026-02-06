#include <stdio.h>
#include <string.h>
#define MAX 50

char dq[MAX];
int front = -1, rear = -1;

void insertRear(char c) {
    if (front == -1)
        front = rear = 0;
    else
        rear++;
    dq[rear] = c;
}

char deleteFront() {
    return dq[front++];
}

char deleteRear() {
    return dq[rear--];
}

int main() {
    char s[50];
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++)
        insertRear(s[i]);

    while (front < rear) {
        if (deleteFront() != deleteRear()) {
            printf("Not Palindrome");
            return 0;
        }
    }

    printf("Palindrome");
    return 0;
}
