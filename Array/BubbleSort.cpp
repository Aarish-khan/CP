#include <iostream>
using namespace std;

void bubble(int arr[], int i, int n)
{
	
	for(int j=0; j<n-i-1; j++)
	{
		if(arr[j]>arr[j+1])
			swap(arr[j],arr[j+1]);
	}
}

void BubbleSort(int arr[], int n)
{
	int i=0;
	for(i; i<n-1; i++)
		bubble(arr,i,n); //bubble up the ith element
	//in case ith element is largest in array it will bubble up to last index
	//second largest element will bubble up to second lat index of array
	//third largest will buuble up to third last index of array 
	//and so on.....
	//first element e.g i=0 will be compared with every remaining element so number of comparisons = n-1
	//for second element number of comparison = n-2
	//for third element = n-3
	//summing up all comparison give = O(n2) comparisons
	//in worst case every comparison is a swap therefor worst case swaps  = O(n2)
	//in best case no comaprison is swap therefor best case swaps operations = 0
	
}


int main()
{
	int n;
	cout<<"enter number of elements to sort: ";
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	//call bubble sort function to sort the array
	
	BubbleSort(arr,n);
	
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
}
