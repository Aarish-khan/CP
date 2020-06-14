//problem description
/*
Given a number n, count minimum steps to minimise it to 1 according to the following criteria:

If n is divisible by 2 then we may reduce n to n/2.
If n is divisible by 3 then you may reduce n to n/3.
Decrement n by 1





Input:

integer N denoting the number.

Output:

Output the minimum steps to minimise the number in a new line for each test case.
*/

#include<iostream>
using namespace std;

int min_steps_to_1(int n, int dp[])
{
	//base case
	if(n == 1)
		return 0;

	//recursive case
	int a,b,c;
	a = b = c = n+1;  //instead of taking INT_MAX we can take n+1 as max, bcoz #steps won't go beyond n.

	if(n%3 == 0)
		a = 1+min_steps_to_1(n/3,dp);

	if(n%2 == 0)
		b = 1+min_steps_to_1(n/2,dp);

	c = 1+min_steps_to_1(n-1,dp);

	int ans = min(min(a,b),c);
	return dp[n] = ans;
}

int main()
{
	int n;
	cin >> n;

	//create a dp array, to store the subproblems solution
	//e.g  for each number we have stored number of steps required to reach to 1. 
	/*
number:	  1   2   3   4   5   6   7   8
		---------------------------------
 steps  | 0 | 1 | 1 | 2 | 3 | 2 | 3 | 3 |
		---------------------------------

	*/

	int dp[n+1];

	cout << min_steps_to_1(n,dp);
}