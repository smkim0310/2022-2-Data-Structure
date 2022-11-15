//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(true){
        cout << "Enter a name: ";
        getline(cin,str);
        if(str.length()>0)
            cout << "Hello "<<str<<"!\n";
        else break;
    }
    cout << "Hello World!\n";
    return EXIT_SUCCESS;
}