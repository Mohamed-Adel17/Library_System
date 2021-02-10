#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Struct of users */
#define MAX_NAME 15
#define ROWS 6
#define COLUMNS 20

typedef struct user
{
    char borrowed_books[ROWS][COLUMNS];
    char name[MAX_NAME];
    int password,id;
    char status,counter;     // if user has books it will be the number of books he has, otherwise status=0
    struct user *next;

}user_t;

/*Struct of books */
#define BOOK_NAME 25
#define AUTHORS 20
#define BORROWING_STATUS 20

typedef struct books
{
    char book_name[BOOK_NAME];
    char book_author[AUTHORS];
    char borrowing_status[BORROWING_STATUS];
    int owner;  // i will assign the id of the borrower_user in this variable
    int book_id ;
}books_t;


/*prototypes for functions*/
void print_All_Users();
user_t  * search_login_info(char[], int);
user_t  * search_Name(char[]);
user_t * search_id(int);
char appendNode(user_t *);


#endif // LINKED_LIST_H

