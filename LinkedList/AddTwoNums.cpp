/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= N, M <= 5000
*/

//a function to reverse linked list
Node * reverse(struct Node* head){
    
    if(head == NULL || head->next == NULL ) return head;
    
    Node *p,*q,*r;
    p = NULL;
    q = head;
    r = head->next;
    
    while(r){
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    head = q;
    return head;
}
//function to insert node in linked list
Node* insert(Node *head, int digit){
    
    Node *new_node = new Node(digit);
    if(head==NULL) return new_node;
    
    new_node->next = head;
    head = new_node;
    
    return head;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = reverse(first);
    second = reverse(second);
    Node *ans = NULL;
    
    int carry = 0;
    int sum = 0;
    int digit;
    while(first&&second){
        sum = first->data + second->data + carry;
        digit = sum%10;
        carry = sum/10;
    
        ans = insert(ans,digit);
        
        first = first->next;
        second = second->next;
    }
    
    if(first==NULL && second !=NULL){
        while(second){
        sum = second->data + carry;
        digit = sum%10;
        carry = sum/10;
    
        ans = insert(ans,digit);
        
        second = second->next;
        }
    }
    else if(first!=NULL && second == NULL){
        while(first){
        sum = first->data + carry;
        digit = sum%10;
        carry = sum/10;
    
        ans = insert(ans,digit);
        
        first = first->next;
        }
    }
    
    if(carry !=0){
        ans = insert(ans,carry);
    }
    return ans;
}

