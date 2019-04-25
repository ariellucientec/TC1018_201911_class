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
    while(temp != NULL)
    {
        cout<< temp->value << " ";
        temp = temp->next;
    }
}

template<class T>
void recursivePrint(Node<T>* node)
{
    if(node == NULL)
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
        root = NULL;
    }

    void add(Node<T>* node)
    {
        if(root == NULL)
            root = node;
        else
        {
            Node<T>* temp = traverse(root);
            temp->next = node;
        }
    }
	
	void add(T value)
    {
        if(root == NULL)
            root = new Node<T>(value);
        else
        {
            Node<T>* temp = traverse(root);
            temp->next = new Node<T>(value);
        }
    }
	void insert(T value, int position){
		Node<T>* toAdd=new Node<T>(value);
		toAdd->next=NULL;
		insert(toAdd, position);
	}
	void insert(Node<T>* toAdd, int position){
		Node<T>* temp=root;
		if(position==0){
			toAdd->next=temp;
			root=toAdd;
			return;
		}
		for(int i=0; i<position-1; i++){
			if(temp->next==NULL){
				break;
			}else{
				temp=temp->next;
			}
		}
		toAdd->next=temp->next;
		temp->next=toAdd;
		
	}

	void remove(int position){
			Node<T>* temp=root;
			Node<T>* toDel;
			if(position==0){
				root=temp->next;
			}else{
				for(int i=0; i<position-1; i++){
					if(temp->next==NULL){
						return;
					}else{
						temp=temp->next;
					}
				}
			}
			toDel=temp->next;
			temp->next=temp->next->next;
			free(toDel);
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
	l.remove(3);
	l.printList();
	cout<<endl;
    return 0;
}
