#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int arr[] = {10,20,30,40,40};

	int n = sizeof(arr)/sizeof(int);

//simple binary search
// ##############################################
	bool present = binary_search(arr,arr+n,40);
	if(present)
		cout<<"present";
	else
		cout<<"absent";
 //##############################################


 //find the lower bound of an element in array

 auto it = lower_bound(arr,arr+n,40);
 cout<<"\nlower bound of 40 is "<<(it-arr);

 auto it2 = upper_bound(arr,arr+n,20);
 cout<<"\nupper bound of 20 is "<<(it2-arr)<<endl;
}
