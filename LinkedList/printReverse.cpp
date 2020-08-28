//function to print element in reverse order using recursion
void recursive_reverse(struct Node* head){

	if(head == NULL) return;

	recursive_reverse(head->next);
	cout<<head->data<<" ";
}
