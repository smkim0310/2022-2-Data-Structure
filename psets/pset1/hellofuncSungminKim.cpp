//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <string>
using namespace std;
void printfunc(int n, char *names[]);

int main(int argc, char *argv[]){
    string str;
    if(argc>1) printfunc(argc-1,&argv[1]);
    else{
        while(true){
        cout << "Enter a name: ";
        getline(cin,str);
        if(str.length()>0)
            cout << "Hello "<<str<<"!\n";
        else break;
        }
    }
    cout << "Hello World!\n";
    
    return EXIT_SUCCESS;
}