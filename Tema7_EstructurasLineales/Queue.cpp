#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T value;
    Node<T>* next;
    Node(){
		next = NULL; 
	}
	Node(T v){
		value=v;
		next=NULL;
	}
};

template<class T>
void printNormal(Node<T>* node)
{
    Node<T>* temp = node;
    while(temp != nullptr)
    {
        cout<< temp->value << ", ";
        temp = temp->next;
    }
	cout<<endl;
}

template<class T>
class Queue{
	protected:
		Node<T>* front;
		Node<T>* back;
	public:
		Queue(){
			front=NULL;
			back=NULL;
		}
		
		void insert(T value){
			Node<T>* toAdd=new Node<T>(value);
			insert(toAdd);
		}
		
		void insert(Node<T>* value){
			if(back==NULL&&front==NULL){
				front=value;
				back=value;
			}else{
				back->next=value;
				back=value;
			}
		}
		
	
		
		Node<T>* remove(){
			if(front==NULL){
				return NULL;
			}else{
				Node<T>* temp=front;
				front=front->next;
				return temp;
			}
		}
	
		void printQueue(){
			printNormal(front);
		}
};

int main(){
	Queue<int> q;
	q.insert(9);
	q.printQueue();
	q.insert(3);
	q.printQueue();
	q.insert(3);
	q.printQueue();
	q.insert(3);
	q.printQueue();
	Node<int>* toProcess=q.remove();
	cout<<"Processing "<<toProcess->value<<endl;
	delete toProcess;
	q.printQueue();
}

