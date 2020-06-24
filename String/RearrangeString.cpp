/*
Question Source = gfg (https://practice.geeksforgeeks.org/problems/rearrange-a-string/0)
Given a string containing uppercase alphabets and integer digits (from 0 to 9), the task is to print the alphabets in the order followed by the sum of digits.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string with uppercase alphabets and integer digits.

Output:
Print alphabets in the order followed by the sum of digits

Example:
Input:
2
AC2BEW3
ACCBA10D2EW30

Output:
ABCEW5
AABCCDEW6
*/
#include <iostream>
using namespace std;

int main() {
	//t is the number of testcases
	int t; cin>>t;
	
	while(t--)
	{
	    string str;
	    cin>>str;
	    int hmap[26] = {0};
	    int sum = 0;
	    
	    int size = str.size();
	    for(int i=0; i<size; i++)
	    {
	        if(str[i]>='A' and str[i]<='Z')
	            hmap[str[i]-'A'] += 1;
	        else
	            sum += str[i]-'0';
	    }
	    
	    for(int i =0; i<26; i++)
	    {
	        for(int j=0; j<hmap[i]; j++)
	        {
	            char ch = 'A' + i;
	            cout<<ch;
	        }
	    }
	    cout<<sum;
	    
	    cout<<endl;
	}
	return 0;
}
