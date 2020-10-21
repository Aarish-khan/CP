#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	int d1 = a.first*a.first + a.second * a.second;
	int d2 = b.first*b.first + b.second * b.second;

	if(d1 == d2)
		return a.first < b.first;
	return d1 < d2;
}

int main()
{
	int n;
	cout<<"how many cars are there ";
	cin>>n;

	vector<pair<int,int>> cars;

	cout<<"enter the x and y co-ordinate of each of "<<n<<" cars ";
	int x,y;
	for(int i=0; i<n; i++){
		cin>>x;
		cin>>y;
		cars.push_back(make_pair(x,y));
	}

	cout<<endl;

	cout<<"here are your cars\n";
	for(auto x:cars){
		cout<<x.first<<" "<<x.second<<endl;
	}

	sort(cars.begin(),cars.end(),compare);

	cout<<"cars sorted according to the shortest distance from you e.g origin \n";

	for(auto x:cars){
		cout<<x.first<<" "<<x.second<<endl;
	}
}
