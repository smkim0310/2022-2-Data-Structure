//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
using namespace std;

int main(){
    /*
    int *pi;
    *pi=24;
    cout<<"i = "<<*pi<<endl;
    */
    //run-time error

    int* pi;

    pi=new int;

    *pi=24;
    cout<<"i = "<<*pi<<endl;
    
    delete pi;
    return 0;
}