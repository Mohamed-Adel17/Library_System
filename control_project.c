/*
   for admin login :
   name : admin or Admin
   password : 1234
*/

#include "control_project.h"
#define MAX_NAME 15
#define USER_MODE 1
#define ADMIN_MODE 2

/*This function is responsible for all actions made in the user mode.
  It calls many other functions, every function called for a specific purpose
  It check for the right call for the right option that choose by user. */
void user_process()
{
    char Name[MAX_NAME];
    char option;
bbb :
    printf("Enter user name : ");
    scanf("%14s",Name);
    int pass = enter_password();
    user_t * Ptr = search_login_info(Name,pass);
    if (Ptr!=NULL)
aaa :
    option = print_options(USER_MODE);
    switch(option)
    {
        case '1' : print_user(Ptr);
         goto aaa;
         break;
        case '2' : print_available_books();
         goto aaa;
        break;
        case '3' : print_user_borrowed_books(Ptr);
         goto aaa;
        break;
        case '4' : return; break;    // to return to the main menu screen of choosing between the two modes.
        default :
            printf("Wrong Entry!!, Try Again.\n\n");
            goto bbb;
    }
}



/*This function is the same as the above function but for the admin mode.
  It calls many other functions, every function called for a specific purpose
  It check for the right call for the right option that choose by admin. */
void admin_process()
{
    char Name[MAX_NAME];
    char option;
    int pass;
bbb :
    printf("Enter Admin name : ");
    scanf("%14s",Name);
    pass = enter_password();
    if ((!(strcmp(Name,"admin")) || !(strcmp(Name,"Admin")))&& (pass==1234))
    {

aaa :
        option = print_options(ADMIN_MODE);
        user_t * Ptr;
        switch(option)
        {
            case '1' :
                print_All_Users();
                goto aaa;
                break;
            case '2' :
                Ptr=inputNode();
                char checked = appendNode(Ptr);
                check_process(checked);
                goto aaa;
                break;
            case '3' :
                print_available_books();
                reserve_book();
                goto aaa;
                break;
            case '4' :
                print_notAvailable_books();
                make_book_available();
                goto aaa;
            case '5' : return; break;
            default :
                printf("Wrong Entry!!, Try Again.\n");
                goto aaa;
        }
    }else
    {
        printf("Wrong entry, Try again\n\n");
        goto bbb;
    }
}

/*This function is considered as the main controller of the whole project.
   it calls one of the two above functions.
   This function is repeated for infinity as long as the program is running. */
void MainScreen()
{
   char choice = login_mode();
   switch (choice)
   {
       case '1' : user_process(); break;
       case '2' : admin_process(); break;
       default : printf("Wrong Entry!!, Try Again\n"); break;
   }
}
