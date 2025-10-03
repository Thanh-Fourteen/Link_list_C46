#include "insert.cpp"
#include "delete.cpp"

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
















