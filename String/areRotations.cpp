#include<bits/stdc++.h>
using namespace std;

bool areRotations(string s1,string s2)
{
    // Your code here
    if(s1.size()!=s2.size())
        return false;
    
    int size = s1.size();
    int lps[size];
    computeLPS(s1,s2,lps);
    
    
    //i = starting index of string s2
    //k = number of time string is rotated
    //lps[size-1] = value at last index of lps table
    int i = 0;
    for(int k = lps[size-1]; k<size; k++,i++)
    {
        if(s2[k]!=s1[i])
            return false;
    }
    return true;
}
int main()
{
  string s1 =  "geeksforgeeks";
  string s2 = "forgeeksgeeks";
  cout<<areRotations(s1,s2);
}
