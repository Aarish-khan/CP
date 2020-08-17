/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,]
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105
*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    //edge case 1: head_A is empty than simply return head_B
    if(head_A==NULL) return head_B;
    if(head_B == NULL) return head_A;
    
    //create a sorting pointer that traces the sorted list
    Node *sorting;
    if(head_A->data > head_B->data){
        sorting = head_B;
        head_B = head_B->next;
    }
    else{
        sorting = head_A;
        head_A = head_A->next;
    }
    //since now we have starting of sorted linked list
    //we will store this becdause we will change sorting 
    //in the process
    Node* head = sorting;
    
    while(head_A && head_B){
        
        if(head_A->data > head_B->data){
            sorting->next = head_B;
            sorting = head_B;
            head_B = head_B->next;
        }
        else{
            sorting->next = head_A;
            sorting = head_A;
            head_A = head_A->next;
        }
    }
    
    if(head_A==NULL){
        sorting->next = head_B;
    }
    else{
        sorting->next = head_A;
    }
    
    return head; 
}  
