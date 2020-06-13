/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt

EXAMPLE:
Input: 16
Output: true

Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if (num == 1)
            return true;
        
        long long int upper = num/2;
        long long int lower = 2;
        long long int mid = (upper+lower)/2;
        
        while(lower<=upper)
        {
            if(mid*mid == num)
                return true;
            else if(mid*mid > num)
                upper = mid-1;
            else
                lower = mid+1;
            
            mid = (upper+lower)/2;
        }
        return false;
    }
};
