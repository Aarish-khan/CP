/*
Question Source : gfg
Given a binary string S. The task is to count the number of substrings that start and end with 1. For example, if the input string is “00100101”, 
then there are three substrings “1001”, “100101” and “101”.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of an integer 'N' denoting the string length and next 
line is followed by a binary string.

Output:
For each testcase, in a new line, print the number of substring starting and ending with 1 in a separate line


Example:
Input:
2
4
1111
5
01101
Output:
6
3

*/

long binarySubstring(int n, string a){
    
    // Your code here
    int str_count = 0;
    int ones_count = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]=='1')
        {
            str_count += ones_count;
            ++ones_count;
        }
    }
    return str_count;
    
}
