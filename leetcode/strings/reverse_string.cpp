/* Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"] */

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        for(int i = 0; i < s.size()/2; i++)
        {
            int index = s.size() - 1 - i;
            char temp = s[i];
            s[i] = s[index];
            s[index] = temp;
        }
    }
};