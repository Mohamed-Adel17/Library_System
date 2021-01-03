#ifndef INOUT_H
#define INOUT_H
#include "Linked_list.h"

/*prototypes for functions*/
user_t * inputNode();
user_t * pre_inputNode(char[],int,int);

char login_mode();
char print_options(char);
int enter_password();
void print_user(user_t * searched);
void print_available_books();
void reserve_book();
void print_user_borrowed_books(user_t *);
void make_book_available();
void print_notAvailable_books();
void check_process(char);
void assign_book_data(books_t *);
#endif // INOUT_H

