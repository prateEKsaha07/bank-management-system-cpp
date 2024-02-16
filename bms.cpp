#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class temp
{
    int accNo, newAmount;
    char name[25], fname[25], cnid[25], phone[25], email[25];
    float amount;
    fstream file, file1;

public:
    int search;

    void create_account(void);
    void deposit_amount(void);
    void withdraw_amount(void);
    void check_info(void);
};

int main()
{
    temp obj;
    char choice;
    cout << "----welcome to xyz national bank----" << endl;
    cout << "------------------------------------" << endl;
    cout << "press 1 to log in to your account " << endl;
    cout << "press 2 to create a new account " << endl;
    cout << "press 0 to exit the system" << endl;
    cout << "------------------------------------" << endl;
    cout << "enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cout << "enter your account number: ";
        cin >> obj.search;
        while (1)
        {
            cout << "\n----------------------------------------\n";
            cout << "\n press 1 to deposit amount";
            cout << "\n press 2 to withdraw amount ";
            cout << "\n press 3 to check your balance ";
            cout << "\n press 0 to go back in the main menu";
            cout << "\n----------------------------------------\n";
            cout << "enter your choice : ";
            cin >> choice;

            switch (choice)
            {
            case '1':
                cin.ignore();
                obj.deposit_amount();
                break;

            case '2':
                cin.ignore();
                obj.withdraw_amount();
                break;

            case '3':
                cin.ignore();
                obj.check_info();
                break;

            case '0':
                return 0;
                break;

            default:
                cout << "invalid input...please choose a valid one....";
                break;
            }
            system("pause");
            system("cls");
        }
        break;

    case '2':
        obj.create_account();
        break;

    case '0':
        system("exit");
        break;

    default:
        cout << "invalid input...please choose a valid one....";
        break;
    }

    return 0;
}

// defining the first function of thr program which creates the new account of a user
void temp ::create_account()
{
    srand(time(0));
    accNo = rand() * rand() * rand() * rand();

    cout << "enter your name :";
    cin >> name;
    cout << "enter your father's name : ";
    cin >> fname;
    cout << "enter your Cnid : ";
    cin >> cnid;
    cout << "enter your phone number : ";
    cin >> phone;
    cout << "enter your email id: ";
    cin >> email;
    cout << "enter your amount : ";
    cin >> amount;

    cout << "!! important note !! " << endl;
    cout << "this is your account number please save it  " << accNo << endl;

    file.open("data.txt", ios ::in | ios ::app);
    file << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
    file.close();
}
// defining the second function which will show the deposit amount function
void temp ::deposit_amount()
{
    cout << "enter the amount to deposit : ";
    cin >> newAmount;

    file.open("data.txt", ios ::in);
    file1.open("data1.txt", ios ::out| ios ::app);
    file >> accNo >> name >> fname >> cnid >> phone >> email >> amount;

    while (!file.eof()){
        if(accNo == search){
            cout << "\n current amount : " << amount;
            amount = amount + newAmount;
            cout << "\n updated amount : " << amount << endl;
            file1 << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
        }else{
            file1 << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
        }
        file << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

void temp ::withdraw_amount()
{
    cout << "enter the amount to withdraw: ";
    cin >> newAmount;

    file.open("data.txt", ios ::in);
    file1.open("data1.txt", ios ::out | ios ::app);
    file >> accNo >> name >> fname >> cnid >> phone >> email >> amount;

    while (!file.eof())
    {
        if (accNo == search)
        {
            cout << "\n current amount : " << amount;
            amount = amount - newAmount;
            cout << "\n updated amount : " << amount << endl;
            file1 << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
        }
        else
        {
            file1 << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
        }
        file << accNo << "\t" << name << "\t" << fname << "\t" << cnid << "\t" << phone << "\t" << email << "\t" << amount << endl;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

// defining the third function which will check info of the user

void temp ::check_info()
{
    fstream file;
    file.open("data.txt", ios::in);
    if (!file.eof()){
        cout<<"file opening error";
    }
      file >> accNo >> name >> fname >> cnid >> phone >> email >> amount;
        while(!file.eof()){
            if(accNo == search){
            cout << "\n-------------------------------------------\n";
            cout << "\n account number : ";
            cout << accNo;
            cout << "\n user name :";
            cout << name;
            cout << "\n fathers name :";
            cout << fname;
            cout << "\n cnid number :";
            cout << cnid;
            cout << "\n phone number :";
            cout << phone;
            cout << "\n email id : ";
            cout << email;
            cout << "\n current amount: ";
            cout << amount;
            cout<<"/n--------------------------------------------/n";
        }

        file >> accNo >> name >> fname >> cnid >> phone >> email >> amount;
    }
    
    file.close();
}