/*
Question: https://practice.geeksforgeeks.org/problems/first-repeating-element/0

Given an integer array. The task is to find the first repeating element in the array i.e., an element that occurs more than once and whose index of first occurrence is smallest.

Input :
The first line contains an integer T denoting the total number of test cases. In each test cases, First line is number of elements in array N and second line contains N space separated integer values of the array.

Output:
In each separate line print the index of first repeating element, if there is not any repeating element then print “-1” (without quotes). Use 1 Based Indexing. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 106

Example:
Input:
3
7
1 5 3 4 3 5 6
4
1 2 3 4
5
1 2 2 1 3
Output:
2
-1
1

Explanation: 
Testcase 1: 5 is appearing twice and its first appearence is at index 2 which is less than 3 whose first occuring index is 3.
Testcase 2: None of the elements are occuring twice . So, the answer is -1.
Testcase 3: 1 is appearing twice and its first appearence is at index 1 which is less than 2 whose first occuring is at index 2.

*/
#include <iostream>
#include<unordered_map>
using namespace std;

int firstRepeating(int arr[], int n)
{
    unordered_map<int,int> hmap;
    int min_index = n+1;
    
    for(int i=1; i<=n; i++)
    {
        if(hmap[arr[i]]==0)
            hmap[arr[i]] = i;
        else
        {
            if(min_index>hmap[arr[i]])
                min_index = hmap[arr[i]];
        }
    }
    if(min_index==n+1)
        return -1;
    return min_index;
}

int main() {
	int t; cin>>t;
	
	while(t--)
	{
	    int n; cin>>n;
	    int arr[n];
	    
	    for(int i=1; i<=n; i++)
	        cin>>arr[i];
	    
	    cout<<firstRepeating(arr,n)<<"\n";
	}
	return 0;
}
