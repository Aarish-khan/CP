/*
https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 

Note: C is the position of the node to which the last node is connected. If it is 0 then no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
C = 2
Output: 1
Explanation: In the first test case
N = 3.The linked list with nodes
N = 3 is given. Here, x = 2 which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop. 

Example 2:
Input:
N = 4
value[] = {1,8,3,4}
C = 0
Output: 1
Explanation: N = 4 and x = 0, which
means lastNode->next = NULL, thus
the Linked list does not contains
any loop.
Your Task:
Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the linked list. Simply remove the loop in the list (if present) without disconnecting any nodes from the list. The driver code will print 1 if your code is correct.

Expected time complexity : O(n)

Expected auxiliary space : O(1)

Constraints:
1 <= N <= 104
*/
Node *meetingPoint(Node *head){
    Node* hare = head, *tortoise = head;
    
    while(hare && hare->next){
        hare = hare->next->next;
        tortoise = tortoise->next;
        if(hare == tortoise)
            return hare;
    }
    return NULL;
}

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    
    
    //step 1: first get the node where hare and tortoise meet
    Node *meetAt = meetingPoint(head);
    
    //speciall case 1: if meetAt is null means they never meet
    //imply there is no cycle, so simply return here itself
    if(meetAt==NULL) return;
    
    //step 2:assign the slow pointer back to head and proceed
    //with both fronts e.g slow and fast untill they meet
    Node *slow = head;
    Node *fast = meetAt;
    
    //special case 2: when all linked list is a cycle e.g last node 
    //pointing back to first
    if(slow == fast){
        while(slow->next != fast){
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }
    
    //step 3:  proceed with step 2 things 
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return;   
}
