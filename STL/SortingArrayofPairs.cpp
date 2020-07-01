#include<bits/stdc++.h>
using namespace std;

//Note: Sorting an array of pairs using STL sort sorts the array based on first element of pair

int main()
{
  //declaring a array of pairs
  int size = 5;
  pair<int,int> arrPos[size];
  //a random array 
	int arr[5] = {4,1,7,2,5};

  //filling array of pairs using random array
	for(int i=0; i<size; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}
  
  //sorting using STL sort
	sort(arrPos, arrPos + size);

	for(int i=0; i<size; i++)
	{
		cout<<arrPos[i].first<<" "<<arrPos[i].second<<",";
	}
}
