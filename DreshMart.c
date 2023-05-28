#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dress
{
    int dressID;
    char dressName[50];
    float price;
    struct Dress *next;
};

struct Dress *createDress(int dressID, char dressName[], float price)
{
    struct Dress *newDress = (struct Dress *)malloc(sizeof(struct Dress));
    newDress->dressID = dressID;
    strcpy(newDress->dressName, dressName);
    newDress->price = price;
    newDress->next = NULL;
    return newDress;
}

void insertDress(struct Dress **head, struct Dress *newDress)
{
    if (*head == NULL)
    {
        *head = newDress;
    }
    else
    {
        struct Dress *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newDress;
    }
}

void displayDresses(struct Dress *head)
{
    struct Dress *temp = head;
    while (temp != NULL)
    {
        printf("Dress ID: %d\n", temp->dressID);
        printf("Dress Name: %s\n", temp->dressName);
        printf("Price: %.2f\n\n", temp->price);
        temp = temp->next;
    }
}

struct Dress *searchDress(struct Dress *head, int dressID)
{
    struct Dress *temp = head;
    while (temp != NULL)
    {
        if (temp->dressID == dressID)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Dress not found
}

void deleteDress(struct Dress **head, int dressID)
{
    struct Dress *current = *head;
    struct Dress *previous = NULL;

    while (current != NULL)
    {
        if (current->dressID == dressID)
        {
            if (previous == NULL)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            printf("Dress with ID %d deleted.\n", dressID);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Dress with ID %d not found.\n", dressID);
}

int main()
{
    struct Dress *head = NULL;
    int choice;

    while (1)
    {
        printf("\nDress Shop's Dress Managing System\n");
        printf("1. Add a new dress\n");
        printf("2. Display all dresses\n");
        printf("3. Search for a dress\n");
        printf("4. Delete a dress\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int dressID;
            char dressName[50];
            float price;

            printf("\nEnter Dress ID: ");
            scanf("%d", &dressID);
            printf("Enter Dress Name: ");
            scanf(" %[^\n]s", dressName); // Read the string with spaces
            printf("Enter Dress Price: ");
            scanf("%f", &price);

            struct Dress *newDress = createDress(dressID, dressName, price);
            insertDress(&head, newDress);

            printf("\nDress added successfully.\n");
            break;
        }
        case 2:
        {
            if (head == NULL)
            {
                printf("\nNo dresses found.\n");
            }
            else
            {
                printf("\nDress List:\n");
                displayDresses(head);
            }
            break;
        }
        case 3:
        {
            int searchID;
            printf("\nEnter Dress ID to search: ");
            scanf("%d", &searchID);

            struct Dress *foundDress = searchDress(head, searchID);
            if (foundDress != NULL)
            {
                printf("\nDress found:\n");
                printf("Dress ID: %d\n", foundDress->dressID);
                printf("Dress Name: %s\n", foundDress->dressName);
                printf("Price: %.2f\n", foundDress->price);
            }
            else
            {
                printf("\nDress with ID %d not found.\n", searchID);
            }
            break;
        }
        case 4:
        {
            int deleteID;
            printf("\nEnter Dress ID to delete: ");
            scanf("%d", &deleteID);
            deleteDress(&head, deleteID);
            break;
        }
        case 5:
        {
            printf("\nExiting the program.\n");
            exit(0);
        }
        default:
        {
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
        }
        printf("\n");
    }

    return 0;
}