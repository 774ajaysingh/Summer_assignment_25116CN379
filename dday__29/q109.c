/*Write a program to Create library 
management system. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    int  id;
    char title[60];
    char author[40];
    int  available;   /* 1 = on shelf, 0 = issued */
} Book;

Book books[MAX];
int  total = 0;

/* ── helpers ── */
void line(void) { printf("--------------------------------------------------\n"); }

void header(const char *t) {
    printf("\n==================================================\n");
    printf("  📚  LIBRARY MANAGEMENT  —  %s\n", t);
    printf("==================================================\n\n");
}

Book *find(int id) {
    for (int i = 0; i < total; i++)
        if (books[i].id == id) return &books[i];
    return NULL;
}

/* ── operations ── */
void add_book(void) {
    header("ADD BOOK");
    if (total >= MAX) { printf("  Library full!\n"); return; }
    Book *b = &books[total];
    b->id        = total + 1;
    b->available = 1;
    printf("  Title  : "); scanf(" %[^\n]", b->title);
    printf("  Author : "); scanf(" %[^\n]", b->author);
    total++;
    printf("\n  ✓ Book added! ID = %d\n", b->id);
}

void view_books(void) {
    header("ALL BOOKS");
    if (total == 0) { printf("  No books found.\n"); return; }
    printf("  %-4s %-35s %-20s %s\n", "ID", "Title", "Author", "Status");
    line();
    for (int i = 0; i < total; i++)
        printf("  %-4d %-35s %-20s %s\n",
               books[i].id, books[i].title, books[i].author,
               books[i].available ? "Available" : "Issued");
}

void search_book(void) {
    header("SEARCH BOOK");
    char key[60];
    printf("  Enter title keyword: "); scanf(" %[^\n]", key);
    int found = 0;
    printf("\n  %-4s %-35s %-20s %s\n", "ID", "Title", "Author", "Status");
    line();
    for (int i = 0; i < total; i++)
        if (strstr(books[i].title, key)) {
            printf("  %-4d %-35s %-20s %s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].available ? "Available" : "Issued");
            found = 1;
        }
    if (!found) printf("  No match found.\n");
}

void issue_book(void) {
    header("ISSUE BOOK");
    int id;
    printf("  Enter Book ID: "); scanf("%d", &id);
    Book *b = find(id);
    if (!b)             { printf("  ✗ Book not found.\n"); return; }
    if (!b->available)  { printf("  ✗ Already issued.\n"); return; }
    b->available = 0;
    printf("  ✓ \"%s\" issued successfully.\n", b->title);
}

void return_book(void) {
    header("RETURN BOOK");
    int id;
    printf("  Enter Book ID: "); scanf("%d", &id);
    Book *b = find(id);
    if (!b)            { printf("  ✗ Book not found.\n"); return; }
    if (b->available)  { printf("  ✗ Book already on shelf.\n"); return; }
    b->available = 1;
    printf("  ✓ \"%s\" returned successfully.\n", b->title);
}

void delete_book(void) {
    header("DELETE BOOK");
    int id;
    printf("  Enter Book ID to delete: "); scanf("%d", &id);
    for (int i = 0; i < total; i++)
        if (books[i].id == id) {
            printf("  ✓ \"%s\" deleted.\n", books[i].title);
            books[i] = books[--total];   /* replace with last */
            return;
        }
    printf("  ✗ Book not found.\n");
}

/* ── main ── */
int main(void) {
    /* seed data */
    strcpy(books[0].title,  "The C Programming Language");
    strcpy(books[0].author, "Kernighan & Ritchie");
    books[0].id = 1; books[0].available = 1;

    strcpy(books[1].title,  "Data Structures in C");
    strcpy(books[1].author, "Tanenbaum");
    books[1].id = 2; books[1].available = 1;

    total = 2;

    int choice;
    do {
        printf("\n==================================================\n");
        printf("        📚  LIBRARY MANAGEMENT SYSTEM\n");
        printf("==================================================\n");
        printf("  [1] Add Book\n");
        printf("  [2] View All Books\n");
        printf("  [3] Search Book\n");
        printf("  [4] Issue Book\n");
        printf("  [5] Return Book\n");
        printf("  [6] Delete Book\n");
        printf("  [0] Exit\n");
        printf("--------------------------------------------------\n");
        printf("  Choice: "); scanf("%d", &choice);

        switch (choice) {
            case 1: add_book();    break;
            case 2: view_books();  break;
            case 3: search_book(); break;
            case 4: issue_book();  break;
            case 5: return_book(); break;
            case 6: delete_book(); break;
            case 0: printf("\n  Goodbye! 👋\n\n"); break;
            default: printf("  ✗ Invalid option.\n");
        }
    } while (choice != 0);

    return 0;
}