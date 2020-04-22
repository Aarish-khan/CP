#include <iostream>
using namespace std;

void subarray(int arr[], int n, int target_sum)
{
    int curr_subarray_sum = 0;
    //p and q are two pointers indicating the start
    //and end of subarray respectivly(both are initially at first index)
    int p = 1;
    int q = 1;
    
    for(; q<=n; q++)
    {
        //if current sum is larger suntract start indecies values till
        //it becomes less than target
        curr_subarray_sum += arr[q];
        
        while(curr_subarray_sum > target_sum)
            curr_subarray_sum -= arr[p++];
        
        
        if(curr_subarray_sum == target_sum)
        {
            //printing the indexes between whom(inclusive) given sum
            //is found
            cout <<p <<" "<<q;
            return;
        }
        
    
            
    }
    //if cotrol comes here that means subarray not found
    cout <<"-1";
    return;
    
    
}


int main() {
//n is the numbe rof elements in the array
//s is the subarray you want to find
    int n,s;
    cin>>n>>s;
    int arr[n];
    //taking array elements freom the user
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    //find the subarray 
    subarray(arr,n,s);
    cout<<endl;
    
	return 0;
}
