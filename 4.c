#include <stdio.h>
#include <string.h>
#define MAX 100

char queue[MAX][50];
int front = -1, rear = -1;

// Add document to queue
void addDocument(char doc[]) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        strcpy(queue[rear], doc);
        printf("Document '%s' added.\n", doc);
    }
}

// Print document
void printDocument() {
    if (front == -1 || front > rear) {
        printf("No documents to print\n");
    } else {
        printf("Printing: %s\n", queue[front]);
        front++;
    }
}

// Display pending documents 
void displayDocuments() {
    if (front == -1 || front > rear) {
        printf("No pending documents.\n");
    } else {
        printf("Pending documents:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d. %s\n", i - front + 1, queue[i]);
        }
    }
}

int main() {
    int choice;
    char doc[50];

    do {
        printf("\nPrinter Queue Menu:\n1. Add Document\n2. Print Document\n3. Display Pending\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                printf("Enter document name: ");
                fgets(doc, sizeof(doc), stdin);
                doc[strcspn(doc, "\n")] = 0; 
                addDocument(doc);
                break;
            case 2:
                printDocument();
                break;
            case 3:
                displayDocuments();
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}