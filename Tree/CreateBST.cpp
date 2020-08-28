//write a program to create a binary search tree
//Note: this is a class based implementation

#include<iostream>
using namespace std;

//structure of the node
struct Node{
	int data;
	Node* lc;
	Node* rc;

	Node(int x){
		data = x;
		lc = nullptr;
		rc = nullptr;
	}
};
//class structure and it;s functions
class BST{
private:
	struct Node* root;
public:
	BST(){
		root = nullptr;
	}

	BST(int x){
		root = new Node(x);
	}


	Node* getRoot(){
		return root;
	}



	void insert(int x){

		//create a tree node
		Node* temp = new Node(x);

		//check if bst is empty or not
		if(root==nullptr){
			root = temp;
		}

		else
		{
			Node* curr = root;
			Node *parent;
			while(curr){
				parent = curr;
				if(x>curr->data){
					curr = curr->rc;
				}
				else{
					curr = curr->lc;
				}

			}
			if(x>parent->data)
				parent->rc = temp;
			else
				parent->lc = temp;
		}
	}


	void display(){
		print(root);
	}



	void print(Node* root){
		Node* curr = root;
		if(curr == nullptr) return;
		
		print(root->lc);

		cout<<curr->data<<" ";
		
		print(root->rc);
	}
};

int main(){

	BST tree = BST();
	tree.insert(15);
	tree.insert(18);
	tree.insert(11);
	tree.insert(10);
	tree.insert(20);
	tree.insert(17);
	tree.display();
}
