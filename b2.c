#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[50];
    int age;
} Student;
typedef struct Node {
    Student data;
    struct Node* left;
    struct Node* right;
} Node;

Node* root = NULL;
Node* createNode(int id, const char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->data.age = age;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int id, const char* name, int age) {
    if (root == NULL) {
        return createNode(id, name, age);
    }
    if (id < root->data.id) {
        root->left = insertNode(root->left, id, name, age);
    } else if (id > root->data.id) {
        root->right = insertNode(root->right, id, name, age);
    }
    return root;
}
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("ID: %d, Name: %s, Age: %d\n", root->data.id, root->data.name, root->data.age);
        inorderTraversal(root->right);
    }
}

Node* searchNode(Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }
    if (id < root->data.id) {
        return searchNode(root->left, id);
    }
    return searchNode(root->right, id);
}

void addStudent(int id, const char* name, int age) {
    root = insertNode(root, id, name, age);
}
void displayStudents() {
    if (root == NULL) {
        printf("Khong co sinh vien trong danh sach.\n");
    } else {
        inorderTraversal(root);
    }
}
void searchStudent(int id) {
    Node* student = searchNode(root, id);
    if (student != NULL) {
        printf("ID: %d, Name: %s, Age: %d\n", student->data.id, student->data.name, student->data.age);
    } else {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
    }
}
Node* deleteNode(Node* root, int id) {
    if (root == NULL) {
        return NULL;
    }

}

void deleteStudent(int id) {

}
int main() {
    int choice;
    int id, age;
    char name[50];

    do {
        printf("1. Them sinh vien \n");
        printf("2. Hien thi danh sach sinh vien \n");
        printf("3. Tim kiem sinh vien \n");
        printf("4. Xoa sinh vien \n");
        printf("5. thoat \n");
        printf("nhap lua chon");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Nhap ID: ");
                scanf("%d", &id);
                printf("Nhap ten: ");
                scanf("%s", name);
                printf("Nhap tuoi: ");
                scanf("%d", &age);
                addStudent(id, name, age);
                printf("Da them sinh vien thanh cong.\n");
                break;
            }
                case 2: {
                // hien thi
                displayStudents();
                break;
            }
                case 3: {
                // tim kiem
                printf("Nhap ID can tim: ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            }
                case 4: {
                    // xoa theo id

                break;
            }
                case 5: {
                printf("da thoat chuong trinh");
                break;
            }
            default: {
                    printf("Lua chon khong hop le");
                break;
            }
        }
    }while (choice != 5);
    return 0;
}