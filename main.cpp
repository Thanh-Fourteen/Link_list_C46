#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL){
		printf("ERROR!!!");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertAtHead(Node **head, int data){
	Node *newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
}

void insertAtTail(Node **head, int data){
	Node *newNode = createNode(data);
	if (*head == NULL){
		*head = newNode;
		return;
	}
	
	Node *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void printList(Node *head){
	if (head == NULL){
		printf("List Empty!");
		return;
	}	
	
	Node *temp = head;
	while(temp != NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

void freeList(Node **head){
	Node *temp;
	while(*head != NULL){
		temp = *head;
		*head = temp->next;
		free(temp);
	}
}

void deleteAtHead(Node **head){
	if (*head == NULL){
		printf("Linked list empty!\n");
		return;
	}
	
	Node *temp = *head;
	*head = temp->next;
	free(temp);
}

void deleteAtTail(Node **head){
	if (*head == NULL){
		printf("Linked list empty!\n");
		return;
	}
	
	Node *temp = *head;
	if (temp->next == NULL){
		free(*head);
		*head = NULL;
		return;
	}
	
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	
	free(temp->next);
	temp->next = NULL;
}

void insertAtPosition(Node **head, int data, int position){
	if (position == 1){
		insertAtHead(&(*head), data);
		return;
	}
	
	Node *temp = *head;
	for(int i = 1; i < position - 1 && temp != NULL; ++i){
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Position out of range!!\n");
		return;
	}
	
	Node *newNode = createNode(data);
	newNode->next = temp->next;
	temp->next = newNode;
}

void deleteAtPosition(Node **head, int position){
	if (position == 1){
		deleteAtHead(&(*head));
		return;
	}
	
	Node *temp = *head;
	for (int i = 1; i < position - 1 && temp != NULL; ++i){
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("Position out of range!!\n");
		return;
	}
	
	Node *del = temp->next;
	temp->next = del->next;
	free(del);
}

void insertAfterKeys(Node **head, int value, int key){
	Node *temp = *head;
	while(temp != NULL){
		if (temp->data == key){
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			temp = temp->next;
		}
		temp = temp->next;
	}
}

void insertBeforeKeys(Node **head, int value, int key){
	Node *temp = *head;
	if (temp == NULL){
		return;
	}
	
	if (temp->data == key){
		insertAtHead(&(*head), value);
	}
	
	while (temp->next != NULL){
		if (temp->next->data == key){
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next = newNode;
			temp = temp->next;
		}
		temp = temp->next;
	}
}

void deleteAfterKeys(Node **head, int key){
	Node *temp = *head;
	if (temp == NULL) return;
	while(temp->next != NULL){
		if(temp->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			if (del->data != key){
				temp = temp->next;
			}
			free(del);
		} else {
			temp = temp->next;
		}
	}
}

void deleteBeforeKeys(Node **head, int key){
	if (*head == NULL || (*head)->next == NULL)
		return;
	
	// 2
	while((*head)->next != NULL && (*head)->next->data == key)
		deleteAtHead(&(*head));
	
	Node *temp = *head;
	while(temp->next != NULL && temp->next->next != NULL){
		if (temp->next->next->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			free(del);
		} else {
			temp = temp->next;
		}
	}
}

void deleteAllKeys(Node **head, int key){
	while (*head != NULL && (*head)->data == key){
		deleteAtHead(&(*head));
	}
	
	Node *temp = *head;
	while(temp!=NULL && temp->next != NULL){
		if (temp->next->data == key){
			Node *del = temp->next;
			temp->next = del->next;
			free(del);
		} else{
			temp = temp->next;
		}
	}
}

int main(){
	Node *head = NULL;
//	insertAtTail(&head, 1);
	insertAtTail(&head, 2);
//	insertAtTail(&head, 1);
	insertAtTail(&head, 2);
	insertAtTail(&head, 2);
//	insertAtTail(&head, 3);
	insertAtTail(&head, 2);
//	insertAtTail(&head, 5);
	printList(head);
	
	deleteAllKeys(&head, 2);
	printList(head);
	
	freeList(&head);
}
















