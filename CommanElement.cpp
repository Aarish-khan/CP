//another approach with constant space is also possible, wher we will make use of the fact that arrays are sorted
//here in this approach of solution we have used extra space of O(n ) and time complexity is also linear.
/*
Question : https://practice.geeksforgeeks.org/problems/common-elements/0/

Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases. T testcases follow. Each testcase contains four lines of input. First line consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C respectively. The second line contains N1 elements of A array. The third lines contains N2 elements of B array. The fourth lines contains N3 elements of C array.

Output:
For each testcase, print the common elements of array. If not possible then print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 107
1 <= Ai, Bi, Ci <= 1018

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements
*/

#include <iostream>
#include<map>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n1,n2,n3;
	    cin>>n1>>n2>>n3;
	    
	    int arr1[n1]; int arr2[n2]; int arr3[n3];
	    
	    for(int i=0; i<n1; i++)
	        cin>>arr1[i];
	    
	    for(int i=0; i<n2; i++)
	        cin>>arr2[i];
	    
	    for(int i=0; i<n3; i++)
	        cin>>arr3[i];
	        
	    map<int,int> hmap;
	    
	    for(int i=0; i<n1; i++)
	        if(hmap.find(arr1[i]) == hmap.end())
	            hmap[arr1[i]] = 1;
	            
	    for(int i=0; i<n2; i++)
	        if(hmap.find(arr2[i]) != hmap.end() && hmap[arr2[i]] == 1)
	            hmap[arr2[i]] = 2;
	    
	    for(int i=0; i<n3; i++)
	        if(hmap.find(arr3[i]) != hmap.end() && hmap[arr3[i]] == 2)
	            hmap[arr3[i]] = 3;
	   
	   map<int,int>::iterator it = hmap.begin();
	   bool isPresent = false;
	   for(; it!=hmap.end();it++)
	   {
	       if(it->second == 3)
	       {
	           cout<<it->first<<" ";
	           isPresent = true;
	       }
	   }
	   
	   if(!isPresent)
	    cout<<"-1";
	   
	   cout<<endl;
	}
	return 0;
}
