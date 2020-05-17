//leetcode question no 33

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        int mid = (start+end)/2;
        
        while(start<=end)
        {
            
            if(nums[mid] == target)
                return mid;
            
            //checking which half is sorted
            else if(nums[mid]<nums[end]) //if this is true means right half is sorted
            {
                //now checking target element lies to which side
                if(target > nums[mid] && target <= nums[end]) //go right
                    start = mid+1;
                else
                    end = mid-1;
            }
            
            //else left part is sorted 
            else
            {
                //check again with target
                if(target >= nums[start] && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
                
            }
            
            mid = (start+end)/2;
        }
        
        return -1;
    }
};
