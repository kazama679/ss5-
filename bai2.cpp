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

void insertPosition(Node** head, int data, int position){
    Node* newNode = createNode(data);
    
    if(*head == NULL){
        *head = newNode;
        return; 
    } 
    Node* temp = *head;
    
    if (position == 0) {
        insertHead(head, data);
        return;
    }

    for(int i = 0; i < position - 2; i++) {
        if (temp == NULL) { 
            printf("Vi tri khong hop le.\n");
            return;
        }
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp->next;
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

    printf("Danh sach truoc khi chen: ");
    printList(head);
    
    printf("\ngia tri chen: ");
	scanf("%d", &data);
	
    printf("vi tri chen: ");
	scanf("%d", &p);
	insertPosition(&head, data, p);
    printf("Danh sach sau khi chen: ");
    printList(head);
    return 0;
}
