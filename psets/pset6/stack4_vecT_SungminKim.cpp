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

template<typename T>
struct Stack{
    vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s) {delete s;}

template<typename T>
int size(stack<T> s) {return s->item.size();}

template<typename T>
bool empty(stack<T> s) {return s->item.empty();}

template<typename T>
void pop(stack<T> s) {
    s->item.pop_back();
    DPRINT(cout<<"\nstack status: size = " << s->item.size() << ", capacity = "<<s->item.capacity() <<endl);
}

template<typename T>
T top(stack<T> s){
    return s->item.back();
}

template<typename T>
void push(stack<T> s, T item){
    s->item.push_back(item);
    DPRINT(cout<<"\nstack status: size = " << s->item.size() << ", capacity = "<<s->item.capacity() <<endl);
}

template<typename T>
void printStack(stack<T> s){
    if(empty(s)) return;
    cout << top(s) <<' ';
    T temp = top(s);
    pop(s);
    printStack(s);
    push(s,temp);
}

template<typename T>
void printStack_fromBottom(stack<T> s){
    if(empty(s)) return;
    T temp=top(s);
    pop(s);
    printStack(s);
    push(s,temp);
    cout << top(s) << ' ';
}


int main(){
    
    int list[]={1,2,3,4,5,0,6,0,0,7,0,0,0,8}; int sen=0;
    //string list[]= {"to","be","or","not","to","-","be","-","-","that","-","-","-","is"}; string sen="-";

    stack<int> s = new Stack<int>;
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