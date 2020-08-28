//a step by step walkthrough of bfs algorithm

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

//pogress report
void display_progress(vector<string> visited_list, queue<Node*> q){
	//diplay the content of visited list after each  iteration
	cout<<"visied list is ";
	for(auto x:visited_list)
		cout<<x<<" ";
	cout<<endl;
	//diplay progress ends
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

	//declare a visited list array for storing the sequence of vsited nodes
	vector<string> visited_list;
	//keep a queue to make the nodes marked as visited
	queue<Node*> q;


	//step 1: push the root in the queue
	q.push(root);


	//step 2 
	//2.1 pop the node out from queue 
	//2.2 and mark it visited 
	//2.3 add it's children in queue
	Node *temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);


	display_progress(visited_list,q);


	//step 3: repeate step 2 untill empty q

	//2.1 pop the node out from queue 
	//2.2 and mark it visited 
	//2.3 add it's children in queue
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);



	//step 4: repeat step 2
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);


	//step 5: repeat step 2
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);


	//step 6: repeat step 2
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);


	//step 4: repeat step 2
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);


	//step 4: repeat step 2
	temp = q.front();
	q.pop();
	visited_list.push_back(temp->data);
	//adding it's children in queue
	if(temp->has_left_child())
		q.push(temp->lc);
	if(temp->has_right_child())
		q.push(temp->rc);

	display_progress(visited_list,q);


}
