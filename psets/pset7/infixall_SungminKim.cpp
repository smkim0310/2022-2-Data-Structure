//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05	created and assert() added
//
#include <iostream>
#include <cassert>
#include <stack>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

template <typename T>
void printStack(stack<T> orig) {
	if(orig.empty()) return;
	cout << orig.top() <<' ';
   	T temp = orig.top();
    orig.pop();
    printStack(orig);
    orig.push(temp);
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a,b);
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
}

int precedence(char op){
	if(op=='^') return 2;
	else if(op=='*'||op=='/') return 1;
	else return 0;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
	double right  = va_stack.top(); va_stack.pop();     
	double left = va_stack.top(); va_stack.pop();
	char op = op_stack.top(); op_stack.pop();
	double value = apply_op(left, right, op);

	DPRINT(cout << " va/op_stack.pop: " << value << endl;);
	return value;
}

// returns value of expression after evaluation.
double evaluate(string tokens) {
	DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
	stack<double>  va_stack;              // stack to store operands or values
	stack<char> op_stack;                 // stack to store operators.
	double value = 0;

	for (size_t i = 0; i < tokens.length(); i++) {
		// token is a whitespace or an opening brace, skip it.
		if (isspace(tokens[i])) continue;
		DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

		// current token is a value(or operand), push it to va_stack.
		if (isdigit(tokens[i])) {
			int ivalue = 0;
			string temp;
			while(true){
				temp.push_back(tokens[i]);
				i++;
				if(tokens[i]-'0'<0||tokens[i]-'0'>9) break;
			}
			i--;
			ivalue=stod(temp);
			va_stack.push(ivalue);
			DPRINT(printStack(op_stack););
			DPRINT(printStack(va_stack););
		} 
		else if (tokens[i] == ')') { // compute it, push the result to va_stack
			double result;
			while(op_stack.top()!='('){
				result=compute(va_stack, op_stack);
				va_stack.push(result);
				DPRINT(printStack(op_stack););
				DPRINT(printStack(va_stack););
			}
			op_stack.pop();
			DPRINT(printStack(op_stack););
			DPRINT(printStack(va_stack););
		}
		else { // token is an operator; push it to op_stack.
			if(op_stack.empty()||tokens[i]=='(') op_stack.push(tokens[i]);
			else{
				char prevOp;
				double result;
				
				while(!op_stack.empty()&&op_stack.top()!='('){
					prevOp=op_stack.top();
					if(precedence(tokens[i])<=precedence(prevOp)){
						result=compute(va_stack,op_stack);
						va_stack.push(result);
					}
					else break;
				}
				op_stack.push(tokens[i]);
				
			}
		}
	}

	while(!op_stack.empty()){
		double final=compute(va_stack,op_stack);
		va_stack.push(final);
		DPRINT(printStack(op_stack););
		DPRINT(printStack(va_stack););
	}

	DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
	DPRINT(cout << "va_stack size: " << va_stack.size() <<endl;);
	DPRINT(printStack(va_stack);  cout << endl;);
	DPRINT(cout << "op_stack size: " << op_stack.size() <<endl;);
	DPRINT(printStack(op_stack);  cout << endl;);
	
	
	assert(op_stack.empty());

	assert(va_stack.size()==1);

	value=va_stack.top();

	return value;
}

