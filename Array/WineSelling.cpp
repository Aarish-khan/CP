#include<iostream>
using namespace std;


int max_profit(int wines[], int n, int year)
{
	//base case
	if(n==0)
		return 0;

	//look in the memoization table if you have already calculated result or not


	int leftSelled = max_profit(wines+1,n-1,year+1) + year*wines[0];

	int rightSelled = max_profit(wines,n-1,year+1) + year*wines[n-1];

	return max(leftSelled,rightSelled);
}



int main()
{
	int wines[] = {2,3,5};
	int n = sizeof(wines)/sizeof(wines[0]);
	int year = 1;
	


	cout<<max_profit(wines,n,year);
}