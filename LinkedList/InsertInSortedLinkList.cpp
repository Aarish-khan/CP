/*
//https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

Given a sorted singly linked list and a data, your task is to insert the data in the linked list in a sorted way i.e. order of the list doesn't change.

Example 1:

Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 19 25 36 47 58 69 80
Example 2:

Input:
LinkedList: 50->100
data: 75
Output: 50 75 100
Your Task:
The task is to complete the function sortedInsert() which should insert the element in sorted Linked List and return the head of the linked list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
-99999 <= A[i] <= 99999, for each valid i
*/
Node *sortedInsert(struct Node* head, int data) {
    
    //first create a node with data
    Node *new_node = new Node(data);
    
    // //edge case : when link list is empty
    if(head == NULL) return new_node;
    
    //edge case: when insert position is just before head itself
    if(data <= head->data){
        new_node -> next = head;
        head = new_node;
        return head;
    }
    
    Node *pos = head;
    Node *curr = head;
    while(curr && data>curr->data){
        pos = curr;
        curr = curr->next;
    }
    pos->next = new_node;
    new_node->next = curr;
    
    return head; 
}
