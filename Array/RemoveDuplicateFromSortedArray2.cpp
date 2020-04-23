//leetcode question link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    if(nums.size() == 0)
        return 0;
    
    int count =1;
	int k = 0;
	int i=0;

	for(; i<nums.size()-1; i++)
	{
		if(nums[i] == nums[i+1])
		{
			count++;
			continue;
		}

		if(count == 1)
			nums[k++] = nums[i];
		else
		{
			nums[k++] = nums[i];
			nums[k++] = nums[i];
			count = 1;
		}
	}
    //for boundary case
	if(count == 1)
		nums[k++] = nums[i];
	else
	{
		nums[k++] = nums[i];
		nums[k++] = nums[i];
	}

	return k;
    }
};
