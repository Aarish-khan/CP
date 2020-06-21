#include <iostream>
using namespace std;

int mul(int m, int n)
{
	if(m==0||n==0)
		return 0;
	else
		return m+mul(m,n-1);
}


int main()
{
	int m,n;
	cout<<"enter two numbers to recursively multiply: ";
	cin>>n>>m;
	
	cout<<mul(m,n);
	
}
