#include "Linked_list.h"

/* initialization of head and tail of linkedlist to be NULL */
user_t *head = NULL;
user_t *tail = NULL;


/*Function "appendNode()" take a pointer to the node made by"inputNode()" function,
   and copy its data in a new node in the LinkedList,
   and then free the location of the "pre_inputNode" node in memory. */
char appendNode(user_t *appender)
{
    user_t *node = (user_t *)malloc(sizeof(user_t));
    if (node==NULL)
    {
        return '0';
    }
    node->id = appender->id;
    node->password = appender->password;
    strcpy(node->name,appender->name);
    node->status=appender->status;
    node->counter = 0;

    if (head==NULL)    // means that the linkedlist is empty
    {
        node->next=NULL;
        head=node;
        tail=node;
    } else
    {
        node->next=NULL;
        tail->next=node;
        tail=node;
    }
   // free(appender);    // to free the location of the old node which i don't more need.
    return '1';
}



/*Function "search_Name()" takes a name and search in the linkedlist
   and return a pointer to the node it found that contains this name,
   otherwise, if the name is not exist in the list, it will return NULL.*/
user_t  * search_Name(char Name[15])
{
    user_t *ptr;
    for (ptr=head; ptr!=NULL ; ptr=ptr->next)
    {
        if (strcmp(ptr->name,Name) == 0)
        {
            return ptr;
        }
    }
    printf("Wrong data\n");
    return NULL;
}

user_t * search_id(int ID)
{
        user_t *ptr;
    for (ptr=head; ptr!=NULL ; ptr=ptr->next)
    {
        if (ptr->id == ID)
        {
            return ptr;
        }
    }
    printf("Wrong data\n");
    return NULL;
}



/*Function "search_login_info()" takes a name and a password,
   then it searchs in the linkedlist for a node contain this data,
   and return a pointer to the node it found,
   otherwise, if the data is not exist in the list, it will return NULL.*/

user_t  * search_login_info(char Name[15], int pass)
{
    user_t *ptr;
    for (ptr=head; ptr!=NULL ; ptr=ptr->next)
    {
        if ((strcmp(ptr->name,Name) == 0) && (ptr->password == pass))
        {
            return ptr;
        }
    }
    return NULL;
}



/*Function that print all existing users in the library.
  This function is called only in the admin mode */
void print_All_Users()
{
    user_t *ptr;
     printf("\nuser Name           password           id             borrowed books\n");
     printf("----------------------------------------------------------------------------------------\n");
    for (ptr=head;ptr!=NULL;ptr=ptr->next)
    {

        printf("\n%s            %d          %d             ",ptr->name,ptr->password,ptr->id);

        if (ptr->status == 0)   // all users have initialization of status=0 , it will increase in case the user have borrowed books
            {
                printf("There are no borrowed books\n");
                continue;
            }
        for(int i=0;i<ptr->status;i++)
            {
                printf("%s,",ptr->borrowed_books[i] );
            }
        printf("\n");
    }
}


void SendHeadandSaveList(void)
{
    WriteListIntoFile(head);
}

