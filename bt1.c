#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Operation {
    char url[100];
    char timestamp[20];
} Operation;
typedef struct Node {
    Operation data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* backStack = NULL;
Node* forwardStack = NULL;
Node* historyList = NULL;

void visitPage(const char* url, const char* timestamp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data.url, url);
    strcpy(newNode->data.timestamp, timestamp);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (backStack == NULL) {
        backStack = newNode;
        historyList = newNode;
    } else {
        newNode->prev = backStack;
        backStack->next = newNode;
        backStack = newNode;
    }
    forwardStack = NULL;
}
void goBack() {
    if (backStack == NULL) {
        printf(" rong.\n");
        return;
    }
    Node* current = backStack;
    backStack = backStack->prev;
    if (backStack != NULL) {
        backStack->next = NULL;
    }
    current->next = forwardStack;
    forwardStack = current;
}

void goForward() {
    if (forwardStack == NULL) {
        printf("rong.\n");
        return;
    }
    Node* current = forwardStack;
    forwardStack = forwardStack->next;
    if (forwardStack != NULL) {
        forwardStack->prev = NULL;
    }
    current->prev = backStack;
    if (backStack != NULL) {
        backStack->next = current;
    }
    backStack = current;
}

void printCurrentPage() {
    if (backStack == NULL) {
        printf("khong co.\n");
    } else {
        printf("Current page: %s\n", backStack->data.url);
    }
}
void printHistory() {
    if (historyList == NULL) {
        printf("rong.\n");
        return;
    }
    Node* current = historyList;
    printf("Browsing history:\n");
    while (current != NULL) {
        printf("%s - %s\n", current->data.url, current->data.timestamp);
        current = current->next;
    }
}

void clearHistoryList() {
    Node* current = historyList;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    historyList = NULL;
}

void clearHistory() {
    while (historyList != NULL) {
        Node* temp = historyList;
        historyList = historyList->next;
        free(temp);
    }
    backStack = NULL;
    forwardStack = NULL;
}

int main () {
    int choice;
    char url[100];
    char timestamp[20];
    do {
        printf("1. VISIT url\n");
        printf("2. BACKWARD \n");
        printf("3. FORWARD \n");
        printf("4. CURRENT \n");
        printf("5. HISTORY \n");
        printf("6. CLEAR HISTORY\n");
        printf("7. thoat \n");
        printf(" Nhap lua chon \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("nhap url: ");
                scanf("%s", url);
                printf("nhap timestamp: ");
                scanf("%s", timestamp);
                visitPage(url, timestamp);
                break;
            }
            case 2: {
                goBack();
                break;
            }
            case 3: {
                goForward();
                break;
            }
            case 4: {
                printCurrentPage();

                break;
            }
            case 5: {
                printHistory();
              break;
            }
            case 6: {
                clearHistory();
                break;
            }
                case 7: {
                printf("da thoat chuong trinh");
                break;
            }
            default: {
                printf("Lua chon khong hop le");
                break;
            }
        }
    }while (choice != 8);

    return 0;
}