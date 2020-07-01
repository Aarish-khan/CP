//Approach: 1.Creating every possible substring
//2.check if it pqalindrome usbstring
//if this is palindrome substring than check if this is greater than the previous palindrome substring
//if yes then this is the new longest palindrome substring


bool isPalindrome(string str)
{
    string temp = str;
    reverse(str.begin(), str.end());
    return temp == str;
}
string longestPalindrome(string A) {
    int size = A.size();
    string substr;
    int max_size = 1;
    int start_idx = 0;
    for(int i=0; i<=size; i++)
    {
        for(int j=i+1; j<=size; j++)
        {
            //create substring 
            substr = A.substr(i,j-i);
            
            string temp = substr;
            //reverse substring
            reverse(substr.begin(),substr.end());
            check if both are equal
            if(temp == substr)
            {
                //check if this palindrome substring length is reater than previous maximum, if yes than assign this length to max_size
                if(j-i>max_size)
                {
                    max_size = j-i;
                    start_idx = i;
                }
            }
        }
    }
    return A.substr(start_idx,max_size);
}

int main()
{
  string str = "abababa";
  cout<<longestPalindrome(str);
}
