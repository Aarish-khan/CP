#include<iostream>
using namespace std;

struct Node{

	int data;
	struct Node *next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

//remove a partivular node from link list
void remove_node(struct Node  **head){
	struct Node *head_ref = *head;

	struct Node *head_ptr = head_ref->next;

	head_ref->next = NULL;
	free(head_ref);
	*head = head_ptr;

	
}
//reverse linked list using pointers
struct Node* reverse(struct Node* head){
    
    if(head==NULL) return head;
    
    Node *p,*q,*r;
    p = NULL;
    q = head;
    r = head->next;
    
    while(r){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    head = q;
    
    return head;
    
}

//a slight modification of reverse function
struct Node* reverse2(struct Node* head){

	if(head==NULL) return head;
	Node *p,*q,*r;
	p = NULL;
	q = head;
	r = head;
	while(r){
		r = r->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}

//reverse a linked list in groups of size k
struct Node* reverseGroup(struct Node* head, int k){

	if(head==NULL) return head;
	if(k==0) return head;

	//reverse first batch of k nodes or (less than k if nodes are less than k, for this condition i will
	//insert r != NULL condition in while loop)
	Node *p,*q,*r;
	p = NULL;
	q = head;
	r = head;
	int count = 0;
	while(r && count<k){
		r = r->next;
		q->next = p;
		p = q;
		q = r;
		count++;
	}

	//recurse rest n/k batches recusively
	Node* temp = reverseGroup(r,k);

	head->next = temp;
	
	return p;



}

//copy a linked list memory by memory
Node* simpleCopy(Node* head){
    if(head == NULL) return head;
    
    Node *new_head = new Node(head->data);
    Node* curr = new_head;
    head = head->next;
    while(head){
        curr->next = new Node(head->data);
        curr = curr->next;
        head = head->next;
    }
    
    return new_head;
}

//find the mid of linked list
Node* Mid(Node* head){
    Node* fast = head;
    Node* slow = head;
    
    while(fast && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main(){

	//create nodes of linked list
	Node *a = new Node(1);
	Node *b = new Node(2);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(5);
	Node *f = new Node(6);
	Node *g = new Node(7);
	
//linke the nodes to form linked list
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = g;
	Node* head = a;

	// remove_node(&head);


	// head = reverseGroup(head,2);
	// while(head){
	// 	cout<<head->data<<" ";
	// 	head = head->next;
	// }

	Node* h = Mid(head);
	cout<<h->data;




}
