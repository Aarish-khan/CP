/*
Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 ) and last two characters represent minutes (between 00 to 59)

*/



#include <iostream>
#include<algorithm>
using namespace std;

int minimum_platform(int arrival[], int departure[], int n)
{
    if(n<=0)
        return 0;
    sort(arrival,arrival+n);
    sort(departure,departure+n);
    int p = 0;
    int q = 0;
    int stations = 0;
    int count = 0;
    while(p<n && q<n)
    {
        if(arrival[p]<=departure[q])
        {
            count += 1;
            p++;
        }
        else
        {
            count -= 1;
            q++;
        }
        
        stations = max(stations,count);
    }
    return stations;
    
}


int main() {
	
  int n; cin>>n;
  int arrival[n];
  int departure[n];
  for(int i=0; i<n; i++)
      cin>>arrival[i];
  for(int i=0; i<n; i++)
      cin>>departure[i];

  cout<<minimum_platform(arrival,departure,n)<<"\n";
  
	return 0;
}
