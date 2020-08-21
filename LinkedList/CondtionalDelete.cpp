//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1

/*
Given a singly linked list, remove all the nodes which have a greater value on its next adjacent element.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on their next node. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of linked list <= 1000
1 <= element of linked list <= 1000
*/
Node *compute(Node *head)
{
    // your code goes here
    if(head->next == NULL) return head;
    
    Node *result = compute(head->next);
    
    if(head->data < result->data){
        head->next = NULL;
        free(head);
        return result;
    }
    else{
        head->next = result;
        return head;
    }
}
