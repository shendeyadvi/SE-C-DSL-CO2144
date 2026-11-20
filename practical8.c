#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Structure to represent a hash table entry
typedef struct {
    int bookID;
    bool isOccupied;
    bool isDeleted;
} HashNode;

// Hash Table array
HashNode hashTable[TABLE_SIZE];

// Initialize the hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].bookID = -1;
        hashTable[i].isOccupied = false;
        hashTable[i].isDeleted = false;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// a. Insert book ID using linear probing
void insertBook(int bookID) {
    int hashIndex = hashFunction(bookID);
    int originalIndex = hashIndex;
    int i = 0;

    // Linear probing for finding an empty or deleted slot
    while (hashTable[hashIndex].isOccupied && hashTable[hashIndex].bookID != bookID) {
        i++;
        hashIndex = (originalIndex + i) % TABLE_SIZE;

        // If we have looped through the entire table
        if (hashIndex == originalIndex) {
            printf("Error: Hash table is full. Could not insert Book ID %d.\n", bookID);
            return;
        }
    }

    hashTable[hashIndex].bookID = bookID;
    hashTable[hashIndex].isOccupied = true;
    hashTable[hashIndex].isDeleted = false;
    printf("Inserted Book ID %d at index %d.\n", bookID, hashIndex);
}

// b. Search for a specific book ID
int searchBook(int bookID) {
    int hashIndex = hashFunction(bookID);
    int originalIndex = hashIndex;
    int i = 0;

    while (hashTable[hashIndex].isOccupied || hashTable[hashIndex].isDeleted) {
        if (hashTable[hashIndex].isOccupied && hashTable[hashIndex].bookID == bookID) {
            return hashIndex; // Found
        }
        i++;
        hashIndex = (originalIndex + i) % TABLE_SIZE;

        if (hashIndex == originalIndex) {
            break; // Full circle
        }
    }
    return -1; // Not found
}

// Display the contents of the hash table
void displayTable() {
    printf("\n--- Library Hash Table ---\n");
    printf("Index\tBook ID\t\tStatus\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        if (hashTable[i].isOccupied) {
            printf("%d\t\tOccupied\n", hashTable[i].bookID);
        } else if (hashTable[i].isDeleted) {
            printf("-\t\tDeleted\n");
        } else {
            printf("-\t\tEmpty\n");
        }
    }
    printf("--------------------------\n");
}

// Main function to test the program
int main() {
    initTable();

    // Insert sample Book IDs
    insertBook(101);
    insertBook(111); // Collides with 101 (111 % 10 = 1, 101 % 10 = 1) -> probes next index
    insertBook(203);
    insertBook(55);
    insertBook(45);  // Collides with 55

    displayTable();

    // Search for a book ID
    int searchID = 111;
    int pos = searchBook(searchID);
    if (pos != -1) {
        printf("\nBook ID %d found at index %d.\n", searchID, pos);
    } else {
        printf("\nBook ID %d not found in the library.\n", searchID);
    }

    searchID = 999;
    pos = searchBook(searchID);
    if (pos != -1) {
        printf("Book ID %d found at index %d.\n", searchID, pos);
    } else {
        printf("Book ID %d not found in the library.\n", searchID);
    }

    return 0;
}
