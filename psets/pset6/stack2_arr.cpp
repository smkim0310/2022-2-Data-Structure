//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
using namespace std;

struct Stack{
    string *item;
    int N;
    int capacity;
};
using stack = Stack*;

stack newStack(int capacity){
    stack s= new Stack;
    s->item=new string[capacity];
    s-> N=0;
    s->capacity=capacity;
    return s;
}

void free(stack s){
    delete[] s->item;
    delete s;
}

int size(stack s) {return s->N;}
bool empty(stack s) {return s->N==0;}
void pop(stack s) {s->N--;}
string top(stack s){
    return s->item[s->N-1];
}
void push(stack s, string item){
    s->item[s->N++] = item;
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

    stack s=newStack(sizeof(list)/sizeof(list[0]));
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