//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4
Your Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)
*/

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    if(head==NULL||k==0) return head;
    
    
    //reverse the first batch of k nodes and rest recursion will take care
    node* curr,*prev,*next;
    prev = NULL;
    next = curr = head;
    int count = 0;
    while(next && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //recursively call fun to reverse all batches of k
    head->next = reverse(next,k);
    return prev;
}
