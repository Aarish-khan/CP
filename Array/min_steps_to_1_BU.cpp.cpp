#include<iostream>
using namespace std;

int MinStep(int n, int dp[])
{

	dp[1] = 0;

	int a,b,c;
	
	for(int i = 2; i<= n; i++)
	{
		a = b = c = n+1;
		if(i%3==0)
			a = dp[i/3];
		if(i%2==0)
			b = dp[i/2];

		c = dp[i-1];

		dp[i] = 1 + min(min(a,b),c);

	}

	
	return dp[n];


}



int main()
{
	int n; cin >> n;

	int dp[n+1] = {0};

	cout<<MinStep(n,dp);


}