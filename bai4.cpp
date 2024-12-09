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

printList(Node* head){
	int count=0; 
    Node* temp = head;
    while(temp != NULL){
    	count++; 
        temp = temp->next;
    }
    return count; 
}

int main(){
    Node* head = NULL;
    int n;
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

    int number = printList(head);
	printf("%d", number); 
    return 0;
}
