#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int max_subarray_sum(int *, int); //defining the function that returns/prints the answer
    int n; //number of elements in the array
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) //taking elements from user
    cin>>arr[i];
    cout<<max_subarray_sum(arr, n); //passing array to function with number of elemnts and printing the result returned by function.
}

void max_subarray_sum(int *arr, int array_size)
{
	int maxsum = INT_MIN;  //minimum posiible value stored initially in maxsum variable
	
	/* we will start from index 0 and check all subarrays possible starting from 0 index
	and whoever is maximum among them his sum will be stored in maxsum
	then we will move array_starting_index by 1 and check all subarrays those starts
	from index 1, we will see if any subarray among these have sum greater then current maxsum
	similarly we will proceed till araay_starting index reaches array_size*/
	int start_index, end_index;
	for(int array_starting_index=0;  array_starting_index<array_size;  ++array_starting_index)
	{
		int sum =0;    
		for(int j=array_starting_index; j<array_size; j++) //this loop will check maximum subarray from a particular index
		{
			sum += arr[j];
			if(sum>maxsum)
			{
				maxsum = sum;
				start_index = array_starting_index; //keep a tab on the starting index of maxsum subarray
				end_index = j;                      //keep a tab on the end  index of maxsum subarray
				
			}
		}
	}
	
	return maxsum;
	
}
