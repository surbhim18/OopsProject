/*
 * Changes made:
 * commented function getobj()
 */

#include <iostream>
#include "register.h"
using namespace std;
/*
User getObj(string name, string psswrd)
{
    ifstream file;
    file.open("Users.txt", ios::in);
    User obj; //these kind of objects don't increment count value
    cout << "\nB4 reading pos: " << file.tellg();
    file.read((char*)&obj, sizeof(obj));
    cout << "\nAfter reading pos: " <<  file.tellg();
    while(file.tellg() > -1)
    {
        obj.display();
       // if(obj.getUserName() == name && obj.getPassword() == psswrd)
           {
               cout <<"\nin if";
            return obj;
           }
      //  else
           {
               cout <<"\nin else";
            cout << "\nB4 reading pos: " << file.tellg();
            file.read((char*)&obj, sizeof(obj));
            cout << "\nAfter reading pos: " <<  file.tellg();
           }
    }
    file.close();
    User tmp;
    return tmp;
}
*/

void getObj()
{
    User obj;
    obj.getObj();
    cout<<"\nIn getobj outside fn\n";
    obj.display();
    /*
    ifstream file;
    file.open("Users", ios::in);
    User obj;

    cout <<  "\ntellg at " << file.tellg();
    file.read((char*)&obj, sizeof(obj));
    cout <<  "\ntellg at " << file.tellg();

    while(file.tellg() > -1) //we did this initially
    {
        obj.display();
        cout <<  "\ntellg at " << file.tellg();
        file.read((char*)&obj, sizeof(obj));
        cout <<  "\ntellg at " << file.tellg();
    }
    file.close();
    */
}

User login()
{
    string name, pass = "";
	cout << "User Name: ";
	cin >> name;
	cout << "\nPassword: ";
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
            return login();
          }
        }
    }
     //return getObj(name, pass);
     getObj();
     User obj;
     return obj;
}



