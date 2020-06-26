/*
Question: https://practice.geeksforgeeks.org/problems/word-with-maximum-frequency/0
You are given a string that is made up of words separated by spaces. Your task is to find the word with highest frequency, i.e. it appears maximum times in the sentence. If multiple words have maximum frequency, then print the word that occurs first in the sentence.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each testcase contains a string.

Output:
Print the word with the maximum frequency and the frequency, both separated by a space. See example for more clarity.

Constraints:
1<=T<=100
1<=Total Words<=100

Example:

Input:
5
the devil in the sky
amazon is amazon geeks for geeks is geeks for geeks
this is not right
excels
the phenomenal one

Output:
the 2
geeks 4
this 1
excels 1
the 1

Explanation:
For testcase 1: The frequency of the is 2, so we print the and its frequency
For testcase 3: Every word has the frequency of 1, so we print this 1 as this occurs first in the sentence
*/

#include <iostream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

int main() {
	//t is the number of testcases
	int t; cin>>t;
	while(t--)
	{
	    string str;
	    cin>>ws; //clear the input buffer before using getline as the 
	    //newline entered after giving t input is considered a valid 
	    //string by getline
	    getline(cin,str);
	    
	    
	    istringstream stream_str(str);
	    string curr_str;
	    unordered_map<string,int> hmap;
	    int max_count = 0;
	    
	    while(stream_str>>curr_str)
	    {
	        hmap[curr_str] += 1;
	        max_count = max(max_count,hmap[curr_str]);
	    }
	    
	    istringstream stream_str2(str);
	    while(stream_str2>>curr_str)
	    {
	        if(hmap[curr_str] == max_count)
	        {
	            cout<<curr_str<<" "<<max_count;
	            break;
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}
