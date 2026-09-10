#include<stdio.h>

int main()
{
    int marks[100], n, i;
    int choice, pos, key;
    int found, low, high, mid, temp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Insert Marks\n");
        printf("2. Delete a Mark\n");
        printf("3. Display Marks\n");
        printf("4. Linear Search\n");
        printf("5. Sort Marks\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter %d student marks:\n", n);

                for(i = 0; i < n; i++)
                {
                    printf("Marks of Student %d: ", i + 1);
                    scanf("%d", &marks[i]);
                }

                printf("Marks inserted successfully.\n");
                break;

            case 2:
                if(n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                printf("Enter position to delete (1-%d): ", n);
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    for(i = pos - 1; i < n - 1; i++)
                    {
                        marks[i] = marks[i + 1];
                    }

                    n--;

                    printf("Mark deleted successfully.\n");
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("No marks available.\n");
                }
                else
                {
                    printf("\nStudent Marks:\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("%d ", marks[i]);
                    }

                    printf("\n");
                }
                break;

            case 4:
                if(n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                printf("Enter mark to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(marks[i] == key)
                    {
                        printf("Mark found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Mark not found.\n");

                break;

            case 5:
                if(n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                for(i = 0; i < n - 1; i++)
                {
                    int j;

                    for(j = 0; j < n - i - 1; j++)
                    {
                        if(marks[j] > marks[j + 1])
                        {
                            temp = marks[j];
                            marks[j] = marks[j + 1];
                            marks[j + 1] = temp;
                        }
                    }
                }

                printf("Marks sorted successfully.\n");
                printf("Sorted Marks: ");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", marks[i]);
                }

                printf("\n");
                break;

            case 6:
                if(n == 0)
                {
                    printf("Array is empty.\n");
                    break;
                }

                printf("Enter mark to search: ");
                scanf("%d", &key);

                low = 0;
                high = n - 1;
                found = 0;

                while(low <= high)
                {
                    mid = (low + high) / 2;

                    if(marks[mid] == key)
                    {
                        printf("Mark found at position %d (Sorted Array)\n", mid + 1);
                        found = 1;
                        break;
                    }
                    else if(key < marks[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }

                if(found == 0)
                    printf("Mark not found.\n");

                break;

            case 7:
                printf("Program Terminated.\n");
                break;

            default:
                printf("Invalid Choice! Try Again.\n");
        }

    } while(choice != 7);

    return 0;
}