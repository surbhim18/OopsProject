#include <iostream>
#include "userClass.h"
using namespace std;

void registerUsr()
{
	string name, pass = "";
	cout << "User Name: ";
	cin >> name;
	cout << "\nPassword(Max 6 characters): ";
    char ch;
    ch = _getch();
    for(int i=0; ; i++)
    {
       if(ch == '\r' || ch == ' ') //checking enter or space
          break;

       else
        {
          pass += ch;
          cout << '*';

          if(i == 5) //preventing extra user input, under normal circumstances this acts as the termination pt of the loop
            break;

          ch = _getch();
          if(ch == '\b')
          {
            cout << "\n\tERROR!\nBackspaces are not expected. Kindly re-enter the informations.\n\n";
            registerUsr();
            return;
          }
        }
    }
	User *obj  = new User(name, pass);
	obj->putObj();
	//User tmp = getObj();
	cout << "\nYou are successfully registered!\n";
	//tmp.display();
}





