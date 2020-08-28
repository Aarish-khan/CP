#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	string data;
	struct Node* lc;
	struct Node* rc;

	Node(string s){
		data = s;
		lc = nullptr;
		rc = nullptr;
	}

	bool has_left_child(){
		return lc!=nullptr;
	}

	bool has_right_child(){
		return rc!=nullptr;
	}
};

vector<string> BFS(struct Node *root){
	//#########################################
	//step 1: push the root into q

	//step 2
	//2.1 pop the node out from queue 
	//2.2 and mark it visited 
	//2.3 add it's children in queue

	//step 3: repeat step 3 untill q is empty
	//#########################################
	//declare a visited list array for storing the sequence of vsited nodes
	vector<string> visited_list;
	//keep a queue to make the nodes marked as visited
	queue<Node*> q;
	//A temporary node pointer need while processing tree
	struct Node *temp;

	//step 1: push the root in the queue
	q.push(root);

	//continue while the q is not empty
	while(!q.empty()){
		//pop the node out of q 
		temp = q.front();
		q.pop();

		//mark it visited and add it's content in visited_list
		visited_list.push_back(temp->data);

		//if this node has left and right child than add than to q
		if(temp->has_left_child())
			q.push(temp->lc);
		if(temp->has_right_child())
			q.push(temp->rc);
	}

	return visited_list;
}

int main()
{
	struct Node* root = new Node("apple");

	root->lc = new Node("banana");
	root->rc = new Node("mango");
	root->lc->lc = new Node("pink");
	root->lc->rc = new Node("blush");
	root->rc->lc = new Node("Berries");
	root->rc->rc = new Node("papaya");

	//  apple
	// /     \
  //   banana     mango
  //   /  \       /    \
  // pink  blush Berry  papaya

	//now my tree is ready lets proceed further with bfs;

	vector<string> visited_list = BFS(root);

	for(auto x: visited_list)
		cout<<x<<" ";
}
