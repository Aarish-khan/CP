/*
link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.


Example 1:

Input:
LinkList1 = {10,20,5,10}
LinkList2 = {30,40,50,5,10}
Output: 5
Explanation:The point of intersection of
two linked list is 5, means both of them
get linked (intersects) with each other
at node whose value is 5.
Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it should return -1.

Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 100
1 <= value <= 1000
*/
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   
   
int intersectPoint(Node* head1, Node* head2)
{
    // edge case: when one or both of the link list are empty than
    //there exist no intersection point thus return -1
    if(head1==NULL ||head2==NULL) return -1;
    //find the length of first linked list
    int len1 = 0;
    Node *head_ref = head1;
    while(head_ref){
        ++len1;
        head_ref = head_ref->next;
    }
    
    //find the length of second linklist
    int len2 = 0;
    head_ref = head2;
    while(head_ref){
        ++len2;
        head_ref = head_ref->next;
    }
    
    int diff = abs(len1 - len2);
    
    //traverse bigger link list by diff amount
    if(len1>=len2){
        for(int i=0; i<diff; i++){
            head1 = head1->next;
        }
    }
    
    else{
        for(int i=0; i<diff; i++){
            head2 = head2->next;
        }
    }
    
    //now traverse both link list and keep a tab where the address
    //of both the node is same
    while(head1 != head2 && head1 && head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if(head1==head2) return head1->data;
    
    return -1;
    
}

