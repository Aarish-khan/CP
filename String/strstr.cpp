/*
question: https://practice.geeksforgeeks.org/problems/implement-strstr/1/

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. The first line of each test case contains two strings s and x.

Output:
For each test case, in a new line, output will be an integer denoting the first occurrence of the x in the string s. Return -1 if no match found.

Example:
Input
2
GeeksForGeeks Fr
GeeksForGeeks For
Output
-1
5
*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     int s_size = s.size();
     int x_size = x.size();
     
     for(int i=0; i+x_size<=s_size; i++)
     {
         int j=0;
         for(; j<x_size; j++)
         {
            if(s[i+j]==x[j])
                continue;
            else
                break;
         }
         if(j==x_size)
            return i;
     }
     return -1;
}
