#include "insert.cpp"
#include "delete.cpp"
#include "loadTestCase.cpp"
#include "color.h"

void menu() {
	printf("%s+----------------------- Menu -----------------------+%s\n", GREEN, RESET);
	printf("%s| %-50s |%s\n", RED, "0. Exit", RESET);
	printf("%s| %-50s |%s\n", CYAN, "1. Add to the beginning of the list", RESET);
	printf("%s| %-50s |%s\n", CYAN, "2. Add to the end of the list", RESET);
	printf("%s| %-50s |%s\n", CYAN, "3. Insert an element at a position", RESET);
	printf("%s| %-50s |%s\n", CYAN, "4. Add an element after a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "5. Add an element before a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "6. Remove the first element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "7. Remove the last element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "8. Remove an element at a position", RESET);
	printf("%s| %-50s |%s\n", CYAN, "9. Remove a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "10. Remove an element after a specific element", RESET);
	printf("%s| %-50s |%s\n", CYAN, "11. Remove an element before a specific element", RESET);
	printf("%s| %-50s |%s\n", YELLOW, "12. Print the linked list", RESET);
	printf("%s| %-50s |%s\n", YELLOW, "13. Load test cases from file", RESET);
	printf("%s+----------------------------------------------------+%s\n", GREEN, RESET);
}


int main() {
	menu();
	int choice;
	Node *head = NULL;
	do {
		system("cls"); // Clear the screen
		menu();
		printf("Your choice: ");
		scanf("%d", &choice);
		int value, position, key, key_value;
		char filename[100];

		switch (choice) {
			case 1:
				printf("Enter the value to add: ");
				scanf("%d", &value);
				insertAtHead(&head, value);
				break;

			case 2:
				printf("Enter the value to add:");
				scanf("%d", &value);
				insertAtTail(&head, value);
				break;

			case 3: // Insert at position
				printf("Enter the position: ");
				scanf("%d", &position);
				printf("Enter the value to add: ");
				scanf("%d", &value);
				insertAtPosition(&head, value, position);
				break;

			case 4: // Add after a specific element
				printf("Enter the value of the element to add after: ");
				scanf("%d", &key);
				printf("Enter the value to add: ");
				scanf("%d", &key_value);
				insertAfterKeys(&head, key_value, key);
				break;
			case 5: // Add before a specific element
				printf("Enter the value of the element to add before: ");
				scanf("%d", &key);
				printf("Enter the value to add: ");
				scanf("%d", &key_value);
				insertBeforeKeys(&head, key_value, key);
				break;

			case 6: // Delete the first element
				deleteAtHead(&head);
				printf("List after deleting the first element:\n");
				printList(head);
				system("pause");
				break;

			case 7: // Delete the last element
				deleteAtTail(&head);
				printf("List after deleting the last element:\n");
				printList(head);
				system("pause");
				break;

			case 8: // Delete at position
				printf("Enter the position to delete: ");
				scanf("%d", &position);
				deleteAtPosition(&head, position);
				break;

			case 9: // Delete all occurrences of a value
				printf("Enter the value to delete: ");
				scanf("%d", &value);
				deleteAllKeys(&head, value);
				break;

			case 10: // Delete after a specific element
				printf("Enter the value of the element to delete after: ");
				scanf("%d", &key);
				deleteAfterKeys(&head, key);
				break;
			case 11: // Delete before a specific element
				printf("Enter the value of the element to delete before: ");
				scanf("%d", &key);
				deleteBeforeKeys(&head, key);
				break;

			case 12:
				printf("Current linked list: ");
				printList(head);
				system("pause");
				break;

			case 13: // Load test cases from file
	            printf("Enter the test case filename: ");
	            scanf("%s", filename);
	            loadTestCases(&head, filename);
	            printf("Test cases loaded successfully.\n");
	            system("pause");
				break;

			default:
				break;
		}

	} while (choice != 0);

	freeList(&head);
	return 0;
}
















