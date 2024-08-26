#include <iostream>
#include <exception>
#include<vector>
using namespace std;

class account
{
    public:
    int acc_num, bal;
    string name, type;
    void set_basics()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter account number: ";
        cin>>acc_num;
        cout<<"Enter account type: ";
        cin>>type;
    }
    void set_bal(int bal2)
    {
        cout<<"Enter the amount, you want to deposit: ₹";
        cin>>bal2;
        bal = bal + bal2;
    }
};
class cur_acct : public account
{
    public:
    void dis_cur_bal()
    {
        cout<<"Current balance: ₹"<<bal<<endl;
    }
    void checkbook()
    {
        cout<<"Checkbook will be provided."<<endl;
    }
    void panelty()
    {
        if (bal<8330)
            bal = bal - 3000;
    }
    void cur_basics(account x)
    {
        cur_acct::acc_num = x.acc_num;
        cur_acct::name = x.name;
        cur_acct::type = x.type;
    }
};
class sav_acct : public account
{
   public:
   void dis_sav_bal()
   {
    cout<<"Current balance: ₹"<<(bal + (bal/100)*6.5)<<endl;
   }
   void sav_basics(account x)
    {
        sav_acct::acc_num = x.acc_num;
        sav_acct::name = x.name;
        sav_acct::type = x.type;
    }
};

int main()
{
    int n;
    cout<<"Enter the number of account you want to create: ";
    cin>>n;
    vector<account> cstmr(n);
    vector<cur_acct> cur_cstmr(n);
    vector<sav_acct> sav_cstmr(n);
    for(int i=0; i<n; i++)
        cstmr.at(i).set_basics();
    for(int i=0; i<n; i++)
    {
        if(cstmr[i].type == "Current")
            cur_cstmr[i].cur_basics(cstmr[i]);
        if(cstmr[i].type == "Saving")
            sav_cstmr[i].sav_basics(cstmr[i]);
    }
    cout<<"*************************************"<<endl;
    int num, i=0;
    string acc_type;
    cout<<"Enter account number: ";
    cin>>num;
    cout<<"Enter account type: ";
    cin>>acc_type;
    cout<<"'1' for deposit."<<endl;
    cout<<"'2' for balance display."<<endl;
    cout<<"'3' for withdrawal."<<endl;
    cout<<"Enter 1, 2 or 3: "<<endl;
    int x;
    cin>>x;
    switch(x)
    {
        case 1:
        {
            if(acc_type == "Current")
            {
                while((cur_cstmr.at(i).acc_num == num)||(i<n))
                    i=i+1;
                i=i-1;
                int b; cin>>b;
                cur_cstmr.at(i).set_bal(b);
            }
            if(acc_type == "Saving")
            {
                while((sav_cstmr.at(i).acc_num == num)||(i<n))
                    i=i+1;
                i=i-1;
                int b; cin>>b;
                sav_cstmr.at(i).set_bal(b);
            }
        }
        break;
    }
    return 0;
}