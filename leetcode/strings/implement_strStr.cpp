/* Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0. */

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        //leetcode leeto
        for(int i = 0; i < haystack.length(); i++)
        {
            int count = 0;
            if(i + needle.length() <= haystack.length())
            {
                for(int j = 0; j < needle.length(); j++)
                {
                    if(haystack[i + j] != needle[j])
                    {
                        break;
                    }
                    count++;
                }
                
                if(count == needle.length())
                {
                    return i;
                }
            }
        }
        return -1;
    }
};