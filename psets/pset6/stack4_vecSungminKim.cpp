//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

struct Stack{
    vector<string> item;
};
using stack = Stack*;


void free(stack s) {delete s;}
int size(stack s) {return s->item.size();}
bool empty(stack s) {return s->item.empty();}

void pop(stack s) {
    s->item.pop_back();
    DPRINT(cout<<"\nstack status: size = " << s->item.size() << ", capacity = "<<s->item.capacity() <<endl);
}
string top(stack s){
    return s->item.back();
}
void push(stack s, string item){
    s->item.push_back(item);
    DPRINT(cout<<"\nstack status: size = " << s->item.size() << ", capacity = "<<s->item.capacity() <<endl);
}

void printStack(stack s){
    if(empty(s)) return;
    cout << top(s) <<' ';
    string temp = top(s);
    pop(s);
    printStack(s);
    push(s,temp);
}

void printStack_fromBottom(stack s){
    if(empty(s)) return;
    string temp=top(s);
    pop(s);
    printStack(s);
    push(s,temp);
    cout << top(s) << ' ';
}


int main(){
    //int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8}; int sen=0;
    string list[]= {"to","be","or","not","to","-","be","-","-","that","-","-","-","is"}; string sen="-";

    stack s = new Stack;
    for(auto item: list){
        if(item!=sen) push(s,item);
        else{
            cout << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nstack T: "; printStack(s);
    cout << "\nstack B: "; printStack_fromBottom(s);
    cout << "\nHappy Coding" << endl;

    free(s);
}