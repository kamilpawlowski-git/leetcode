/* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome. */

class Solution {
public:
    bool isPalindrome(string s) 
    {
        // ka;mil
        
        string letters = "abcdefghijklmnopqrstuvwxyz0123456789";
        int i = 0;
        while(i < s.length())
        {
            int count = 0;
            for(int j = 0; j < letters.length(); j++)
            {
                if(tolower(s[i]) == letters[j])
                {
                    i++;
                    break;
                }
                count++;

                if( count == letters.length() )
                {
                    s.erase(s.begin() + i);
                }
            }
        }
        
        
        for(int i = 0; i < s.length()/2; i++)
        {
            if(tolower(s[i]) != tolower(s[s.length() - 1 - i]))
            {
                return false;
            }
        }
        return true;
    }
};