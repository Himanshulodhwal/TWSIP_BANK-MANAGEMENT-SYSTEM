#include <iostream>
#include <conio.h>
#include<stdlib.h>

using namespace std;

class BankManagementSystem {
private:
    int total;
    int total_cash[100];
    int acc_no[100];
    string name[100];

public:
    BankManagementSystem() {
        total = 0;
    }
    // Main menu display function
    void display();
    // Function to input new account data
    void inputData();
    // Display all account holders' information
    void displayAllAccounts();
    // Modify account information
    void modfy_acc();
    // Check account balance
    void balance_enq();
    // Close an account
    void close_acc();
    // Deposit amount
    void Deposit();
    // Withdraw amount
    void withdraw();
};

void BankManagementSystem::display() {
    char ch;
    while (true) {
    // Display main menu
    cout<<"\n\t\t\t======================\n";
    cout<<"\t\t\tBANK MANAGMENT SYSTEM\n";
    cout<<"\t\t\t======================\n";
    cout<<"\t\t\t    ::MAIN MENU::\n\n";
    cout<<"\t\t\t1. NEW ACCOUNT\n";
    cout<<"\t\t\t2. DEPOSIT AMOUNT\n";
    cout<<"\t\t\t3. WITHDRAW AMOUNT\n";
    cout<<"\t\t\t4. BALANCE ENQUIRY\n";
    cout<<"\t\t\t5. ALL ACCOUNT HOLDER LIST\n";
    cout<<"\t\t\t6. CLOSE AN ACCOUNT\n";
    cout<<"\t\t\t7. MODIFY AN ACCOUNT\n";
    cout<<"\t\t\t8. EXIT\n\n";
    cout<<"\t\t\tSelect Your Option (1-8):";
    // Get user choice
        ch = getch();
    // Handle user choice
        switch (ch) {
            case '1':
                inputData();
                break;
            case '2':
                Deposit();
                break;
            case '3':
                withdraw();
                break;
            case '4':
                balance_enq();
                break;
            case '5':
                displayAllAccounts();
                break;
            case '6':
                close_acc();
                break;
            case '7':
                 modfy_acc();
                break;
            case '8':
                cout << "Exiting the program.\n";
                return;
            default:
                cout << "Invalid option. Please select a valid option.\n";
        }
    }
}

void BankManagementSystem::inputData() {
 // ... Input new account data ...
   cout << "\nEnter data of person " << total + 1 << endl;
        cout << "\nEnter name: ";
        cin >> name[total];
    int new_acc;
    bool accExists;

    do {
        accExists = false;
        cout << "\nAccount number: ";
        cin >> new_acc;

        // Check for duplicate ID
        for (int i = 0; i < total; i++) {
            if (acc_no[i] == new_acc) {
                cout << "\nError: account already exists. Please enter a different acc number. \n";
                accExists = true;
                break;
            }
        }
    } while (accExists);

    cout << "\nTotal Balance: ";
    cin >> total_cash[total];

    // Store the data if no duplicates found
    acc_no[total] = new_acc;
    total++;
}


void BankManagementSystem::displayAllAccounts() {
    // ... Display all account holders' information ...
    if(total==0)
    cout<<"\nNo record found\n";
    else{
    for (int i = 0; i < total; i++)
     { 
        cout << "\nData of person " << i + 1 << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Account number: " << acc_no[i] << endl;
        cout << "Total Balance: " << total_cash[i] << endl;  
    }
}
}
void BankManagementSystem::modfy_acc()
{   // ... Modify account information ...
    int acc_modify;
    cout<<"\nEnter account number of person you want to modify: ";
    cin>>acc_modify;
    for(int i=0;i<total;i++)
    {
        if(acc_no[i]==acc_modify)
        {
            cout<<"\n\t\tPrevious data: ";
            cout <<"Name: " << name[i] << endl;
            cout <<"Account number: " << acc_no[i] << endl;
            cout <<"Total Balance: " << total_cash[i] << endl;
            cout<<"\nEnter new data ";
            cout <<"\nEnter name: ";
            cin >> name[i];
            cout <<"\nAccount number: ";
            cin >> acc_no[i];
            cout <<"\nTotal Balance: ";
            cin >> total_cash[i];
            cout<<"\nData modified!!";
        }
        else
		cout<<"\nNo such record found"<<endl;    
    }
}
void BankManagementSystem::balance_enq() 
{     // ... Check account balance ...
    int new_acc;
    cout<<"\nEnter account number whose balance you want to see ";
    cin>>new_acc;
    for(int  i=0;i<total;i++)
    {
        if(acc_no[i]==new_acc)
        cout<<"\nYour balance is "<<total_cash[i];
        else
        {
		cout<<"\nNo such record found"<<endl;
         }
    }
}
void BankManagementSystem::close_acc()
{    // ... Close an account ...
int new_acc;
cout<<"\nEnter account number which you want close: ";
cin>>new_acc;
for(int  i=0;i<total;i++)
    {
        if(acc_no[i]==new_acc)
        {
         for(int j=i;j<total;j++)
       { name[j]=name[j+1]; 
        acc_no[j] =acc_no[j+1];
        total_cash[j]=total_cash[j+1];
        total--;
       }
        cout<<"\nAccount closed succesfully ";
        break;
        }
       else
        {
		cout<<"\nNo such record found"<<endl;
         }
    }
} 
void BankManagementSystem::Deposit()
{    // ... Deposit amount ...
    int new_acc;
    cout<<"\nEnter account number whose amount you want to deposit: ";
    cin>>new_acc;
    
     for(int  i=0;i<total;i++)
    {   int deposite=0;
        if(acc_no[i]==new_acc)
        {cout<<"\nEnter amount you want to deposit ";
        cin>>deposite;
        total_cash[i]=total_cash[i]+deposite;
        cout<<"\nDeposit succesfully ";
        }
        else
        {
		cout<<"\nNo such record found"<<endl;
         }
    }
}
void BankManagementSystem::withdraw()
{    // ... Withdraw amount ...
    int new_acc;
    cout<<"Enter account number whose amount you want to withdraw: ";
    cin>>new_acc;

     for(int  i=0;i<total;i++)
    { 
        int withdraw=0;
        if(acc_no[i]==new_acc)
        {cout<<"\nEnter amount you want to withdraw: ";
        cin>>withdraw;
        total_cash[i]=total_cash[i]-withdraw;
        cout<<"\nWithdraw succesfully ";
        }
        else
        {
		cout<<"\nNo such record found"<<endl;
         }
}
}

int main() {
   system("Color 1A");// Set console text and background color
    BankManagementSystem bms;
    bms.display();
    system("pause");// Pause before exiting


    return 0;
}
