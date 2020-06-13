//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
/*
exampl:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> umap;
        
        for(int i=0; i<s.size(); i++)
            umap[s[i]] += 1;
        
        for(int i=0; i<s.size(); i++){
            
            if(umap[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};
