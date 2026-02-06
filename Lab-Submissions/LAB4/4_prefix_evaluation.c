#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[50];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char prefix[50];
    int i, a, b;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    for(i = strlen(prefix) - 1; i >= 0; i--) {
        if(isdigit(prefix[i]))
            push(prefix[i] - '0');
        else {
            a = pop();
            b = pop();
            if(prefix[i] == '+') push(a + b);
            if(prefix[i] == '-') push(a - b);
            if(prefix[i] == '*') push(a * b);
            if(prefix[i] == '/') push(a / b);
        }
    }

    printf("Result = %d", pop());
    return 0;
}

