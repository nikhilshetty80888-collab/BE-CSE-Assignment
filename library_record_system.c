#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int issued;
};

struct Book books[MAX];
int count = 0;

void addBook() {
    if (count >= MAX) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", books[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", books[count].author);

    books[count].issued = 0;
    count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    int i;

    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n========== LIBRARY RECORDS ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID     : %d", books[i].id);
        printf("\nTitle       : %s", books[i].title);
        printf("\nAuthor      : %s", books[i].author);

        if (books[i].issued)
            printf("\nStatus      : Issued\n");
        else
            printf("\nStatus      : Available\n");

        printf("------------------------------------\n");
    }
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found!\n");
            printf("Book ID : %d\n", books[i].id);
            printf("Title   : %s\n", books[i].title);
            printf("Author  : %s\n", books[i].author);

            if (books[i].issued)
                printf("Status  : Issued\n");
            else
                printf("Status  : Available\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].issued)
                printf("\nBook is already issued!\n");
            else {
                books[i].issued = 1;
                printf("\nBook issued successfully!\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].issued)
                printf("\nBook is already available!\n");
            else {
                books[i].issued = 0;
                printf("\nBook returned successfully!\n");
            }
            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n====================================");
        printf("\n      LIBRARY RECORD SYSTEM");
        printf("\n====================================");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6:
                printf("\nThank you for using Library Record System!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
