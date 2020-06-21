#include<iostream>
using namespace std;



int main()
{
	int first_missing_positive(int [], int);
	
	int arr[] = {0,-10,1,3,-20};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<first_missing_positive(arr,n);
}

int first_missing_positive(int arr[], int n)
{
    //checking if 1 is present or not
    bool one_present;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==1)
            one_present = true;  //marking 1 as present
    }
    if(!one_present)
        return 1;
    
    
    //if one is present then execution will come here
    
    //making all 0's and negative numbers equal to 1(this is a way
    //of neglacting or skipping these numbers, because we don't care
    //about negatives and zeros)
    for(int i=0; i<n; i++)
        if(arr[i]<=0 || arr[i]>n)
            arr[i] = 1;
    
    //now the main crux of concept is
    //use array values as an index and marks those indexes as present
    for(int i=0; i<n; i++)
    {
        
        if(arr[abs(arr[i])-1]>0)
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    
    //now for all those values which are present in array 
    //if i consider these values as index of array and go to these
    //indexes, here i'll find negative values
    
    
    //scan through array one last time and lokk for any positive value
    //the index of this value is the missing number
    for(int i=0; i<n; i++)
        if(arr[i]>0)
            return i+1;
    
    //if i come here then all values upto n are present so smallest
    //misiing will be n+1
    return n+1;
}

