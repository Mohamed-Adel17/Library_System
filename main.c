/*
   for admin login :
   name : admin or Admin
   password : 1234
*/

#include "Linked_list.h"
#include "InOut.h"
#include "control_project.h"

books_t book[6];  // a global array object of struct "books_t"

int main()
{
assign_books_data(&book);  // a function that assign books data to books_t struct


/* To initialize some already existing users in the library.
    Function "pre_inputNode" returns a pointer to the node it saved the data in.
    Function "appendNode" take this node and copy its data in a new node in the LinkedList,
    and then free the location of the "pre_inputNode" node in memory. */
appendNode(pre_inputNode("Mohamed",1111,1));      // (name,password,id)
appendNode(pre_inputNode("Ahmed",2222,2));          // (name,password,id)
appendNode(pre_inputNode("Ali",3333,3));                // (name,password,id)
appendNode(pre_inputNode("Eslam",4444,4));         // (name,password,id)



printf("\t\t\t\t/*************Library Project*************/\n");
printf("\t\t\t/*************Developed by (Mohamed Adel)*************/\n");

while (1)
{
    MainScreen();   // a function in the "control_project.c" file
}
    return 0;
}
