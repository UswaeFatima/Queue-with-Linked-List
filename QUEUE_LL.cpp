#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class Queue{
	private:
		Node* front;
		Node* rear;
	public:
	Queue() {
        front = NULL;
        rear = NULL;
    }
    
    bool isEmpty(){
    	return front == NULL;
	}
    
	void inQueue(int t_data){
		Node* new_node = new Node;
		new_node->data = t_data;
		new_node->next = NULL; 
		if(isEmpty())
		{
			front = new_node;
			rear = new_node;
			return;
		}
		rear->next = new_node;
		rear = new_node;
	}	
	
	void deQueue(){
		if(isEmpty())
		{
			cout<<"Queue is Empty."<<endl;
			return;
		}
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	
	void print(){
		if(isEmpty())
		{
			cout<<"Queue is Empty."<<endl;
			return;
		}
		Node* curr = front;
		while(curr != NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}
};
int main()
{
	Queue q;
	cout<<q.isEmpty()<<endl;
	q.inQueue(10);
	q.inQueue(20);
	q.inQueue(30);
	q.print();
	q.deQueue();
	q.deQueue();
	q.print();
	q.deQueue();
	q.print();
	return 0;
}
