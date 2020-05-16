#include <iostream>
using namespace std;

int kadane(int arr[], int size)
{
    
    int curr_sum = arr[0];
    int max_sum = arr[0];
    
    for(int i=1; i<size; i++)
    {
        curr_sum = max(curr_sum+arr[i], arr[i]);
        
        if(curr_sum > max_sum)
            max_sum = curr_sum;
    }
    
    return max_sum;
}


int main() {
	
  int n; //enter size of array e.g number of element in array
  cin>>n; 
  int arr[n]; 
  
  //enter all elements of array one by one separated by space
  for(int i=0; i<n; i++)
      cin>>arr[i];

  cout<<(kadane(arr,n));
  cout<<endl;
	return 0;
}
