/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index. */

class Solution {
public:
    int firstUniqChar(string s) 
    {
        if(s.length() == 1)
        {
            return 0;
        }
        // loveleetcode //abcdabcde
        for(int i = 0; i < s.length(); i++)
        {
            int count = 0;
            for(int j = 0; j < s.length(); j++)
            {
                if(i != j)
                {
                    if(s[i] == s[j])
                    {
                        break;
                    }
                    count++;
                    
                    if( (count == s.length() - 1) )
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};