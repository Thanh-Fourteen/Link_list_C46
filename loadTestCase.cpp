#include <string.h>
#include "color.h"
#include "setup.h"

void loadTestCases(Node** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf(RED "Cannot open file.\n" RESET);
        return;
    }

    int choice, val, pos, key;
    char taskDescription[255]; 

    while (fscanf(file, "%d", &choice) != EOF) {

        switch (choice) {
            case 1:
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Add %d to the head" RESET, val);
                insertAtHead(head, val);
                break;
            case 2:
                fscanf(file, "%d", &val);
                sprintf(taskDescription, GREEN "Add %d to the tail" RESET, val);
                insertAtTail(head, val);
                break;
            case 3:
                fscanf(file, "%d %d", &pos, &val);
                sprintf(taskDescription, GREEN "Add %d at position %d" RESET, val, pos);
                insertAtPosition(head, val, pos);
                break;
            case 4:
                fscanf(file, "%d %d", &key, &val);
                sprintf(taskDescription, GREEN "Add %d after element %d" RESET, val, key);
                insertAfterKeys(head, val, key);
                break;
            case 5:
                fscanf(file, "%d %d", &key, &val);
                sprintf(taskDescription, GREEN "Add %d before element %d" RESET, val, key);
                insertBeforeKeys(head, val, key);
                break;
            case 6:
                strcpy(taskDescription, RED "Delete head element" RESET);
                deleteAtHead(head);
                break;
            case 7:
                strcpy(taskDescription, RED "Delete tail element" RESET);
                deleteAtTail(head);
                break;
            case 8:
                fscanf(file, "%d", &pos);
                sprintf(taskDescription, RED "Delete element at position %d" RESET, pos);
                deleteAtPosition(head, pos);
                break;
            case 9:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Delete all occurrences of %d" RESET, key);
                deleteAllKeys(head, key);
                break;
            case 10:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Delete element after %d" RESET, key);
                deleteAfterKeys(head, key);
                break;
            case 11:
                fscanf(file, "%d", &key);
                sprintf(taskDescription, RED "Delete element before %d" RESET, key);
                deleteBeforeKeys(head, key);
                break;
            case 0:
                printf(YELLOW "Test cases ended.\n" RESET);
                fclose(file);
                return;
            default:
                printf(RED "Invalid choice in file.\n" RESET);
                continue;
        }
        
        printf(CYAN "Task: %s\n" RESET, taskDescription);

        printList(*head);
        printf("\n");
    }

    fclose(file);
}
