#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T value;
    Node<T>* next;
    Node(){
		next = nullptr; 
	}
	Node(T v){
		value=v;
		next=nullptr;
	}
    
};
template<class T>
void printNormal(Node<T>* node)
{
    Node<T>* temp = node;
    while(temp != nullptr)
    {
        cout<< temp->value << " ";
        temp = temp->next;
    }
}

template<class T>
void recursivePrint(Node<T>* node)
{
    if(node == nullptr)
        return; 
    else
    {
        cout << node->value<<",";
        return recursivePrint(node->next);
    }
}

template<class T>
class LinkedList
{
protected:
    Node<T>* root;
public:
    LinkedList()
    {
        root = nullptr;
    }

    void add(Node<T>* node)
    {
        if(root == nullptr)
            root = node;
        else
        {
            Node<T>* temp = traverse(root);
            temp->next = node;
        }
    }
	
	void add(T value)
    {
        if(root == nullptr)
            root = new Node<T>(value);
        else
        {
            Node<T>* temp = traverse(root);
            temp->next = new Node<T>(value);
        }
    }
	
	void insert(T value, int position){
		Node<T>* toAdd=new Node<T>(value);
		Node<T>* temp=root;
		if(position==0){
			toAdd->next=temp;
			root=toAdd;
			return;
		}
		for(int i=0; i<position-1; i++){
			if(temp->next==nullptr){
				break;
			}else{
				temp=temp->next;
			}
		}
		toAdd->next=temp->next;
		temp->next=toAdd;
		
	}

    Node<T>* traverse(Node<T>* node)
    {
        if(node->next == nullptr)
            return node;
        else
            return traverse(node->next);
    }
	
	void printList(){
		recursivePrint(root);
	}

};

int main()
{
    /*Node<char>* node =new Node<char>();  // esto se crea en el heap
    node->value = 33;
    Node<char>* nodeEight = new Node<char>();
    nodeEight->value = 34;
    node->next = nodeEight;
    Node<char>* nodeNine = new Node<char>();
    nodeNine->value = 35;
    nodeEight->next = nodeNine;
    recursivePrint(node);*/
	LinkedList<int> l;
	l.add(5);
	l.add(4);
	l.add(10);
	l.printList();
	cout<<endl;
	l.insert(6, 10000);
	l.printList();
	cout<<endl;
    return 0;
}