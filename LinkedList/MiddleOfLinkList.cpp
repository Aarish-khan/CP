#include<iostream>
using namespace std;


struct node{

	int data;
	struct node* next;
};

struct node* insert_element(struct node *const head, int x){

	//first creat a node and store the element x in it
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	//fill the data x in node and set it's next pointer = null
	new_node-> data = x;
	new_node-> next = NULL;


	//check if link list is empty
	if(head == NULL)
		return new_node;

	//if execution comes here means link list is not emppty
	//so first go to the end of node and than link new_node

	//if we use our head pointer to traverse to end of node we'll lose starting address
	//of the node therefor we are taking a copy of it 
	struct node* head_ref = head;
	while(head_ref ->next != NULL)
		head_ref = head_ref->next;

	//linking the newly formed node to end 
	head_ref->next = new_node;
	
	return head;
}

void print_list(struct node *const head){

	struct node *head_ref = head;

	if(head == NULL)
		return;

	while(head_ref!=NULL){

		cout << head_ref-> data <<" ";
		head_ref  = head_ref->next;
	}

}

void find_middle(struct node *const head){

	struct node* head_ref = head;
	struct node* head_ref2 = head;

	//if linklist is empty just return as there is no midle
	if(head == NULL){
		cout <<"empty";
		return;
	}

	//case1: if linklist contains only  one element that itself is everything
	if(head->next == NULL){

		cout<< "middle = "<<head->data <<endl;
		return;
	}

	//case2: if linklist contains 2 nodes than return first
	if(head->next->next == NULL){

		cout << "middle = "<<head->data;
		return;
	}

	//If control comes here means link list contain more than 2 element
	//there might be a case where i am at second last node and doing head_ref->next->next will take me out of 
	//link list, So it is better to first chect if there exist two nodes, 
	// if there exist two nodes then jump by 2 steps otherwise come out of loop
	//so here we are doing that checking by "head_ref->next != NULL"-----means check aage node h?
	//if not NULL than aage node h
	//check again head_ref->next->next !=NULL -----means us se aage b node h kya?
	//if both statement are true means we can jump by two step otherwise no.
	while(head_ref2 -> next !=NULL && head_ref2 -> next ->next !=NULL){

		head_ref2 = head_ref2->next->next;
		head_ref = head_ref->next;
	}

	cout << "middle = "<<head_ref->data;
	return;
}

int main()
{	
	struct node* head = NULL;
	
	//inserting sample elements in link list
	for(int i=1; i<=10; i++){
		head = insert_element(head,i);
	}

	//print the linked list
	print_list(head);
	cout<<endl;
	//call the fuction that prints the value at middle
	find_middle(head);

}
