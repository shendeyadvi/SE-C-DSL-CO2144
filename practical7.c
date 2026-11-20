#include <stdio.h>
#define MAX 10

int graph[MAX][MAX] = {0};
int visited[MAX];
int n;

// Add connection
void addConnection(int a, int b)
{
    graph[a][b] = 1;
    graph[b][a] = 1;
    printf("Connection added!\n");
}

// BFS
void BFS(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i, current;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear)
    {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS
void DFS(int start)
{
    int i;
    visited[start] = 1;
    printf("%d ", start);

    for (i = 0; i < n; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    int choice, a, b, start, i;

    printf("Enter number of users (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of users!\n");
        return 0;
    }

    do
    {
        printf("\n1. Add Connection");
        printf("\n2. BFS");
        printf("\n3. DFS");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter two users (0 to %d): ", n - 1);
            scanf("%d %d", &a, &b);

            if (a >= 0 && a < n && b >= 0 && b < n)
                addConnection(a, b);
            else
                printf("Invalid users!\n");
            break;

        case 2:
            printf("Enter starting user: ");
            scanf("%d", &start);

            if (start >= 0 && start < n)
                BFS(start);
            else
                printf("Invalid user!\n");
            break;

        case 3:
            printf("Enter starting user: ");
            scanf("%d", &start);

            if (start >= 0 && start < n)
            {
                for (i = 0; i < n; i++)
                    visited[i] = 0;

                printf("DFS: ");
                DFS(start);
                printf("\n");
            }
            else
                printf("Invalid user!\n");
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}