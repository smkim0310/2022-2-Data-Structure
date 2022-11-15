//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <sstream>
using namespace std;

int add(int a, int b) { return a+b; }
int sub(int a, int b) { return a-b; }
int mul(int a, int b) { return a*b; }
int dvd(int a, int b) { if(b!=0) return a/b; else return 0; }

int get_int(){
    int x;
    do {
        cout << "Enter an integer: ";
        string str;
        getline(cin, str);
        try{
            x=stoi(str);
            break;
        }
        catch (invalid_argument& e){
            cerr << e.what() << " error occurred. Retry~" <<endl;
        }
    } while(true);
    return x;
}

char get_op(string opstr) {
    char op;
    do {
        stringstream ss;
        string str;
        cout << "Enter an operator( " << opstr << " ): " ;
        getline(cin, str);
        ss << str;
        ss >> op;
    }while (opstr.find(op) == string::npos);
    return op;
}

int main(){
    int a { get_int()};
    char op { get_op("+-*/")};
    int b { get_int()};

    int (*calc)(int, int);
    switch(op){
        case '+':
            calc=add;
            break;
        case '-':
            calc=sub;
            break;
        case '*':
            calc=mul;
            break;
        case '/':
            calc=dvd;
            break;
        default: break;
    }
    cout << a << " " << op << " " << b << " = " << calc(a,b) << endl;
    return 0;
}