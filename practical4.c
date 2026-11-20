#include <stdio.h>
#include <string.h>

#define MAX 50
#define SIZE 100

int main() {
    char backStack[MAX][SIZE];
    char forwardStack[MAX][SIZE];

    int backTop = -1;
    int forwardTop = -1;

    char currentPage[SIZE] = "Home";
    char newPage[SIZE];

    int choice;

    do 
    {

        printf("====== BROWSER NAVIGATION ======\n");
        printf("1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {

            //Visit new page
            case 1:
                printf("Enter page name: \n");
                scanf("%s", newPage);

                backTop++;

                strcpy(backStack[backTop], currentPage);
                strcpy(currentPage, newPage);

                forwardTop = -1;

                printf("Current page: %s\n", currentPage);
                break;

            //Back navigation
            case 2:
                if(backTop == -1){
                    printf("No previous page available\n");
                }

                else{
                    forwardTop++;

                    strcpy(forwardStack[forwardTop], currentPage);

                    strcpy(currentPage, backStack[backTop]);

                    backTop--;

                    printf("Current page: %s\n", currentPage);
                }
                break;

            //Forward navigation
            case 3:
                if(forwardTop == -1){
                    printf("No forward page available\n");
                }

                else{
                    backTop++;

                    strcpy(backStack[backTop], currentPage);

                    strcpy(currentPage, forwardStack[forwardTop]);

                    forwardTop--;

                    printf("Current page: %s\n", currentPage);
                }
                break;

            //Display current page
            case 4:
                printf("Current page: %s\n", currentPage);
                break;

            //Exit
            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!!");
                break;
        }
    } while(choice != 5);

    return 0;
}