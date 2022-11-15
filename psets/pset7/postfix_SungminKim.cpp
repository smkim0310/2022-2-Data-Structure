//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom. 
void printStack(stack<string> orig) {
	stack<string> temp;
	while(!orig.empty()){
		cout<<orig.top()<< ' ';
		temp.push(orig.top());
		orig.pop();
	}
	while(!temp.empty()){
		orig.push(temp.top());
		temp.pop();
	}
}

void printStack(stack<double> orig) {
	stack<double> temp;
	while(!orig.empty()){
		cout<<orig.top()<< ' ';
		temp.push(orig.top());
		orig.pop();
	}
	while(!temp.empty()){
		orig.push(temp.top());
		temp.pop();
	}
}


// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;
	string result;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a value(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			assert(st.size()>=2);
			string t2=st.top();
			st.pop();
			string t1=st.top();
			st.pop();
			string tok; tok.push_back(token);
			result="("+t1+" "+tok+" "+t2+")";
			st.push(result);
		}

		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
			string temp;
			temp.push_back(token);
			st.push(temp);
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);
	DPRINT(cout << "stack size: " << st.size() <<endl;);

	assert(st.size()==1);
	result=st.top();

	DPRINT(cout << "<evaluate() returns " << result << endl;);
	return result;
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {
	for(char token: tokens){
		if(token<58&&token>47) continue;
		else{
			if(token==32||token==42||token==43||token==45||token==47) continue;
			else return false;
		}
	}
	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;
	double result;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			// checking the stack top() for right operand 
			// checking the stack top() for left oprand 
			// compute the expression and push the result

			double t2=st.top();
			st.pop();
			double t1=st.top();
			st.pop();
			switch (token){
				case /* constant-expression */'+':
					/* code */
					result=t1+t2;
					break;
				case /* constant-expression */'-':
					/* code */
					result=t1-t2;
					break;
				case /* constant-expression */'*':
					/* code */
					result=t1*t2;
					break;
				case /* constant-expression */'/':
					/* code */
					result=t1/t2;
					break;
				default:
					break;
			}

			st.push(result);
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack

			string temp;
			temp.push_back(token);
			double tok=stod(temp);
			st.push(tok);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
	DPRINT(cout << "stack size: " << st.size() <<endl;);
	DPRINT(printStack(st););

	assert(st.size()==1);
	result=st.top();

	DPRINT(cout << "<evaluate() returns " << result << endl;);
	return result;
}
