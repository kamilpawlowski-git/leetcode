/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true */

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
        {
            return false;
        }
        
        int arrayS[26] = { 0 };
        int arrayT[26] = { 0 };
        
        for(int i = 0; i < s.length(); i++)
        {
            arrayS[int(s[i] - 'a')]++;
            arrayT[int(t[i] - 'a')]++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(arrayS[i] != arrayT[i])
            {
                return false;
            }
        }
        return true;
    }
};