/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will 
return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

You may assume that both strings contain only lowercase letters.

*/


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<int,int> umap;
        int magazine_len = magazine.size();
        int ransomNote_len = ransomNote.size();
        
        for(int i=0; i<magazine_len; i++)
            umap[magazine[i]] += 1;
        
        for(int i=0; i<ransomNote_len; i++)
        {
            
            auto it = umap.find(ransomNote[i]);
            
            if(it == umap.end() || it->second == 0)
                return false;
            else
                it->second -= 1;
        }
        return true;
    }
};
