#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include"Linked_list.h"


void WriteListIntoFile(user_t *head);

void  ReadListFromFile(void);

void WriteBooksStatusIntoFile(books_t *ptr);

void ReadBooksStatusFromFile(books_t *ptr);

#endif // FILEHANDLING_H
