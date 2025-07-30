#include<iostream>
#include <string> 
using namespace std;
struct BankAccount {
    string holderName;
    string accountType;
    int accountNumber;
    double balance;
};
void createAccounts(BankAccount* accounts, int n_cus);
void displayAccounts(BankAccount* accounts, int n_cus);
void withdraw(BankAccount* accounts, int n_cus);
void deposit(BankAccount* accounts, int n_cus);
void checkBalance(BankAccount* accounts, int n_cus);
void editAccount(BankAccount* accounts, int n_cus);
void searchAccount(BankAccount* accounts, int n_cus);
void deleteAccount(BankAccount* accounts, int& n_cus);






int main() {
    int n_cus,choice;
    cout <<"Enter the number of customers"<<endl ;
    cin>>n_cus;
    BankAccount* accounts = new BankAccount[n_cus];
    do{
   cout<<"1-createAccount\n";
   cout<<"2-displayAccounts\n";
   cout<<"3-withdraw\n";
   cout<<"4-deposit\n";
   cout<<"5-checkBalance\n";
   cout<<"6-editAccount\n";
   cout<<"7-searchAccount\n";
   cout<<"8-deleteAccount\n";
   cout<<"0-Exit\n";
   cin>>choice;
   switch(choice){
    case 1:createAccounts(accounts,n_cus);break;
    case 2:displayAccounts(accounts,n_cus);break;
    case 3:withdraw(accounts,n_cus);break;
    case 4:deposit(accounts,n_cus);break;
    case 5:checkBalance(accounts,n_cus);break;
    case 6:editAccount(accounts,n_cus);break;
    case 7:searchAccount(accounts,n_cus);break;
    case 8:deleteAccount(accounts, n_cus);break;
    case 0:{
                cout << "Thank you for using the system. Goodbye!\n";
                break;}
    default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
    delete[] accounts;
    return 0;
}

void createAccounts(BankAccount* accounts, int n_cus){
 for(int i=0;i<n_cus;i++){
    cout<<"Enter customer data number"<<i+1<<endl;
    cout<<"Name: ";
    cin>> accounts[i].holderName;
    cout<<endl;
    cout<<"accountType: "<<endl;
    cin>>accounts[i].accountType;
    cout<<endl;
    cout<<"balance: "<<endl;
    cin>>accounts->balance;
    accounts->accountNumber=i+1;

 }
}

void displayAccounts(BankAccount* accounts, int n_cus){
    cout<<"Account data"<<endl;
  for(int i=0;i<n_cus;i++){
    cout << "accountNumber: "  << accounts[i].accountNumber << endl;
    cout << "holdername: " << accounts[i].holderName << endl;
    cout << "account Type " << accounts[i].accountType << endl;
    cout << "balance " << accounts[i].balance << " pound" << endl;
    
  } 
}

void withdraw(BankAccount* accounts, int n_cus){
   int i,Ac_num,amount;
cout<<"Enter accountNumber: ";
cin>>Ac_num;
cout<<"Enter amount: ";
cin>>amount;
for(i=0;i<n_cus;i++){
if (accounts[i].accountNumber==Ac_num){
    if(accounts[i].balance-amount>=0){
    accounts[i].balance=accounts[i].balance - amount;
    cout << "Withdraw done successfully\n";
    break;
    
    }
}



}
if(i==n_cus)
cout<<"Account does not exist";

}

void deposit(BankAccount* accounts, int n_cus){
    int i,Ac_num,amount;
    cout<<"Enter accountNumber: ";
    cin>>Ac_num;
    cout<<"Enter amount: ";
    cin>>amount;
    for(i=0;i<n_cus;i++){
    if (accounts[i].accountNumber==Ac_num){
        if(amount>=0)
        accounts[i].balance=accounts[i].balance + amount;
        cout << "deposit done successfully\n";
         break;

    }
    
    }
    if(i==n_cus)
    cout<<"Account does not exist";

}

void checkBalance(BankAccount* accounts, int n_cus){
    int i,Ac_num;
    cout<<"Enter accountNumber: ";
    cin>>Ac_num;
    for(i=0;i<n_cus;i++){
    if (accounts[i].accountNumber==Ac_num){
         cout<<accounts[i].balance<<endl;
    }
    
    }
    if(i==n_cus)
    cout<<"Account does not exist";
}

void editAccount(BankAccount* accounts, int n_cus){
    int i,Ac_num,choice;
    string name;
    string type;
    cout<<"Enter accountNumber: ";
    cin>>Ac_num;
    for(i=0;i<n_cus;i++){
    if (accounts[i].accountNumber==Ac_num){
        cout<<"Enter 1 to edit the holdername or click 2 to edit account type or click 3 to edit hodername&account type ";
        cin>>choice;
        switch(choice){
             case 1 : {
                cout<<"Enter the new holdername: ";
                cin>>name;
                accounts[i].holderName=name;
             };break;
             case 2: {
                cout<<"Enter the new account type: ";
                cin>>type;
                accounts[i].accountType=type;
             };break;
             case 3:{
                cout<<"Enter the new holdername: ";
                cin>>name;
                accounts[i].holderName=name;
                cout<<"Enter the new account type: ";
                cin>>type;
                accounts[i].accountType=type;


             };break;
             default:
             cout << "Invalid choice." << endl;
            }
        }
    
    }
    if(i==n_cus)
    cout<<"Account does not exist";

}

void searchAccount(BankAccount* accounts, int n_cus){
    int i,Ac_num,choice;
    string name;
cout<<"To search by account number enter 1 , to search by holdername enter 2";
cin>>choice;
switch(choice){
    case 1 :{
        cout<<"enter account number: ";
        cin>>Ac_num;
        for(i=0;i<n_cus;i++){
            if(accounts[i].accountNumber==Ac_num){
                cout<<accounts[i].accountNumber<<endl;
                cout<<accounts[i].accountType<<endl;
                cout<<accounts[i].balance<<endl;
                cout<<accounts[i].holderName<<endl;



        }
    }
    if(i==n_cus)
    cout<<"Account does not exist";
};break;
case 2 :{
    cout<<"enter holdername: ";
    cin>>name;
    for(i=0;i<n_cus;i++){
        if(accounts[i].holderName==name){
            cout<<accounts[i].accountNumber<<endl;
            cout<<accounts[i].accountType<<endl;
            cout<<accounts[i].balance<<endl;
            cout<<accounts[i].holderName<<endl;



    }
}
if(i==n_cus)
cout<<"Account does not exist";
};break;
}
}

void deleteAccount(BankAccount* accounts, int& n_cus){
    int i,Ac_num;
cout<<"Enter account number";
cin>>Ac_num;
for(i=0;i<n_cus;i++){
    if(accounts[i].accountNumber==Ac_num)
    {
      for(int j=i; j<n_cus-1; j++)
      accounts[j]=accounts[j+1];
      n_cus--;
      break;
    }
    
}
if(i==n_cus)
cout<<"Account does not exist";
}










