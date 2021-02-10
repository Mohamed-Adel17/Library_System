#include "InOut.h"

#define BOOKS_NUMBER 6
#define MAX_NAME 15
books_t book[BOOKS_NUMBER];

/*Function "inputNode()" asks for data from user in the run-time,
and saves them in a node,then returns a pointer to this node.*/
user_t * inputNode()
{
      user_t *Node = (user_t *)malloc(sizeof(user_t));

      printf("Enter the user name : ");
      scanf("%14s",Node->name);
      printf("Enter the user password : ");
      scanf("%d",&Node->password);
      printf("Enter the user id : ");
      scanf("%d",&Node->id);
      Node->status=0;

      return Node;
}



/*Function "pre_inputNode()" takes data and returns a pointer to the node it saved the data in.
   Will use it only to pre-set some users in the library. */
user_t * pre_inputNode(char name[MAX_NAME],int pass,int id)
{
      user_t *Node = (user_t *)malloc(sizeof(user_t));
      Node->password = pass;
      Node->id= id;
      Node->status=0;
      strcpy(Node->name,name);

      return Node;
}



/*Function that print a specific user data in the library.
  It takes a pointer to his node (resulted from search function) and print his data */
void print_user(user_t * searched)
{
    if (searched != NULL)
    {
    printf("\n user Name : %s",searched->name);
    printf("\n password : %d",searched->password);
    printf("\n id : %d\n",searched->id);
    }
}



/*Function "check_process()" to check if the process was successful or not
   it take 0 or 1
   if "0" it prints successful , otherwise it prints failure */
void check_process(char checked)
{
    switch(checked)
    {
    case '1' : printf("\tThis operation is Successful\n"); break;
    case '0' : printf("\tThis operation failed\n"); break;
    }
}


/*Function "login_mode()" to print the two modes option,
   and return this option */
char login_mode()
{
    char mode;
    printf("\n\t\t--------------------------------------------------------------------------------------\n");
    printf("\t 1- user mode.\n\t 2- admin mode.\n\n");
    printf("choose the mode you want to access : \n");
    scanf(" %c",&mode);
    return mode;
}



/*Function "enter_password()" that ask the user to enter a password,
   and returns this password. */
int enter_password()
{
     int pass;
    printf("Enter the password : ");
    scanf("%d",&pass);
    return pass;
}



/*Function "print_options()" takes a choice of two modes,
   and print options to user upon this choice,
   then it asks th user to choose one option,
   and takes this option and return it. */
char print_options(char mode)
{
        char option;
        switch (mode)
        {
        case 1 :
            {
                printf("\n\t 1- view your info.\n");
                printf("\t 2- view all the books available to borrow.\n");
                printf("\t 3- view your borrowed books.\n");
                printf("\t 4- Return.\n\n");
                printf("choose the option you want : ");
                scanf(" %c",&option);
                break;
            }
        case 2 :
            {
                printf("\n\t1. view all users data\n");
                printf("\t2. Add new user\n");
                printf("\t3. make reservation of a book\n");
                printf("\t4. make a reserved book available in stock again.\n");
                printf("\t5. Return.\n\n");
                printf("choose the option you want : ");

                scanf(" %c",&option);
                break;
            }
       }
       return option;
}



/*function "print_available_books()" prints all available books in the library. */
void print_available_books()
{
    printf("Book name               Author name             Book id\n");
    printf("--------------------------------------------------------------------\n");

    for (int i=0;i<BOOKS_NUMBER;i++)
    {
        if(strcmp(book[i].borrowing_status,"available")==0)  // checks if this book is available or not
        {
            printf("%s               %s             %d\n",book[i].book_name,book[i].book_author,book[i].book_id);
        }
    }
}



/*This function is the opposite of the previous function,
   it prints all not available books and their borrowers
   i will use it when i want to make a book available again. */
void print_notAvailable_books()
{
    printf("Book name                Author name                   Book id                Borrower\n");
    printf("--------------------------------------------------------------------------------\n");

    for (int i=0;i<BOOKS_NUMBER;i++)
    {
        if(strcmp(book[i].borrowing_status,"not available")==0)
        {
            user_t *ptr=search_id(book[i].owner);
            printf("%s                %s                   %d                  %s\n",book[i].book_name, book[i].book_author, book[i].book_id, ptr->name);
        }
    }
}



/*Function "reserve_book()" used to reserve a book for a user by the admin,
   it asks the admin fot the id of the book and the user name,
   then it searches  by this name for its linkedlist node,
   and add this book for this user's borrowed books list. */
void reserve_book()
{
    int ID;
    char Name[MAX_NAME];
    user_t *ptr;
    aaa :
    printf("\nEnter id of the book you want to reserve :  ");
    scanf("%d",&ID);
    printf("Enter the user name who will borrow the book : ");
    scanf(" %s",Name);
    if ((ID<=BOOKS_NUMBER)&& !(strcmp(book[ID-1].borrowing_status, "available")))
        {
            ptr= search_Name(Name);
            if(ptr!=NULL)
            {
            strcpy(ptr->borrowed_books[ptr->status] , book[ID-1].book_name);    // status starts from 0 and increased with every new book borrowed
            strcpy(book[ID-1].borrowing_status,"not available");       // ID-1 as index of array starting from 0, but the book_id starts from 1
            book[ID-1].owner = ptr->id;     // assign the id of the user in the owner variable
            ptr->status++;      // increment of status variable as this user owned a new book
            printf("\tThe operation done successfully\n");
            return;
            }
            else
                return;
        }
        else{
            printf("\tnot available id, try again\n\n");
            goto aaa;
        }
}



/*This function is the opposite of the previous function,
   it makes an borrowed book to be available again,
   it asks the admin for id of the book and then it makes this book available. */
void make_book_available()
{
    int ID;
    printf("\nEnter id of the book :  ");
    scanf("%d",&ID);
    user_t *Ptr = search_id(book[ID-1].owner);   // passing the id of the borrower to function search_id()
    if((ID<= BOOKS_NUMBER)&& !(strcmp(book[ID-1].borrowing_status, "not available")))
    {
    strcpy(book[ID-1].borrowing_status,"available");
    Ptr->status--;    // to decrement the status variable as the user returned a book
    return;
    }else
    {
    printf("\twrong id, try again\n\n");
    return;
    }
}



/*This function prints all borrowed books by a specific user
   It takes a pointer to the node of this user,
    if he has borrowed books, it prints them
    otherwise, it prints that he does not have any book. */
void print_user_borrowed_books(user_t * searched)
{
    if (searched != NULL)
    {
        printf("borrowed books : \n");
        if (searched->status == 0)     // the default state for any user before borrowing books
            {
                printf("\t\tThere are no borrowed books\n");
                return;
            }
        for(int i=0; i< searched->status; i++)
            {
                printf("%s\n",searched->borrowed_books[i] );
            }
        printf("\n");
    }
}


/*I used this function to assign books data to books_t struct,
  it takes a pointer to the address of the array object of structs
  and assigns all data belows.*/
void assign_books_data(books_t *ptr)
{

ptr->book_id = 1;
ptr->owner=0;
strcpy(ptr->book_name,"Ulysses");
strcpy(ptr->book_author,"James Joyce");
strcpy(ptr->borrowing_status,"available");
ptr++;

ptr->book_id = 2;
ptr->owner=0;
strcpy(ptr->book_name,"Don Quixote");
strcpy(ptr->book_author,"Miguel de Cervantes");
strcpy(ptr->borrowing_status,"available");
ptr++;

ptr->book_id = 3;
ptr->owner=0;
strcpy(ptr->book_name,"The Great Gatsby");
strcpy(ptr->book_author,"F. Scott Fitzgerald");
strcpy(ptr->borrowing_status,"available");
ptr++;

ptr->book_id = 4;
ptr->owner=0;
strcpy(ptr->book_name,"Moby Dick");
strcpy(ptr->book_author,"Herman Melville");
strcpy(ptr->borrowing_status,"available");
ptr++;

ptr->book_id = 5;
ptr->owner=0;
strcpy(ptr->book_name,"War and Peace");
strcpy(ptr->book_author,"Leo Tolstoy");
strcpy(ptr->borrowing_status,"available");
ptr++;

ptr->book_id = 6;
ptr->owner=0;
strcpy(ptr->book_name,"Hamlet");
strcpy(ptr->book_author,"William Shakespeare");
strcpy(ptr->borrowing_status,"available");

}

void SendBookOBJandWriteStatusIntoFile(void)
{
    WriteBooksStatusIntoFile(book);
}

void SendBookOBJandReadStatusFromFile(void)
{
    ReadBooksStatusFromFile(book);
}
