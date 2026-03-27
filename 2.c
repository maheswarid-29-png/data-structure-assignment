#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char ch) {
    stack[++top] = ch;
}

// Pop
void pop() {
    if (top != -1)
        top--;
}

// Check Balanced
int main() {
    char exp[MAX];
    int i;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (top == -1) {  
                printf("Not Balanced Exp\n");
                return 0;
            } else {
                pop();
            }
        }
    }

    if (top == -1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");

    return 0;
}