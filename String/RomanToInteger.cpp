/*

Question: https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0

Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3
*/

#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	//first create a map for roman and integer numerals
	unordered_map<char,int> values;
	values['M'] = 1000;
	values['D'] = 500;
	values['C'] = 100;
	values['L'] = 50;
	values['X'] = 10;
	values['V'] = 5;
	values['I'] = 1;
	

  string s; cin>>s;
  int curr_val = 0;
  int ans = 0;
  for(int i=s.size()-1; i>=0; i--)
  {
      int temp = values[s[i]];
      if(temp>=curr_val)
      {
          ans += temp;
          curr_val = temp;
      }
      else
      {
          ans -= temp;
          curr_val = temp;
      }
  }

  cout<<ans<<"\n";
	return 0;
}
