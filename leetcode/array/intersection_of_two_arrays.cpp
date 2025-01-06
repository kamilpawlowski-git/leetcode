/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2] */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums1.size() - 1; j++)
            {
                if(nums1[j + 1] < nums1[j])
                {
                    int temp = nums1[j];
                    nums1[j] = nums1[j + 1];
                    nums1[j + 1] = temp;
                }
            }
        }
        
        for(int i = 0; i < nums2.size(); i++)
        {
            for(int j = 0; j < nums2.size() - 1; j++)
            {
                if(nums2[j + 1] < nums2[j])
                {
                    int temp = nums2[j];
                    nums2[j] = nums2[j + 1];
                    nums2[j + 1] = temp;
                }
            }
        }
        // 1, 1, 2, 2
        vector<int> outputArray;
        int last = -1;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    outputArray.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + j);
                    last = nums1[i];
                    break;    
                }
            }
            last = nums1[i];
        }
        return outputArray;
    }
};