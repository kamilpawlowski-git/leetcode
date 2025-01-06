/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0] */

class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums.size() - 1; j++)
            {
                if(nums[j] == 0)
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};