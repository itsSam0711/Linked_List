#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;	
	Node(int data){
		this->data = data;
		this->next = nullptr;
	}
};
int main(){
	Node* head = new Node(12);
	Node* node2 = new Node(23);
	Node* node3 = new Node(32);
	Node* node4 = new Node(34);
	
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	// finding the lowest.
	Node* current = head;
	int lowestvalue = head->data;
	while(current!=nullptr){
		if(current->data < lowestvalue){
			lowestvalue = current->data;
		}
		current = current->next;			
	}
	cout<<"The smallest value is: "<<lowestvalue<<endl;
	
	cout<<"Linked List Data: ";
	current = head;
	while(current!= nullptr){
		cout<<current->data<<" ";
		current = current->next;
	}
	
	current = head;
	while(current!= nullptr){
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	return 0;
}
