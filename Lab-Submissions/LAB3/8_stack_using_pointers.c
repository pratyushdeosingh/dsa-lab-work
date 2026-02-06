#include <stdio.h>
#define SIZE 5
int main() {
    int stack[SIZE], top = -1, choice, x;
    while(1) {
        printf("\n1 PUSH\n2 POP\n3 PEEK\n4 EXIT\n");
        scanf("%d", &choice);
        if(choice == 1) {
            if(top == SIZE - 1)
                printf("Stack Overflow");
            else {
                printf("Enter value: ");
                scanf("%d", &x);
                *(stack + ++top) = x;
            }
        }
        else if(choice == 2) {
            if(top == -1)
                printf("Stack Underflow");
            else
                printf("Popped: %d", *(stack + top--));
        }
        else if(choice == 3) {
            if(top == -1)
                printf("Stack Empty");
            else
                printf("Top Element: %d", *(stack + top));
        }
        else
            break;
    }
    return 0;
}
