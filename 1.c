#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push 
void push(char *ch) {
    if (top == MAX - 1) {
        printf("Stack is  Overflow\n");
    } else {
        top = top + 1;
        stack[top] = *ch;   
    }
}

// Pop 
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX], reversed[MAX];
    char *ptr;
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    ptr = str;  

    while (*ptr != '\0') {
        push(ptr);   
        ptr++;    
    }

    // Pop to reverse string
    i = 0;
    while (top != -1) {
        reversed[i] = pop();
        i++;
    }

    reversed[i] = '\0';

    printf("Reverse string: %s\n", reversed);

    return 0;
}