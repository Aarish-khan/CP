//Problem:Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

//EXAMPLE:-
//Input: 5
//Output: 2
//Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

//SOLUTION

class Solution {
public:
    int findComplement(int num) {
        
        int temp = 1;
        int num_copy = num;
        
        while(num_copy){
            
            num ^= temp;
            temp = temp<<1;
            num_copy = num_copy>>1;
        }
        
        return num;
    }
};
