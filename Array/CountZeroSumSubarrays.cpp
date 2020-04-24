#include <iostream>
#include<unordered_map>
using namespace std;

int count_zero_sum_subarray(int arr[], int n)
{
    int count = 0;
    int curr_subarray_sum = 0;
    unordered_map<int,int> CumulativeSum;
    
    for(int i=0; i<n; i++)
    {
        curr_subarray_sum += arr[i];
        
        if(curr_subarray_sum == 0)
            count++;
        
        if(CumulativeSum.find(curr_subarray_sum)!=CumulativeSum.end())
            count += CumulativeSum[curr_subarray_sum];
        
        CumulativeSum[curr_subarray_sum] += 1;
    }
    
    return count;
}
int main() {
	
  
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	        
	    cout << count_zero_sum_subarray(arr,n);
	    cout << endl;
  
  
	return 0;
}
