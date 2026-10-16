#include <stdio.h>

#define MAX 50

int queue[MAX];
int front = -1;
int rear = -1;

//add patient
void addPatient (int patientID) 
{
    if (rear == MAX-1)
    {
        printf("the queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = patientID;

    printf("Patient ID %d added to the queue \n", patientID);
}

//attend patient
void attendPatient(){
    if (front == -1 || front>rear){
        printf("No patients to attend\n");
        return;
    }

    printf("The patient %d is being attended \n", queue[front]);
    front++;

    if (front>rear){
        front = -1;
        rear = -1;
    }
}

//view patient
void viewPatient(){
    int i;

    if (front == -1){
        printf("No patient waiting\n");
        return;
    }

    printf("The patient waiting are\n");

    for (i=front; i<=rear; i++){
        printf("Patient ID: %d\n", queue[i]);
    }
}

//check whether queue is empty
void isQueueEmpty(){
    if (front == -1)
    printf("The queue is empty!\n");

    else
    printf("The queue is not empty.\n");
}

int main(){
int choice, patientID;

        while(1){
        printf("------ HOSPITAL PATIENT REGISTRATION SYSTEM ------\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Exit\n");

        printf("Enter the choice: ");
        scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    printf("Enter the Patient ID: ");
                    scanf("%d", &patientID);
                    addPatient(patientID);
                    break;

                case 2:
                    attendPatient();
                    break;

                case 3:
                    viewPatient();
                    break;

                case 4:
                    isQueueEmpty();
                    break;

                case 5:
                    printf("Exiting....");
                    return 0;

                default:
                    printf("Invalid choice!");
            }
        }
    return 0;
}