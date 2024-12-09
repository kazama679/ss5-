#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertHead(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void printList(Node* head){
    Node* temp = head;
    printf("NULL");
    while(temp != NULL){
        printf("<->%d", temp->data);
        temp = temp->next;
    }
    printf("<->NULL");
}

void deleteEnd(Node** head){
    // neu rong 
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    // neu chi co 1 phan tu 
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL; 
        return;
    }

    // duyet den cuoi danh sach 
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
	}
    temp->prev->next = NULL;
    free(temp);
}


int main(){
    Node* head = NULL;
    int n, data, p;
    printf("Moi ban nhap vao n: ");
    scanf("%d", &n);

    int value[n];
    for(int i = 0; i < n; i++){
        printf("Moi ban nhap vao gia tri cho phan tu %d: ", i + 1);
        scanf("%d", &value[i]);
    }

    for(int i = n - 1; i >= 0; i--){
        insertHead(&head, value[i]);
    }

    printf("Danh sach truoc khi xoa: ");
    printList(head);
    
    deleteEnd(&head);
    
    printf("\nDanh sach sau khi xoa: ");
    printList(head);
    return 0;
}
