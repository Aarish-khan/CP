//https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1/?track=ppc-linkedlist&batchId=221
//NOTE: This is version of reverse in groups of k where k value is 2

/*
Pairwise swap elements of a linked list 
Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 2 1 4 2 6 5 8 7
Explanation: After swapping each pair
considering (1,2), (2, 4), (5, 6).. so
on as pairs, we get 2, 1, 4, 2, 6, 5,
8, 7 as a new linked list.
Your Task:
The task is to complete the function pairWiseSwap() which takes the head node as the only argument and returns the modified head.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
*/

struct Node *reverse (struct Node *head, int k)
{ 
    // Complete this method
    if(head==NULL||k==0) return head;
    
    
    //reverse the first batch of k nodes and rest recursion will take care
    Node* curr,*prev,*next;
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

Node* pairWiseSwap(struct Node* head) {
    head = reverse(head,2);
    
    return head;
}
