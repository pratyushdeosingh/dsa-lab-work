#include <stdio.h>
#define MAX 10

int main() {
    int front, rear;
    scanf("%d %d", &front, &rear);

    if (front == -1)
        printf("Count = 0");
    else if (rear >= front)
        printf("Count = %d", rear - front + 1);
    else
        printf("Count = %d", MAX - front + rear + 1);

    return 0;
}
