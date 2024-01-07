#include<bits/stdc++.h>
#include <conio.h>
using namespace std;



int num = 0;
struct Book {
    std::string name;
    int id;
    std::string auth;
    int status;
}book[100];


class Operatrion
{
public:
    void add_books();
    void borrow_books();
    void return_books();
    void view_books();
};



void Operatrion::add_books()
{
    cin.ignore();
    // Book b;
    string name ;
    int n ;
    string auth;
    cout <<" please enter name of book , id and author name : ";
    cin>>name>>n;
    cin>>auth;
    book[num].name = name; 
    book[num].auth = auth;
    book[num].id = n;
    book[num].status = 0;  // not borrowed yet
    system("cls");
    cout<<"Book Added";
    num++;
}

void Operatrion::borrow_books()
{
    string name ;
    cout<<"Enter the name of book : ";
    cin>>name;
    for(int i =0;i<num;i++)
    {
        string book_to_find = book[i].name;
        int is_status = book[i].status;
        if(book_to_find==name && is_status == 0)
        {
            system("cls");
            cout<<"Here is your book : "<<name<<" id number : "<<book[i].id<<endl;
            book[i].status=1;
        }
        else{
            cout<<"Sorry book unavailable at this moment"<<endl;
        }
    }
}

void Operatrion::return_books()
{
    string name ;
    int id ;
    system("cls");
    cout<<"Enter id and name of Book : "<<endl;
    cin>>id;
    cin>>name;
    int is_found = 0;
    for(int i =0;i<num;i++)
    {
        string book_to_fill = book[i].name;
        int is_status = book[i].status;
        if(book_to_fill == name && is_status==1)
        {
            cout<<"Thanks for returning the book!!"<<endl;
            book[i].status = 0;
            is_found = 1;
        }
    }
    if(is_found == 0)
    {
        system("cls");
        cout<<"No book record found!! Please add the book first"<<endl;
    }
}


void Operatrion::view_books()
{
    system("cls");
    cout<<"*******Book collection**********\n\n"<<endl;
    for(int i = 0;i<num;i++)
    {
        cout<<"ID-> "<<book[i].id<<", Book name-> "<<book[i].name<<", Author-> "<<book[i].auth<<", Status-> "<<book[i].status<<endl;
    }
}

void main_gate()
{
    cout<<"************BOOK STORE***************"<<endl;
    cout<<"1.Add Book"<<endl;
    cout<<"2.Borrow Books"<<endl;
    cout<<"3.Return Books"<<endl;
    cout<<"4.View Books"<<endl;
    cout<<"5.Exit"<<endl;
    int ch ;
    cin>>ch;

    Operatrion operation; 
    switch(ch)
    {
        case 1 :
            system("cls");
            operation.add_books();
            getch();
            break;
        case 2 :
            system("cls");
            operation.borrow_books();
            getch();
            break;
        case 3 :
            system("cls");
            operation.return_books();
            getch();
            break;
        case 4 :
            system("cls");
            operation.view_books();
            getch();
            break;
        case 5 :
        system("cls");
        exit(0);
            break;
        default:
            system("cls");
            cout<<"Service not available"<<endl;
            main_gate();
            getch();
            break;
    }

}






int main() {
    
    int n ;
    cout<<"Enter 1 to enter and 0 to exit";
    cin>>n;
    
    while(1)
    {
        system("cls");
        if(n==1)
        main_gate();
        else{
            cout<<"Ok Have nice day!!";
            
            break;
        }
    }
   getch();

    return 0;
}
