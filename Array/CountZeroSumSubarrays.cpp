#include <iostream>
#include<unordered_map>
using namespace std;

int count_zero_sum_subarray(int arr[], int n)
{
    int count = 0; //this variable will store the count of subarray having zero sum
    int curr_subarray_sum = 0; //used to storethe sum of current subarray (e.g subarray of current window) 

//Taking a hashmap, CumulativeSum, used to store the cumulative sum upto the subarray at index i
//e.g at index 0 it will contain sum of subarray ranging from index 0 to index 0
//and at index 1 it will make a new entry and will store the sum of subarray ranging from index 0 to index 1;
// and at index 2(iterating in for loop) it will store subarray sum of subarray ranging from index 0 to index 2
// And so on...
    unordered_map<int,int> CumulativeSum;
    
    for(int i=0; i<n; i++)
    {
        curr_subarray_sum += arr[i];
        
	//check if by adding a value(e.g arr[i]) is our curr_sbarray_sum become equal to 0(the required sum)
	//if so then increase count by 1
        if(curr_subarray_sum == 0)
            count++;
        
	//now check if there is any subarray (starting from index 0 to any index (say) x where x<i
	//why x is less than i? because our curr_subarray_sum variable contains the subarray sum ranging from index 0 to i.
	//moreover unoredered map will take care about this condition because we have not yet added the 
	//curr_subarray_sum (subarray sum upto index i) into unordered_map named Cumulative sum
	  
        if(CumulativeSum.find(curr_subarray_sum)!=CumulativeSum.end())
            count += CumulativeSum[curr_subarray_sum];
        
	    
	 //now add this subarray sum(from index 0 to i) into Cumulative_Sum
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
