/*
Question : https://practice.geeksforgeeks.org/problems/remove-duplicates/0/?track=md-string&batchId=144
Given a string, the task is to remove duplicates from it. Expected time complexity O(n) where n is length of input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

Note: that original order of characters must be kept same. 

Input:
First line of the input is the number of test cases T. And first line of test case contains a string.

Output: 
Modified string without duplicates and same order of characters.

Constraints: 
1 <= T <= 15
1 <= |string|<= 1000

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for
*/
#include <iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

void removeDuplicates(string str)
{
    unordered_map<char,int> hmap;
	    
    for(int i=0; i<str.size(); i++)
    {
        if(hmap[str[i]] == 0)
        {
            hmap[str[i]] = 1;
            cout<<str[i];
        }
    }
}

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    
	    string str;
	    //cin.clear(); cin.ignore(INT_MAX,'\n');<----didn't work
	    
	    
	    cin>>ws; //clears the input buffer stream
	    //Alternative to above is that we first take 
	    //newline character in string and overwrites it with 
	    //what i realy wanted by using getline(cin,str) twice
	    getline(cin,str);
	    
	    
	    removeDuplicates(str);
	    cout<<"\n";
	    
	}
	return 0;
}
