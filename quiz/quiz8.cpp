#include <iostream>
using namespace std;

struct List
{
    /* data */
    string who;
    char data;
    List *link;
};


int main(void){
    
    int* p = new int(25);
    cout<< p << endl;
    cout<< *p << endl;
    cout<<endl;

    int* q=p;
    cout << *q << endl;
    cout<< q << endl;
    cout << *p << endl;
    cout<< p << endl;
    cout <<endl;

    *q=34;
    cout << *q << endl;
    cout<< q << endl;
    cout << *p << endl;
    cout<< p << endl;
    cout <<endl;


    delete p;
    cout << *q << endl;
    cout<< q << endl;
    cout << *p << endl;
    cout<< p << endl;
    cout <<endl;

    
    q=new int(56);
    cout << *q << endl;
    cout<< q << endl;
    cout << *p << endl;
    cout<< p << endl;
    cout <<endl;
    
    p=new int(78);
    cout << *q << endl;
    cout<< q << endl;
    cout << *p << endl;
    cout<< p << endl;
    cout <<endl;
    delete p;
    delete q;
    

   /*
   List a,b,c;
   List *q, *p, *r;

   p=&a; q=&b, r=&c;

   p->data='X'; q->data='Y', r->data='Z';
   p->link=q; q->link=r; r->link=nullptr;
   cout << p->data <<b.data << r->data<<endl;
   cout << q << ' ' << r << endl;
   cout << p->link <<' '<< q->link <<' '<< r->link << endl;
   */
}