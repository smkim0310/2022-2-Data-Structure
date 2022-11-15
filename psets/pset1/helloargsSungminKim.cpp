//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    string str;
    for(int i=1;i<argc;i++){
        cout << "Hello "<<argv[i]<<"!\n";
    }
    cout << "Hello World!\n";
    return EXIT_SUCCESS;
}