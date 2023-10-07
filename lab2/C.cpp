#include <bits/stdc++.h>
using namespace std;
struct node{
	int value;
	node* next;
	node(int value){
		this->value = value;
		this->next = NULL;
	}
};
struct LinkedList{
	int size = 0;
	node* head, * tail;
	LinkedList(){
		this->head = NULL;
		this->tail = NULL;
	}
	void add(int value){
		size++;
		node* newnode = new node(value);
		if(!head){
			head = tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
	}
	void print(){
		node* current = head;
		while(current != 0){
			cout << current->value << ' ';
			current = current->next;
		}
	}
	void solution(){
		node* current = head;
		for(int i=0; i<size; i++){
			if(i%2==0){
				cout << current->value << ' ';
			}
			current = current->next;
		}
	}
};
int main(){
	int n;
	cin >> n;
	int d;
	LinkedList l;
	for(int i=0;i<n;i++){
		cin >> d;
		l.add(d);
	}
	l.solution();
}