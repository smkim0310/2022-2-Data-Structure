//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)
		cout << "Hello " << names[i] << "!" << endl;
}
void printfunc(vector<string> names){
	for(auto i: names){
		cout <<"Hello " << i << "!" <<endl;
	}
}

