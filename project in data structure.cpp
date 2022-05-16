#include<iostream>
#include<string>
#include<stdlib.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"
using namespace std;
class node
{
    public:
    string term;
    int number;
    int earnings;
    int paid;
    int dd;
    int mm;
    int yy;
    node* next;
    node(string name, int num, int salary)
    {
        term=name;
        number=num;
        earnings=salary;
        paid=NULL;
        dd=NULL;
        mm=NULL;
        yy=NULL;
        next=NULL;
    }
};

class nod
{
    public:
    nod* previous;
    string pname;
    int price;
    nod* next;
    nod(string nam, int cost)
    {
        previous=NULL;
        pname=nam;
        price=cost;
        next=NULL;
    }
};

node* head=NULL;
nod* top=NULL;
int entry=5521;
int c=0;

void sorting()
{
    for(int i=0;i<c-1;i++)
    {
        node* temp=head;
        int flag=-1;
        while(temp->next!=NULL)
        {
            if(temp->earnings > temp->next->earnings)
            {
                string a=temp->term;
                temp->term=temp->next->term;
                temp->next->term=a;
                int b1=temp->number;
                temp->number=temp->next->number;
                temp->next->number=b1;
                int b2=temp->earnings;
                temp->earnings=temp->next->earnings;
                temp->next->earnings=b2;
                int b3=temp->paid;
                temp->paid=temp->next->paid;
                temp->next->paid=b3;
                int b4=temp->dd;
                temp->dd=temp->next->dd;
                temp->next->dd=b4;
                int b5=temp->mm;
                temp->mm=temp->next->mm;
                temp->next->mm=b5;
                int b6=temp->yy;
                temp->yy=temp->next->yy;
                temp->next->yy=b6;
                flag=0;
            }

            temp=temp->next;
        }
        if(flag==-1)
        {
            break;
        }
    }
}

void employeeDetails()
{
    system("clear");
    node* temp=head;
    if(temp==NULL)
    {
        cout<<RED<< "\t\t No element is present."<<RESET<<endl;
        return;
    }
    sorting();
    while(temp!=NULL)
    {
        cout<<BOLDCYAN<< "\t\t Name:"<<RESET;
        cout<<temp->term<<endl;
        cout<<BOLDCYAN<< "\t\t Number:"<<RESET;
        cout<<temp->number<<endl;
        cout<<BOLDCYAN<< "\t\t Selary:"<<RESET;
        cout<<temp->earnings<<endl;
        cout<<BOLDCYAN<< "\t\t Paid:"<<RESET;
        cout<<temp->paid<<endl;
        cout<<BOLDCYAN<< "\t\t Payment date:"<<RESET;
        cout<<temp->dd<<"/";
        cout<<temp->mm<<"/";
        cout<<temp->yy<<endl;
        cout<<BOLDCYAN<< "\t\t Due:"<<RESET;
        cout<<temp->earnings-temp->paid<<endl;
        temp=temp->next;
    }
    cout<<endl;
}

void addPament()
{
    a_pay:
    system("clear");
    node* temp=head;
    if(temp==NULL)
    {
        cout<<RED<< "\t\t No Employee Added."<<RESET<<endl;
        return;
    }
    string name;
    cout<<BLUE<<endl<< "\t\t Enter Employee Name: "<<RESET;
    cin.ignore();
    getline(cin,name);
    while(temp->next!=NULL)
    {
        if(temp->term==name)
        {
            break;
        }
        temp=temp->next;
    }
    if(temp->term!=name)
    {
        cout<<BOLDRED<< "\t\t Wrong Input"<<RESET<<endl;
        choic:
        cout<<BLUE<<endl<< "\t\t #1. Another Payment"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        int j;
        cin>>j;
        if(j==1)
            goto a_pay;
        if(j==2)
        {
            system("clear");
            return;
        }
        else
        {
            system("clear");
            cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
            goto choic;
        }
    }
    int amount;
    int date;
    int month;
    int year;
    cout<<BLUE<< "\t\t Enter Amount: "<<RESET;
    cin>>amount;
    temp->paid=amount;
    cout<<BLUE<< "\t\t Enter Date of pament: "<<RESET<<endl;
    cout<<BLUE<< "\t\t dd - "<<RESET;
    cin>>date;
    temp->dd=date;
    cout<<BLUE<< "\t\t mm - "<<RESET;
    cin>>month;
    temp->mm=month;
    cout<<BLUE<< "\t\t yy - "<<RESET;
    cin>>year;
    temp->yy=year;
    choice:
    cout<<BLUE<<endl<< "\t\t #1. Another Payment"<<RESET<<endl;
    cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
    cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
    int j;
    cin>>j;
    if(j==1)
        goto a_pay;
    if(j==2)
    {
        system("clear");
        return;
    }
    else
    {
        system("clear");
        cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
        goto choice;
    }
}

void removeEmployee()
{
    a_rmv:
    system("clear");
    string name;
    cout<<endl<<GREEN<< "\t\t Enter Employee Name: "<<RESET;
    cin.ignore();
    getline(cin,name);
    int flag=-1;
    node* temp=head;
    if(temp==NULL)
    {
        cout<<RED<< "\t\t No element is not present."<<RESET<<endl;
        return;

    }
    if(temp->term==name)
    {
        head=temp->next;
        cout<<BOLDRED<< "\t\t "<<name<< "'s details is deleted."<<RESET<<endl;
        c--;
        choice:
        cout<<BLUE<<endl<< "\t\t #1. Remove Another"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        int j;
        cin>>j;
        if(j==1)
            goto a_rmv;
        if(j==2)
        {
            system("clear");
            return;
        }
        else
        {
            system("clear");
            cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
            goto choice;
        }
    }

    while(temp->next->term!=name)
    {
        temp=temp->next;
        if(temp->next==NULL)
        {
            flag=0;
            break;
        }
    }
    if(flag==0)
    {
        cout<<BOLDRED<< "\t\t "<<name<< " is not present."<<RESET<<endl;
        choic:
        cout<<BLUE<<endl<< "\t\t #1. Remove Another"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        int j;
        cin>>j;
        if(j==1)
            goto a_rmv;
        if(j==2)
        {
            system("clear");
            return;
        }
        else
        {
            system("clear");
            cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
            goto choic;
        }
    }
    else
    {
        temp->next=temp->next->next;
        c--;
        cout<<BOLDRED<< "\t\t "<<name<< "'s details is deleted."<<RESET<<endl;
        choi:
        cout<<BLUE<<endl<< "\t\t #1. Remove Another"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        int j;
        cin>>j;
        if(j==1)
            goto a_rmv;
        if(j==2)
        {
            system("clear");
            return;
        }
        else
        {
            system("clear");
            cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
            goto choi;
        }
    }
}

void searchEmployee()
{
    a_search:
    system("clear");
    string name;
    cout<<endl<<GREEN<< "\t\t Enter Employee Name: "<<RESET;
    cin.ignore();
    getline(cin,name);
    int flag=-1;
    node* temp=head;
    if(temp==NULL)
    {
        system("clear");
        cout<<RED<< "\t\t No element is not present."<<RESET<<endl;
        return;

    }
    if(temp->next==NULL)
    {
        if(temp->term==name)
        {
            cout<<BOLDCYAN<< "\t\t Name:"<<RESET;
            cout<<temp->term<<endl;
            cout<<BOLDCYAN<< "\t\t Number:"<<RESET;
            cout<<temp->number<<endl;
            cout<<BOLDCYAN<< "\t\t Selary:"<<RESET;
            cout<<temp->earnings<<endl;
            cout<<BOLDCYAN<< "\t\t Paid:"<<RESET;
            cout<<temp->paid<<endl;
            cout<<BOLDCYAN<< "\t\t Payment date:"<<RESET;
            cout<<temp->dd<<"/";
            cout<<temp->mm<<"/";
            cout<<temp->yy<<endl;
            cout<<BOLDCYAN<< "\t\t Due:"<<RESET;
            cout<<temp->earnings-temp->paid<<endl;
            choic:
            cout<<BLUE<<endl<< "\t\t #1. Another Search"<<RESET<<endl;
            cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
            cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
            int j;
            cin>>j;
            if(j==1)
            goto a_search;
            if(j==2)
            {
                system("clear");
                return;
            }
            else
            {
                system("clear");
                cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                goto choic;
            }
            flag=0;
        }
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->term==name)
            {
                cout<<BOLDCYAN<< "\t\t Name:"<<RESET;
                cout<<temp->term<<endl;
                cout<<BOLDCYAN<< "\t\t Number:"<<RESET;
                cout<<temp->number<<endl;
                cout<<BOLDCYAN<< "\t\t Selary:"<<RESET;
                cout<<temp->earnings<<endl;
                cout<<BOLDCYAN<< "\t\t Paid:"<<RESET;
                cout<<temp->paid<<endl;
                cout<<BOLDCYAN<< "\t\t Payment date:"<<RESET;
                cout<<temp->dd<<"/";
                cout<<temp->mm<<"/";
                cout<<temp->yy<<endl;
                cout<<BOLDCYAN<< "\t\t Due:"<<RESET;
                cout<<temp->earnings-temp->paid<<endl;
                choice:
                cout<<BLUE<<endl<< "\t\t #1. Another Search"<<RESET<<endl;
                cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
                cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
                int j;
                cin>>j;
                if(j==1)
                    goto a_search;
                if(j==2)
                {
                    system("clear");
                    return;
                }
                else
                {
                    system("clear");
                    cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                    goto choice;
                }
                flag=0;
                break;
            }
            temp=temp->next;
        }
    }
    if(flag==-1)
    {
        cout<<RED<< "\t\t "<<name<< " is not present."<<RESET<<endl;
        choi:
        cout<<BLUE<<endl<< "\t\t #1. Another Search"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        int j;
        cin>>j;
        if(j==1)
        goto a_search;
        if(j==2)
        {
            system("clear");
            return;
        }
        else
        {
            system("clear");
            cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
            goto choi;
        }
    }
}

void addEmployee()
{
    again_add:
    system("clear");
    string name;
    int num;
    int salary;
    cout<<endl<<BLUE<< "\t\t Enter Employee Name: "<<RESET;
    cin.ignore();
    getline(cin,name);
    cout<<BLUE<< "\t\t Enter Employee Number: "<<RESET;
    cin>>num;
    cout<<BLUE<< "\t\t Enter Employee salary: "<<RESET;
    cin>>salary;
    node* n;
    n=new node(name,num,salary);
    node* temp=head;
    if(head==NULL)
    {
        head=n;
        c++;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        c++;
    }
    choice:
    cout<<BLUE<<endl<< "\t\t #1. Add Another Employee Details"<<RESET<<endl;
    cout<<BLUE<< "\t\t #2. Go To Admin Panel"<<RESET<<endl;
    cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
    int j;
    cin>>j;
    if(j==1)
        goto again_add;
    if(j==2)
    {
        system("clear");
        return;
    }
    else
    {
        system("clear");
        cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
        goto choice;
    }
}

void adminPanel()
{
    system("clear");
    admin:
    int n;
    do
    {
        cout<<endl<<BLUE<< "\t\t #1. Add A New Employee Details"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Remove An Employee Details"<<RESET<<endl;
        cout<<BLUE<< "\t\t #3. Add Pament Date & Amount"<<RESET<<endl;
        cout<<BLUE<< "\t\t #4. Search An Employee Details"<<RESET<<endl;
        cout<<BLUE<< "\t\t #5. All Employee Details"<<RESET<<endl;
        cout<<BLUE<< "\t\t #6. Go To Main Menu"<<RESET<<endl;
        cout<<BLUE<< "\t\t #7. Exit"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        cin>>n;

        switch(n)
        {
            case 1:
            {
                addEmployee();
                break;
            }
            case 2:
            {
                removeEmployee();
                break;
            }
            case 3:
            {
                addPament();
                break;
            }
            case 4:
            {
                searchEmployee();
                break;
            }
            case 5:
            {
                employeeDetails();
                break;
            }
            case 6:
            {
                system("clear");
                return;
            }
            case 7:
            {
                exit(0);
            }
            default:
            {
                cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                goto admin;
            }
        }
    }while(n<=7);
}

void deleteProduct()
{
    system("clear");
    nod* temp=top;
    if(temp->next==NULL)
    {
        top=NULL;
        cout<<RED<< "\t\t Deleted product is "<<temp->pname<<RESET<<endl;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->previous->next=NULL;
    cout<<RED<< "\t\t Deleted product is "<<temp->pname<<RESET<<endl;
    delete temp;
}

void addProduct()
{
    add_product:
    system("clear");
    string nam;
    int cost;
    nod* n;
    cout<<endl<<BLUE<< "\t\t Enter Product Name: "<<RESET;
    cin.ignore();
    getline(cin,nam);
    cout<<BLUE<< "\t\t Enter Product Price: "<<RESET;
    cin>>cost;
    n=new nod(nam,cost);
    nod* temp=top;
    if(top==NULL)
    {
        top=n;
        n->previous=top;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->previous=temp;
    }
    choice:
    cout<<BLUE<<endl<< "\t\t #1. Add Another Product"<<RESET<<endl;
    cout<<BLUE<< "\t\t #2. Remove The Last One"<<RESET<<endl;
    cout<<BLUE<< "\t\t #3. Go To Employee Panel"<<RESET<<endl;
    cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
    int j;
    cin>>j;
    if(j==1)
        goto add_product;
    if(j==2)
    {
        deleteProduct();
        goto choice;
    }
    if(j==3)
    {
        system("clear");
        return;
    }
    else
    {
        system("clear");
        cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
        goto choice;
    }
}

void listPrint()
{
    system("clear");
    nod* temp=top;
    if(temp==NULL)
    {
        cout<<RED<< "\t\t No product has been added."<<RESET<<endl;
        return;
    }
    int sum=0;

    cout<<BOLDCYAN<< "\t\t Name"<<RESET;
    cout<<BOLDCYAN<< "\t\t Price"<<RESET<<endl<<endl;
    while(temp!=NULL)
    {
        cout<< "\t\t "<<temp->pname;
        cout<< "\t\t "<<temp->price<<endl;
        sum=sum+temp->price;
        temp=temp->next;
    }
    cout<< "\t\t ------------------"<<endl;
    cout<<BOLDBLACK "\t\t Total=\t\t "<<sum<<RESET<<endl;
    choice:
    cout<<BLUE<<endl<< "\t\t #1. Go To Employee Panel"<<RESET<<endl;
    cout<<BLUE<< "\t\t #2. Exit"<<RESET<<endl;
    cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
    int j;
    cin>>j;
    if(j==1)
    {
        system("clear");
        return;
    }
    if(j==2)
        exit(0);
    else
    {
        system("clear");
        cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
        goto choice;
    }

}

void employeePanel()
{
    system("clear");
    employe:
    int n;
    do
    {
        cout<<endl<<BLUE<< "\t\t #1. Add a Product"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. Remove Last Product"<<RESET<<endl;
        cout<<BLUE<< "\t\t #3. See List"<<RESET<<endl;
        cout<<BLUE<< "\t\t #4. Go To Main Menu"<<RESET<<endl;
        cout<<BLUE<< "\t\t #5. Exit"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        cin>>n;

        switch(n)
        {
            case 1:
            {
                addProduct();
                break;
            }
            case 2:
            {
                deleteProduct();
                break;
            }
            case 3:
            {
                listPrint();
                break;
            }
            case 4:
            {
                system("clear");
                return;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                goto employe;
            }
        }
    }while(n<=5);
}

int main()
{
    system("clear");
    menue:
    int n;
    do
    {
        cout<<endl<<BLUE<< "\t\t #1. ADMIN PANEL"<<RESET<<endl;
        cout<<BLUE<< "\t\t #2. EMPLOYEE PANEL"<<RESET<<endl;
        cout<<BLUE<< "\t\t #3. Exit"<<RESET<<endl;
        cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
        cin>>n;

        switch(n)
        {
            case 1:
            {
                again_pass:
                int pass;
                cout<<GREEN<< "\t\t Enter Your Password: "<<RESET;
                cin>>pass;
                if(entry==pass)
                    adminPanel();
                else
                {
                    system("clear");
                    cout<<BOLDRED<< "\t\t Wrong Password"<<RESET<<endl;
                    choice:
                    cout<<endl<<BLUE<< "\t\t #1. Again Enter Password"<<RESET<<endl;
                    cout<<BLUE<< "\t\t #2. Main Menue"<<RESET<<endl;
                    cout<<MAGENTA<< "\t\t Enter Your Choice: "<<RESET;
                    int j;
                    cin>>j;
                    if(j==1)
                        goto again_pass;
                    if(j==2)
                        goto menue;
                    else
                    {
                        system("clear");
                        cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                        goto choice;
                    }
                }
                break;
            }
            case 2:
            {
                employeePanel();
                break;
            }
            case 3:
            {
                exit(0);
            }

            default:
            {
                cout<<RED<< "\t\t Invalid Input."<<RESET<<endl;
                goto menue;
            }
        }
    }while(n<=3);
}
