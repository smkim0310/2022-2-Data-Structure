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
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
	vector<T> item;

	bool empty() const {
		return item.empty();
	}
	auto size() const {
		return item.size();
	}
	void push(T const& data) {
		item.push_back(data);
	}
	void pop() {
		if (item.empty())
			throw out_of_range("stack<>::pop(): pop stack");
		item.pop_back();
	}
	T top() const {
		if (item.empty())
			throw out_of_range("stack<>::top(): top stack");
		return item.back();
	}
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig) {
	stack<T> temp;
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

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	cout << "Unsupported operator encountered: " << op << endl;
	return 0;
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
		if (isspace(tokens[i]) || tokens[i] == '(') continue;
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
		} 
		else if (tokens[i] == ')') { // compute it, push the result to va_stack
			double result;
			result=compute(va_stack, op_stack);
			va_stack.push(result);
		}
		else { // token is an operator; push it to op_stack.
			op_stack.push(tokens[i]);
		}
	}

	if(!op_stack.empty()){
		double final=compute(va_stack,op_stack);
		va_stack.push(final);
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
