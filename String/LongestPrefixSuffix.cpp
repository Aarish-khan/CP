/*
Given a string of character, find the length of longest proper prefix which is also a proper suffix.
Example:
S = abab
lps is 2 because, ab.. is prefix and ..ab is also a suffix.

Input:
First line is T number of test cases. 1<=T<=100.
Each test case has one line denoting the string of length less than 100000.

Expected time compexity is O(N).

Output:
Print length of longest proper prefix which is also a proper suffix

Example:
Input:
2
abab
aaaa

Output:
2
3
*/
#include <iostream>
#include<string>
using namespace std;
//This is an application of KMP's LPS algorithm
//you have throughly done KMP and LPS i ur notes


int LongestPrefixSuffix(string pattern){

	int pattern_size = pattern.size();
	int lps[pattern_size];

	int len = 0; //moves only if there is matching character found ahead
	int i = 1; //moves continuosly to check if the current character is equal to character at len
	lps[0] = 0;

	while(i<pattern_size)
	{
		if(pattern[i]==pattern[len])
		{
			lps[i] = len+1;
			len++; i++;
		}
		else
		{
			if(len!=0)
				len = lps[len-1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps[pattern_size-1];
}


int main() {
	
  string str;
  cin>>str;

  cout<<LongestPrefixSuffix(str)<<"\n";
	return 0;
}
