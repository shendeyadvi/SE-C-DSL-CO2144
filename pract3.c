#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct Contact *newNode;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    printf("Enter name: ");
    scanf("%s", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    newNode->next = head;
    head = newNode;

    printf("Contact added successfully!\n");
}

// Insert at end
void insertEnd()
{
    struct Contact *newNode, *temp;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    printf("Enter name: ");
    scanf("%s", newNode->name);

    printf("Enter phone number: ");
    scanf("%s", newNode->phone);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Contact added successfully!\n");
}

// Delete contact by name
void deleteContact()
{
    char name[50];
    struct Contact *temp, *prev;

    printf("Enter name to delete: ");
    scanf("%s", name);

    temp = head;
    prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {

            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found!\n");
}

// Search contact by name
void searchContact()
{
    char name[50];
    struct Contact *temp;

    printf("Enter name to search: ");
    scanf("%s", name);

    temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Contact Found!\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found!\n");
}

// Display all contacts
void displayContacts()
{
    struct Contact *temp;

    if (head == NULL)
    {
        printf("Contact list is empty!\n");
        return;
    }

    temp = head;

    printf("\n--- Contact List ---\n");

    while (temp != NULL)
    {
        printf("Name  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);
        printf("-------------------\n");

        temp = temp->next;
    }
}

// Free all allocated memory
void freeMemory()
{
    struct Contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            deleteContact();
            break;

        case 4:
            searchContact();
            break;

        case 5:
            displayContacts();
            break;

        case 6:
            freeMemory();
            printf("Memory released. Program ended.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
