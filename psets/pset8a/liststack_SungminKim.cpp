//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

// liststack.cpp
// This program implements a stack using singly-linked list
// without a head structure and without sentinel nodes. It simply links
// node to node. The caller is responsible for maintaining the the first
// node (head) of the list. Most functions need the first node to work
// with the list and returns the first node of the list since it may be
// changed inside of the functions.
//
// author: idebtor@gmail.com
#include "liststack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	Node* curr = p;
	while (curr != nullptr) {
		Node* zap = curr;
		curr = curr->next;
		delete zap;
	}
	cout << "\n\tCleared...\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;

	int count = 0;
	while(p!=nullptr){
		count++;
		p=p->next;
	}
	return count;
}

// sets the min and max values that are passed as references in the list
void minmax(pNode p, int& min, int& max) {
	if (empty(p)) {
		min = max = 0;
		return;
	}

	pNode curr=p;
	min=max=curr->data;
	for(;curr!=nullptr;curr=curr->next){
		if(curr->data<min) min=curr->data;
		if(curr->data>max) max=curr->data;
	}
	return;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode p, int val, int N) {
	DPRINT(cout << ">push val=" << val << " N="<< N << endl;);

	if(N==1) p = new Node{ val, p };
	else if(N>1){
		for(int i=0;i<N;i++){
			p=new Node{ val+i, p};
		}
	}

	DPRINT(cout << "<push size=" << size(p) << endl;);
	return p;
}

// removes N nodes in the list and returns the new first node.
// This deallocates the removed node, effectively reduces its size by N.
pNode pop(pNode p, int N) {
	DPRINT(cout << ">pop size=" << size(p) << " N="<< N << endl;);
	if (empty(p)) return nullptr;
	if(N>size(p)){
		clear(p);
		return nullptr;
	}
	
	if(N==1){
		pNode zap=p;
		p=zap->next;
		delete zap;
	}
	else{
		int i=0;
		while(i<N){
			pNode zap=p;
			p=zap->next;
			delete zap;
			i++;
		}
	}

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode p) {
	if (empty(p)) return nullptr;
	return p;
}

// shows all the list elements, show_n items per line  if all is true.
// shows the first and the last show_n items in the list if all is false.
void show(pNode p, bool all, int show_n) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}

	int i;
	pNode curr;
	const int N = size(p);
	cout << endl << "TOP ";
	if (all || N <= show_n * 2) {
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << "\t" << curr->data;
			if (i % show_n == 0) cout << endl;
		}
		return;
	}
	
	// print the first show_n items
	
	for(i=0,curr=p; i<show_n; i++){
		cout << "\t" << curr->data;
		curr=curr->next;
	}

	cout << "\n...left out...\n";

	// print the last show_n items
	// Firstly, move the pointer to the place where show_n items are left.
	curr=p;

	while(true){
		pNode temp;
		temp=curr;
		for(i=0;i<show_n;i++){
			curr=curr->next;
		}
		if(curr==nullptr){
			curr=temp;
			break;
		}
		else{
			curr=temp;
			curr=curr->next;
		}
	}

	for(i=0;i<show_n;i++){
		cout << "\t" << curr->data;
		curr=curr->next;
	}

	cout << endl;
}
