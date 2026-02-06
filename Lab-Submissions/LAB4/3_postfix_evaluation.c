#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[50];
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i]; i++) {
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');
        else {
            b = pop();
            a = pop();
            if(postfix[i] == '+') push(a + b);
            if(postfix[i] == '-') push(a - b);
            if(postfix[i] == '*') push(a * b);
            if(postfix[i] == '/') push(a / b);
        }
    }

    printf("Result = %d", pop());
    return 0;
}
