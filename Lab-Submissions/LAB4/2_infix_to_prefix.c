#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char infix[50], prefix[50], temp[50];
    int i, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    strrev(infix);

    for(i = 0; infix[i]; i++) {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    i = 0;
    while(infix[i]) {
        if(isalnum(infix[i]))
            temp[k++] = infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')') {
            while(stack[top] != '(')
                temp[k++] = pop();
            pop();
        } else {
            while(top != -1 && priority(stack[top]) > priority(infix[i]))
                temp[k++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while(top != -1)
        temp[k++] = pop();

    temp[k] = '\0';
    strrev(temp);
    strcpy(prefix, temp);

    printf("Prefix expression: %s", prefix);
    return 0;
}
