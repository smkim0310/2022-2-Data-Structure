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

pair<char, int> get_op(string opstr) {
    char op;
    size_t x;
    do {
        cout << "Enter an operator( " << opstr << " ): " ;
        stringstream ss;
        string str;
        getline(cin, str);
        ss << str;
        ss >> op;
        x = opstr.find(op);
    } while (opstr.find(op) == string::npos);
    return pair<char, int>(op,x);
}

int main(){
    int (*calc[4])(int, int) = { add, sub, mul, dvd };
    string opstr { "+-*/" };

    int a { get_int()};
    pair<char, int> op { get_op(opstr)};
    int b { get_int()};

    cout << a << " " << op.first << " " << b << " = " << calc[op.second](a,b) << endl;
    return 0;
}