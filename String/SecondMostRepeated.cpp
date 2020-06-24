/*
Question:https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence/0/

Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings in a sequence and the second line contains N space separated strings.

Output:
For each test case, in a new line print the second most repeated string.

Constraints:
1<=T<=100
3<=N<=103
1<=|String length|<=100

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for
*/

#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

string SecondMostRepeated(string strs[], int n)
{
    unordered_map<string,int> hmap;
    
    for(int i=0; i<n; i++)
        hmap[strs[i]] += 1;
    
    string max_key;
    int max_count = 0;
    for(auto it:hmap)
    {
        if(it.second>max_count)
        {
            max_count = it.second;
            max_key = it.first;
        }
    }
    
    hmap.erase(max_key);
    
    
    max_count = 0;
    for(auto it:hmap)
    {
        if(it.second>max_count)
        {
            max_count = it.second;
            max_key = it.first;
        }
    }
    return max_key;
    
}

int main() {
  //n is the number of strings
  int n; cin>>n;
  string strs[n];

  for(int i=0; i<n; i++)
      cin>>strs[i];

  cout<<SecondMostRepeated(strs,n)<<"\n";
	return 0;
}
