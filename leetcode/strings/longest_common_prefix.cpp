/* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl" */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result;
        for(int i = 0; ; i++)
        {
            if(i >= strs[0].length())
            {
                return result;
            }
            char currentChar = strs[0][i];
            for(int j = 0; j < strs.size(); j++)
            {
                
                if(i >= strs[j].length() || currentChar != strs[j][i])
                {
                    return result;
                }
            }
            result += currentChar;
        }
        return result;
    }
};