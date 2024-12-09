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

void searchNumber(Node* head, int a, int b){
    Node* temp = head;
    int check=0; 
    while(temp != NULL){
    	if(temp->data == a){
    		temp->data = b;
    		check++;
		}
        temp = temp->next;
    }
    if(check==0){
    	printf("Khong tim thay phan tu thay the");
	} 
}

int main(){
    Node* head = NULL;
    int n, a, b;
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

    printf("Danh sach: ");
    printList(head);
    
    printf("\nMoi ban nhap vao gia tri thay the: ");
    scanf("%d", &a);
    printf("Moi ban nhap vao gia tri moi: ");
    scanf("%d", &b);
	searchNumber(head, a, b);
	
    printf("Danh sach sau khi thay doi: ");
    printList(head);
    return 0;
}
