#include <iostream>
#include <windows.h>
#include "login.h"
using namespace std;

int main()
{
    //remove("Users.txt");
    int choice;

    while(1)
    {
        cout << "\tMENU!\n";
        cout << "PRESS 1: To register.\n";
        cout << "PRESS 2: To login.\n";
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
        }
    }
    return 0;
}
