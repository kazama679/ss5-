#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while(temp != NULL) {
        printf("<->%d", temp->data);
        temp = temp->next;
    }
    printf("<->NULL");
}

void insertSublistAtPosition(Node** head, Node* sublistHead, int position) {
    if (*head == NULL || sublistHead == NULL) {
        printf("Danh sach chinh hoac danh sach con rong\n");
        return;
    }

    Node* temp = *head;
    int count = 0;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL || position == 0) {
        if (position == 0) {
            Node* sublistTail = sublistHead;
            while (sublistTail->next != NULL) {
                sublistTail = sublistTail->next;
            }
            sublistTail->next = *head;
            if (*head != NULL) {
                (*head)->prev = sublistTail;
            }
            *head = sublistHead;
        } else {
            Node* prevNode = temp->prev;
            Node* sublistTail = sublistHead;
            while (sublistTail->next != NULL) {
                sublistTail = sublistTail->next;
            }

            prevNode->next = sublistHead;
            sublistHead->prev = prevNode;
            sublistTail->next = temp;
            if (temp != NULL) {
                temp->prev = sublistTail;
            }
        }
    } else {
        printf("Vi tri chen khong hop le!\n");
    }
}

int main() {
    Node* head = NULL;
    int n, n2, position;
    printf("Moi ban nhap so luong danh sach chinh: ");
    scanf("%d", &n);
    printf("Moi ban nhap so luong danh sach con: ");
    scanf("%d", &n2);
    int value[n], value2[n2];
    Node* sublistHead = NULL;
    for(int i = 0; i < n; i++) {
        printf("Moi ban nhap vao gia tri cho danh sach chinh %d: ", i + 1);
        scanf("%d", &value[i]);
    }
    for(int i = 0; i < n2; i++) {
        printf("Moi ban nhap vao gia tri cho danh sach con %d: ", i + 1);
        scanf("%d", &value2[i]);
    }
    for(int i = n - 1; i >= 0; i--) {
        insertHead(&head, value[i]);
    }
    for(int i = n2 - 1; i >= 0; i--) {
        insertHead(&sublistHead, value2[i]);
    }

    printf("Danh sach chinh ban dau: ");
    printList(head);

    printf("\nMoi ban nhap vao vi tri chen danh sach con (0 den %d): ", n);
    scanf("%d", &position);

    insertSublistAtPosition(&head, sublistHead, position);

    printf("\nDanh sach chinh sau khi chen danh sach con: ");
    printList(head);

    return 0;
}
