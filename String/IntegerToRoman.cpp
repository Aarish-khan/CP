/*
Question: https://practice.geeksforgeeks.org/problems/convert-to-roman-no/1/?track=ppc-strings&batchId=221

Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below.

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a single integer n.

Output:
Complete convertToRoman function and return the roman number representation of n.

Your Task:
Complete the function convertToRoman() which takes an integer N as input parameter and returns the equivalent roman. 

Expected Time Complexity: O(log10N)
Expected Auxiliary Space: O(log10N * 10)

Constraints:
1<=T<=100
1<=n<=3999

Example:
Input
2
5
3

Output
V
III 

Explanation:
Test Case 1: 5 can be represented as 'V'.
Test Case 2: 3 can be represented as three 'I'.
*/

// n :given number that you are require to convert
string convertToRoman(int n) 
{
    //Tables for corresponding roman and numaral values
    string roman[] = {"M","CM", "D","CD","C","XC","L", "XL","X","IX","V","IV","I"};
    int number[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    
    int i = 0; // to iterate through above two arrays
    string ans; //our answer (initially empty string)
    
    while(n>0)
    {
        if(n>=number[i])
        {
            ans += roman[i];
            n -= number[i];
        }
        else
            i++;
    }
    return ans;  
}
