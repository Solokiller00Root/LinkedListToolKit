#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include <string.h>
#include <stdbool.h>

int main(void) {
    elem student;
    ListNodePtr list;
    char username[80];
    int grade;
    int choice;

    LL_INIT(&list);

    while (true) {
        printf("\n============== MENU ==============\n");
        printf("1. Add a Student\n");
        printf("2. Exit\n");
        printf("3. Perform Operations\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the student's username: ");
                scanf("%s", username);
                printf("Enter the student's grade: ");
                scanf("%d", &grade);

                strcpy(student.name, username);
                student.grade = grade;
                LL_INSERT_START(&list, student);
                printf("Student added successfully!\n");
                break;

            case 2:
                LL_DESTROY(&list);
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            case 3:
                printf("\nOriginal Linked List: ");
                LL_PRINT(list);
                printf("\n");

                LL_DUB(&list);

                ListNodePtr listCopy = NULL;
                LL_COPY(list, &listCopy);

                LL_MERGESORT(&list);

                LL_REVERCE(&list);

                printf("Sorted Linked List: ");
                LL_PRINT(list);
                printf("\n");

                printf("Reversed List: ");
                LL_PRINT(listCopy);
                printf("\n");

                LL_AVERAGE(listCopy);

                LL_DESTROY(&listCopy);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}

