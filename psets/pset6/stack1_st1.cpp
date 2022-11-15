//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <stack>
using namespace std;

//normal ver
/*
void printStack(stack<string> s){
    stack<string> t;
    while(!s.empty()){
        cout<< s.top() << ' ';
        t.push(s.top());
        s.pop();
    }
    while(!t.empty()){
        s.push(t.top());
        t.pop();
    }
}
*/

//recursive ver
void printStack(stack<string> s){
    if(s.empty()) return;
    cout << s.top() <<' ';
    string temp = s.top();
    s.pop();
    printStack(s);
    s.push(temp);
}

//normal version
/*
void printStack_fromBottom(stack<string> s){
    stack<string> t;
    while(!s.empty()){
        t.push(s.top());
        s.pop();
    }
    while(!t.empty()){
        cout << t.top() << ' ';
        s.push(t.top());
        t.pop();
    }
}
*/

//recursive ver
void printStack_fromBottom(stack<string> s){
    if(s.empty()) return;
    string temp=s.top();
    s.pop();
    printStack(s);
    s.push(temp);
    cout << s.top() << ' ';
}

int main(){
    //int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8};
    string list[]= {"to","be","or","not","to","-","be","-","-","that","-","-","-","is"};

    stack<string> s;
    for(auto item: list){
        if(item!="-") s.push(item);
        else{
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize: " << s.size();
    cout << "\ntop: " << s.top();
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);
    cout << "\nHappy Coding" << endl;

}