#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *left;
    struct Node *right;
};

//create a new node
struct Node* createNode(int roll){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->roll=roll;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

//insert new node
struct Node* insert(struct Node *root, int roll){
    if(root == NULL){
        return createNode(roll);
    }

    else if(roll<root->roll)
        root->left = insert(root->left, roll);

    else if(roll>root->roll)
        root->right = insert(root->right, roll);

    else
        printf("The roll number already exists!\n");

    return root;
}

//search for a student
struct Node* search(struct Node *root, int roll){
    if(root == NULL || root->roll == roll)
        return root;

    if(roll<root->roll)
        return search(root->left, roll);

    return search(root->right, roll);
}

//find minimum node
struct Node* findMin(struct Node *root){
    while(root != NULL && root->left != NULL)
        root =root->left;

    return root;
}

//delete a node
struct Node* deleteNode(struct Node *root, int roll){
    struct Node *temp;

    if (root == NULL){
        printf("Student record not found!\n");
        return root;
    }

    if (roll<root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll>root->roll)
        root->right = deleteNode(root->right, roll);
    else{
        //No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        //One child
        else if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }

        //Two child
        temp = findMin(root->right);
        root->roll = temp->roll;
        root->right = deleteNode(root->right, temp->roll);
    }
    return root;
}

//Inorder: left, root, right
void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->roll);
        inorder(root->right);
    }
}

//Preorder: root, left, right
void preorder(struct Node *root){
    if(root != NULL){
        printf("%d", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder: left, right, root
void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->roll);
    }
}

int main(){
    struct Node *root = NULL;
    struct Node *result;
    int choice, roll;

    do
    {
        printf("\n ------STUDENT RECORD MANAGEMENT------ \n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the roll number: ");
                scanf("%d", &roll);
                root = insert(root, roll);
                break;

            case 2:
                printf("Enter the roll number to delete: ");
                scanf("%d", &roll);
                if (search(root, roll) == NULL){
                    printf("Roll number not found\n");
                }
                else{
                    root = deleteNode(root, roll);
                    printf("Roll number deleted successfully!\n");
                }
                break;

            case 3:
                printf("Enter the roll number to search: ");
                scanf("%d", &roll);
                result = search(root, roll);
                if(result != NULL){
                    printf("Student with roll number %d found. \n", result->roll);
                }
                else{
                    printf("Student record not found!\n");
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preoder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...");
                break;

            default:
                printf("Invalid Choice!!");
                break;
        }

    } while (choice != 7);

    return 0;
    
}