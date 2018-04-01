#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<fstream>
#define MAX 5
using namespace std;

//Count.txt has the count of users currently registered with initial value 0 (indicating no user).
//Users.txt has the details of registered users.

int findCount()
{
    ifstream file;
    file.open("Count.txt", ios::in);
    string tmp;
    getline(file,tmp);
    int count = atoi(tmp.c_str());
    return count;
}
void incCount()
{
    int count = findCount();
    ofstream file;
    file.open("Count.txt");
    count++;
    file << count;
    file.close();
}

class User
{
	int userID;
	string userName, password;
	int noQues, noAns, ques[MAX], ans[MAX];

  public:
    User()
    {
        userID = -1;
		userName = "";
		password = "";
		noQues = 0;
		noAns = 0;
		for(int i=0; i<MAX; i++)
        {
            ques[i] = 0;
            ans[i] = 0;
        }
    }
	User(string name, string psswrd)
	{
		userID = findCount();
		userName = name;
		password = psswrd;
		noQues = 0;
		noAns = 0;
		for(int i=0; i<MAX; i++)
        {
            ques[i] = 0;
            ans[i] = 0;
        }
    }
	void putObj(); //stores User object in file
	string  getUserName()
	{
	    return userName;
	}
	string getPassword()
	{
	    return password;
	}
	void display();
	bool operator ==(User);
};

void User::putObj()
{
    ofstream file;
    file.open("Users.txt",ios::app | ios::ate);

   // cout << "\nB4 writing pos: " << file.tellp();
    file.write((char *)&(*this), sizeof(*this));
    //cout << "\nAfter writing pos: " << file.tellp();
    file.close();
    incCount();
}

void User::display()
{
    cout << "\n\tUser Profile\n";
    cout << "\nUser ID: " << userID;
    cout << "\nUserName: " << userName;
    //cout << "\nPassword: " << password;
    cout << "\nNo of ques asked: " << noQues;
    cout << "\nNo of answers authored: " << noAns;

    if(noQues)
    {
        cout << "\nQues ID of the asked ques: ";
        for(int i=0; i<noQues; i++)
            cout << ques[i];
    }
    if(noAns)
    {
        cout << "\nAnswer ID of the authored answers: ";
        for(int i=0; i<noAns; i++)
            cout << ans[i];
    }
}

bool User::operator == (User obj)
{
    if((userID == obj.userID)&&(userName == obj.userName)&&(password == obj.password)&&(noQues == obj.noQues)&&(noAns == obj.noAns))
        return 1;
    return 0;
}



