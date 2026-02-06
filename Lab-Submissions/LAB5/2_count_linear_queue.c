#include <stdio.h>

int main() {
    int front, rear;
    scanf("%d %d", &front, &rear);

    if (front == -1 || front > rear)
        printf("Count = 0");
    else
        printf("Count = %d", rear - front + 1);

    return 0;
}
    