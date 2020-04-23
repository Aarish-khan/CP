#include <iostream>
#include <unordered_map>
using namespace std;

int subarray_count(int arr[], int n, int target_sum)
{
    int count = 0; //keep track of number of subarrays with given sum found
    int curr_subarray_sum = 0;  //sum of current subarray, between two indices
    unordered_map<int,int> nums;   //Map is used to store the cumulative sum of array while traversing through it
    
    for(int i=0; i<n; i++)
    {
        curr_subarray_sum += arr[i];   // in first iteration we added the first element to the curr_subarray_sum. 
                                       //In first iteration subarray indices(say p,q) are at 0.
        
        //by adding arr[i] we will check if our target_sum is achieved or not, if target sum is achieved than increamnet count by one
        if(curr_subarray_sum == target_sum)
            count++;
        
        
        //look in the map if we have curr_subarray_sum - target_sum,
        if(nums.find(curr_subarray_sum - target_sum) != nums.end())
            count += nums[curr_subarray_sum - target_sum];
        
        nums[curr_subarray_sum] += 1; //add current sum subarray to map
    }
    
    return count;
}

int main() {
	
	    int n; cin>>n;
	    int arr[n];
	    
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    
	    int target_sum;
	    cin>>target_sum;
	    
	    cout<<subarray_count(arr,n,target_sum);
	    cout<<endl;
	return 0;
}
