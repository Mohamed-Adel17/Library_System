#include "FileHandling.h"
#include <stdio.h>
#include "Linked_list.h"

void WriteListIntoFile(user_t *head)
{
    FILE *fptr;
    user_t *Node;
    fptr = fopen("LinkedListData.txt","w");

    if(fptr!=NULL)
    {
      for(Node=head;Node!=NULL;Node=Node->next)
      {
          fprintf(fptr,"%s %d %d %d\n",Node->name,Node->password,Node->id,Node->status);
      }
    }
     fclose(fptr);
}

void ReadListFromFile(void)
{
    FILE *fptr;
    user_t *Node = (user_t *)malloc(sizeof(user_t));
    fptr = fopen("LinkedListData.txt","r");
    if(fptr!=NULL)
    {
        while(fscanf(fptr,"%s %d %d %d",&Node->name,&Node->password, &Node->id, &Node->status) == 4)
        {
            Node->next = NULL;
            appendNode(Node);
        }
    }
    fclose(fptr);

}


void WriteBooksStatusIntoFile(books_t *ptr)
{
    FILE *fptr;
    fptr = fopen("BooksStatusData.txt","w");

    if(fptr!=NULL)
    {
        for(int i=0;i<6;i++)
          fprintf(fptr,"%d %d\n",ptr[i].owner,ptr[i].book_id);

    }
     fclose(fptr);
}


void ReadBooksStatusFromFile(books_t *ptr)
{
    FILE *fptr;
    fptr = fopen("BooksStatusData.txt","r");
    int i=0;
    if(fptr!=NULL)
    {
        while(fscanf(fptr,"%d %d",&ptr[i].owner,&ptr[i].book_id) == 2)
        {
            if(ptr[i].owner!=0)
            {
                user_t *Node = search_id(ptr[i].owner);
                strcpy(Node->borrowed_books[Node->counter] , ptr[i].book_name);   
                strcpy(ptr[i].borrowing_status,"not available");      
                Node->counter++;
            }
            i++;
        }
    }
     fclose(fptr);
}
