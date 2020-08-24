/*
https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1

Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Input:
First line of input contains number of test cases T. Then T test cases follow.
In each test case, first line contains the number n, i.e. number of nodes in list 1 and second lines contains the n space separated values of the nodes.
Similarly, third line contains m, i.e. number of nodes in list 2 and fourth line of test case contains the data of m nodes of list 2.

Output:
The intersection list will be printed in a new line for each test case.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

User Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.

Constraints:
1 <= T <= 1000
1 <= n,m <= 103

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)

Example:
Input:
1
6
9 6 4 2 3 8
4
1 2 8 6
Output:
6 2 8
*/

Node* findIntersection(Node* head1, Node* head2)
{
    // code here
    // return the head of intersection list
    //create a hashmap for linked list 2
    unordered_map<int, bool> umap;
    while(head2){
        umap[head2->data] = true;
        head2 = head2->next;
    }
    
    //now go through first linked list and if i found common element 
    //add to new linked list
    Node* new_head = new Node(0);
    Node* curr = new_head;
    
    while(head1){
        if(umap.find(head1->data) != umap.end()){
            curr->next = new Node(head1->data);
            curr = curr->next;
        }
        head1 = head1->next;
    }
    curr = new_head;
    new_head = new_head->next;
    free(curr);
    return new_head;
}
