#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Peek function
int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int main() {
    int arr[MAX], nge[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
        nge[i] = -1;

    top = -1; 

    for (i = 0; i < n; i++) {
        while (top != -1 && arr[i] > stack[top]) {
            int val = pop();
            for (int j = 0; j < n; j++) {
                if (arr[j] == val && nge[j] == -1) {
                    nge[j] = arr[i];
                    break;
                }
            }
        }
        push(arr[i]);
    }
    printf("Next Greater Elements:\n");
    for (i = 0; i < n; i++)
        printf("%d → %d\n", arr[i], nge[i]);

    return 0;
}