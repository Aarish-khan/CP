/*
https://practice.geeksforgeeks.org/problems/remove-every-kth-node/1/?track=ppc-linkedlist&batchId=221

Given a singly linked list, your task is to remove every kth node from the linked list.

Input:
The first line of input contains number of test cases T. Then T test cases follow. Every test case contains 3 lines. First line of every test case contains an integer N denoting the size of the linked list . The second line contains N space separated values of the linked list. The third line contains an integer K.

Output:
Output for each test case will be space separated values of the nodes of the new transformed linked list.

User Task:
The task is to complete the function deleteK() which should delete every kth nodes from the linked list.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= element of linked list <= 1000
0 <= k <= 100

Example:
Input:
2
8
1 2 3 4 5 6 7 8
3
4
1 2 3 4
2

Output:
1 2 4 5 7 8
1 3

Explanation:
Testcase 1: After removing every 3rd element from the linked list, we have updated list as 1, 2, 4, 5, 7 and 8, and the elements which are removed are 3 and 6.
*/

Node* deleteK(Node *head,int K)
{
  //edge case: if head is null or k is 0
  if(head==NULL || K ==0) return head;
  if(K==1) return NULL;
  
  //delete first kth node (rest recursion will take care)
  Node *head_ref = head;
  int count = 1;
  while(head_ref !=NULL && count < K-1){
      //k-1 bcz we need to stop before k
      head_ref = head_ref->next;
      count++;
  }
  if(count == K-1 &&head_ref && head_ref->next){
      head_ref->next = deleteK(head_ref->next->next,K);
  }
  
  return head;
  
}