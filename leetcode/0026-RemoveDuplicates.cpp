class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        int k = 0;
        int i = 0;
        for(; i<nums.size()-1; i++)
        {
            if(nums[i] != nums[i+1])
                nums[k++] = nums[i];
        }
        //for boundary element 
        nums[k] = nums[i];
        return k+1; 
        //k is the index, bcoz index starts at 0, therefor size will be k+1
        
        
    }
};
