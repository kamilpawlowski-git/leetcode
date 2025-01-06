/* Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1 */

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size() - 1; j++)
            {
                if(nums[j + 1] < nums[j])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        // 1,1,2,2,4
        for(int i = 1; i < nums.size(); i+=2)
        {
            if(nums[i] == nums[i - 1])
            {
                if(i + 1 != nums.size() - 1)
                {
                    continue;
                }
                return nums[nums.size() - 1];
            }else
            {
                return nums[i - 1];
            }  
        }
        return nums[0];
    }
};