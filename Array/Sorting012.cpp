#include <iostream>
using namespace std;

//seggregate 0's , 1's, 2's 
//dutch nationalflag algorithm
void sort(int arr[], int n)
{
    int p, q,k;
    p = 0;
    k = 0;
    q = n-1;
    int pivot = 1;
    while(k<=q)
    {
        if(arr[k]<pivot)
        {
            swap(arr[k],arr[p]);
            p++;
        }
        if(arr[k]==pivot)
        k++;
        else
        {
            swap(arr[k],arr[q]);
            q--;
        }
    }  
}

int main()
{
	int n = 10;
	int arr[n] = {1,0,2,1,2,1,0,0,0,2};
	sort(arr,n);
	for(int i=0; i<n; i++)
	cout<<arr[i];
}
