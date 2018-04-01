/*
 * Changes made:
 * added exit() in switch
 */

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "login.h"
using namespace std;

int main()
{
    //remove("Users.txt");
    int choice;

    ifstream fin;
    fin.open("Users",ios::in);
    User obj;
    while(fin)
    {
        if(fin)
        {
            fin.read((char*)&obj, sizeof(obj));
            obj.display();
        }
    }


/*
   while(1)
   {
        cout << "\n\n\tMENU!\n";
        cout << "PRESS 1: To register.\n";
        cout << "PRESS 2: To login.\n";
        cout << "PRESS 3: To exit.\n";
        cout << "Your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                registerUsr();
                cout << "Kindly login to proceed further.\n";
                Sleep(2000);
                getObj();
                break;
            }
        case 2:
            {
                User currentUser = login();
                User tmp;
                if(currentUser == tmp)
                {
                    cout << "\nno obj found!";
                }
                else
                {
                    cout <<"\nobj found!";
                }
                break;
            }
        case 3: exit(0);
        }
    }
    */
    return 0;
}
