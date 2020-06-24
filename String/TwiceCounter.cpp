/*
Given an array of n words. Some words are repeated twice, we need count such words.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of words in the string. The next line contains n space separated words forming the string.

Output:
Print the count of the words which are repeated twice in the string.

Constraints:
1<=T<=105  
1<=no of words<=105
1<=length of each word<=105

Example:
Input:
2
10
hate love peace love peace hate love peace love peace
8
Tom Jerry Thomas Tom Jerry Courage Tom Courage

Output:
1
2
*/
#include <iostream>
#include<string>
#include<unordered_map>
using namespace std;

int TwiceCounter(string str_arr[], int n)
{
    unordered_map<string,int> hmap;
    
    for(int i=0; i<n; i++)
        hmap[str_arr[i]] += 1;
    
    unordered_map<string,int>::iterator it = hmap.begin();
    int count = 0;
    for(; it!=hmap.end(); ++it)
    {
        if(it->second==2)
            count++;
    }
    return count;
}

int main() {
	

  int n; cin>>n;
  string str_arr[n];

  for(int i=0; i<n; i++)
      cin>>str_arr[i];

  cout<<TwiceCounter(str_arr,n)<<"\n";
	return 0;
}
