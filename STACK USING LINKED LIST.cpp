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
class stack{
	private:
		int size;
		Node* top;
	public:
		stack(): top(nullptr), size(0){}
		push(int data){
			Node* newnode = new Node(data);
			if(top){
				newnode->next = top;	
			}
			top = newnode;
			size++;
		}
		int pop(){
			if(isEmpty()){
				return -1;
			}
			Node* poppednode = top;
			top = top->next;
			int poppedvalue = poppednode->data;
			delete poppednode;
			size--;
			return poppedvalue;
		}
		bool isEmpty(){
			return size == 0;
		}
		int peek(){
			return top->data;
		}
		~stack(){
			while(top){
				Node* temp = top;
				top = top->next;
				delete temp;
			}
		}
};
int main(){
	stack mystack;
	cout<<"\t\t\t\tSTACKS\t\t\t\n";
	int choice = 0;
	while(choice != 4){
		cout<<"\nEnter 1 to push data in stack\nEnter 2 to pop an item in stack\nEnter 3 to check peek element\nEnter 4 to exit()>:  ";
		cin>>choice;
		if(choice == 1){
		 	int item;
			cout<<"\nEnter an element you want to push in stack: ";
			cin>>item;
			mystack.push(item);
			cout<<"Successfully pushed "<<item<<" in stack."<<endl;
		}else if(choice == 2){
			int check = mystack.pop();
			if(check != -1)
				cout<<"\nThe popped value is: "<<check<<endl;
			else
				cout<<"\nStack is empty."<<endl;
		}else if(choice == 3){
			int check = mystack.peek();
			if(check!=-1)
				cout<<"\nThe peek element of stack is: "<<check<<endl;
			else
				cout<<"\nStack is empty."<<endl;
		}else if(choice == 4){
			cout<<"\nThanks for using stacks."<<endl;
			return 0;
		}else{
			cout<<"\nOop\'s!!! You have entered a wrong choice."<<endl;
		}
	}
	
}