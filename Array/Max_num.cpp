#include <iostream>
using namespace std;

bool decide(int a, int b)
{
    int temp1 = stoi(to_string(a)+to_string(b));
    int temp2 = stoi(to_string(b)+to_string(a));
    
    if(temp1>=temp2)
    return false;
    else
    return true;
}


string greatest(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int maxindex = i;
        for(int j=i+1; j<n;j++)
        {
            
            if(decide(arr[maxindex],arr[j]))
            maxindex = j;
            
        }
        swap(arr[maxindex],arr[i]);
    }
    string str = "";
    for(int i =0; i<n; i++)
    {
        str += to_string(arr[i]);
    }
    
    return str;
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<greatest(arr, n)<<endl;
	}
	return 0;
}
