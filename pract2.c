#include<stdio.h>
int main() {
    int n;
    int roll_number[100];
    int temp;

    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("====================================\n");
    for(int i = 0; i < n; i++) {
        printf("Enter the roll no  for student %d: ", i + 1);
        scanf("%d", &roll_number[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(roll_number[j] > roll_number[j + 1]) {
                temp = roll_number[j];
                roll_number[j] = roll_number[j + 1];
                roll_number[j + 1] = temp;
            }
        }
        printf("After pass %d: ", i + 1);
        for(int k = 0; k < n; k++) {
            printf("%d ", roll_number[k]);
        }
        printf("\n");
    }
    printf("====================================\n");
    printf("Sorted roll numbers:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", roll_number[i]);
    }
    return 0;
}