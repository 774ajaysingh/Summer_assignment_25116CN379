/*Write a program to Create mini library 
system. */
#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int issued; // 0 = Available, 1 = Issued
};

int main()
{
    struct Book books[100];
    int n = 0, choice, id, i, found;

    do
    {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Book ID: ");
                scanf("%d", &books[n].id);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", books[n].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", books[n].author);

                books[n].issued = 0;
                n++;

                printf("Book Added Successfully!\n");
                break;

            case 2:
                if(n == 0)
                {
                    printf("\nNo books available.\n");
                }
                else
                {
                    printf("\n----- Book List -----\n");
                    for(i = 0; i < n; i++)
                    {
                        printf("\nBook ID : %d", books[i].id);
                        printf("\nTitle   : %s", books[i].title);
                        printf("\nAuthor  : %s", books[i].author);

                        if(books[i].issued == 0)
                            printf("\nStatus  : Available\n");
                        else
                            printf("\nStatus  : Issued\n");
                    }
                }
                break;

            case 3:
                printf("\nEnter Book ID to Search: ");
                scanf("%d", &id);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(books[i].id == id)
                    {
                        printf("\nBook Found!");
                        printf("\nTitle  : %s", books[i].title);
                        printf("\nAuthor : %s", books[i].author);

                        if(books[i].issued == 0)
                            printf("\nStatus : Available\n");
                        else
                            printf("\nStatus : Issued\n");

                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Book Not Found!\n");
                break;

            case 4:
                printf("\nEnter Book ID to Issue: ");
                scanf("%d", &id);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(books[i].id == id)
                    {
                        if(books[i].issued == 0)
                        {
                            books[i].issued = 1;
                            printf("Book Issued Successfully!\n");
                        }
                        else
                        {
                            printf("Book is already issued.\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Book Not Found!\n");
                break;

            case 5:
                printf("\nEnter Book ID to Return: ");
                scanf("%d", &id);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(books[i].id == id)
                    {
                        if(books[i].issued == 1)
                        {
                            books[i].issued = 0;
                            printf("Book Returned Successfully!\n");
                        }
                        else
                        {
                            printf("Book is already available.\n");
                        }
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Book Not Found!\n");
                break;

            case 6:
                printf("\nThank You! Exiting...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}