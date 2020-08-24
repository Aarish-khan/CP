/*
https://practice.geeksforgeeks.org/problems/delete-keys-in-a-linked-list/1

Given a single linked list and an integer x. Your task is to complete the function deleteAllOccurances() which deletes all occurences of a key x present in the linked list. The function takes two arguments: the head of the linked list and an integer x. The function should

Example 1:

Input:
LinkedList = 2->2->1->4->4
x = 4
Output: 2 2 1 
Example 2:

Input:
LinkedList = 1->2->2->3->2->3
x = 2
Output: 1 3 3
Explanation: Given number to delete is 2.
After deleting all occurrences of 2, we
have elements in the list as 1, 3, and 3.
 

Your Task:
The task is to complete the function deleteAllOccurances() which should delete all the occurrences of given number x from the list and return the head of the modified linked list.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= size of the linkedlist <= 100
1 <= x <= N
*/
Node* deleteAllOccurances(Node *head,int x)
{
    //Add a dummy node at the begging of linked list
    //to avoid special case when we need to remove first node of 
    //link list in case first node is x
    Node *dummy = new Node(x+1);
    dummy->next = head;
    head = dummy;
    
    Node *curr = head;
    Node* frnd = NULL;
    
    while(curr){
        if(curr->data == x){
            frnd->next = curr->next;
            
        }
        else{
            frnd = curr;
        }
        
        curr = curr->next;
    }
    return head->next;
}
