/*
Question: https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string/0
Given a string str containing alphanumeric characters, calculate sum of all numbers present in the string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a string containing alphanumeric characters.

Output:
Print the sum of all numbers present in the string.

Constraints:
1<=T<=105
1<=length of the string<=105

Example:
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123

Explanation:
Testcase 1: 1 and 23 are numbers in the string which is added to get the sum as 24.
Testcase 4: 123 is a single number, so sum is 123.

*/
using namespace std;

int make_number(int num, int digit)
{
    return 10*num + digit;
}

int main() {
	//t is the number of testcases
	int t; cin>>t;
	while(t--)
	{
	    string str; cin>>str;
	    int sum = 0;
	    
	    for(int i=0; i<str.size(); i++)
	    {
	        //if i see any numeric digit then
	        //check for all numeric digit after it(if any)
	        //using a while loop
	        //and form a number of these
	        int num = 0; //to store the indivisual number that occur in between string
	        if(str[i]>='0' && str[i] <= '9')
	        {
	            while(str[i] >= '0' && str[i] <= '9')
	            {
	                int digit = str[i]-'0';
	                //suppose i found a 2 followed by a 5
	                //then this fun will make it 25
	                num = make_number(num,digit); 
	                i++;
	            }
	            
	            sum += num;
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
