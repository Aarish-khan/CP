//write a program to find the address of second last node in linklist

#include<iostream>
using namespace std;

struct node{

	int data;
	struct node *next;
};

//a function to insert elements in the linked list
struct node* insert(struct node *const head, int x);
void find(struct node *const head, int x);
void print_list(struct node *const head);


int main(){

	//initially the link list is empty, 
	//creating empty link list
	//initially null
	struct node *head = NULL;
	//creating a head reference so that i don't lose head pointer
	//struct node *head_ref = head;


	int choice, temp;

	//creating a stopping condition for while loop
	bool not_exit = true;
	
	//continue while user not_exit
	while(not_exit)
	{
		cout << "\t\t\t*************************\n";
		cout << "\t\t\t*  enter your choice:   *\n  ";
		cout << "\t\t\t*************************\n";

		cout <<"\t\t\t1.Insert \n";
		cout <<"\t\t\t2.find \n";
		cout <<"\t\t\t3.print list\n";
		cout <<"\t\t\t4.EXIT\n";
		cin >> choice;




		switch(choice)
		{
			case 1:
			{
				cout << "\nenter the element you want to insert: ";
				cin >> temp;
				head = insert(head,temp);
				cout << temp <<" inserted.\n\n";
				break;
			}

			case 2:
			{
				cout << "enter element you want to find in list: ";
				cin >> temp;
				find(head,temp);
				break;
			}
			case 3:{
				print_list(head);
				break;
			}
			case 4:{

				not_exit = false;
				break;
			}
			default:{

				cout <<"please make valid choice.\n";
			}
		}

	}

}


struct node* insert(struct node* const head, int x){

		//first of all create a node
		struct node *new_node = (struct node *)malloc(sizeof(struct node));

		//setting values in the newly created node
		new_node->data = x;
		new_node->next = NULL;


		//link the node with already existing link list
		//case 0: check if link is empty
		if(head == NULL)
			return new_node;

		//since we need to go to last of link list to link newly formed node
		//therefor we will travverse the link list, and if we use head pointer to traverse
		//then we will lose it, therefor creat a new pointer and assign it equal to head
		//then traverse using this pointer.
		struct node *traverse = head;

		while(traverse->next != NULL)
			traverse = traverse->next;

		traverse->next = new_node;

		return head;
	}


void print_list(struct node *const head){

	//creating a head ref so that head don't change, 
	//moreover changing head will give error coz head is constant pointer
	struct node *head_ref = head;
	cout << "the element of linked list are : ";
	while(head_ref!=NULL)
	{
		cout << head_ref->data <<" ";
		head_ref = head_ref->next;
	}
	cout <<"\n\n";


}

void find(struct node *const head, int x){

	//check the boundary condition
	//if head is null e.g link list is empty
	// if(head == NULL)
	// 	cout << "value not found\n";

	//now, that means link list contains atleast one node
	//now creating a new pointer to traverse link list
	struct node *traverse = head;
	bool found = false;

	while(traverse!=NULL){

		if(traverse->data == x){
			found = true;
			break;
		}

		traverse = traverse->next;
	}

	if(found)
		cout << "value found at address: "<<traverse<<"\n\n";
	else
		cout << "value not found.\n\n";

}
