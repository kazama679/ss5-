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

void filter(Node** head){
    Node* temp = *head;
    while(temp != NULL){
    	// Luu lai node tiep theo truoc khi xoa
        Node* nextNode = temp->next;
        if(temp->data % 2 == 0){
            // neu xoa dau 
            if(temp->prev == NULL){
                *head = temp->next;
                if(*head != NULL) {
                    (*head)->prev = NULL;
                }
            }
            // neu xoa cuoi 
            else if(temp->next == NULL){
                temp->prev->next = NULL;
            }
            else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
        temp = nextNode;
    }
}

void sort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* temp1 = *head;
    Node* temp2 = NULL;
    int swapped;
    for (int i = 0; ; i++) {
        swapped = 0;
        temp1 = *head;
        for (Node* current = *head; current->next != temp2; current = current->next) {
            if (current->data > current->next->data) {
                int tempData = current->data;
                current->data = current->next->data;
                current->next->data = tempData;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        temp2 = temp1;
    }
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

    printf("Danh sach trc khi thay doi: ");
    printList(head);
    
    filter(&head); 
    sort(&head); 

    printf("\nDanh sach sau khi thay doi: ");
    printList(head);
    return 0;
}
