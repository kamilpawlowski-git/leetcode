/* Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^ */

class Solution {
public:
    int myAtoi(string s) 
    {
        string nums = "0123456789";
        
        int i = 0;
        while(i < s.length())
        {
            if(s[i] == ' ' && i == 0)
            {
                s.erase(s.begin() + i);
                continue;
            }
            
            if( (s[i] == '-' || s[i] == '+') && i == 0 )
            {
                i++;
                continue;
            }else
            {
                break;
            }
            
            if(s[i] == '0')
            {
                if(i == 0 || s[i - 1] == '-' || s[i - 1] == '+')
                {
                    s.erase(s.begin());
                    continue;
                }
            }
            
            int count = 0;
            for(int k = 0; k < nums.length(); k++)
            {
                if(s[i] == nums[k])
                {
                    i++;
                    break;
                }
                count++;
                
                if( count == k)
                {
                    s.erase(s.begin() + i, s.end()); 
                    break;
                }
            }
        }
        
        int result = 0;
        int sign = 1;
        i = 0;
        
        if(s[i] == '-' || s[i] == '+')
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        while (i < s.length() && isdigit(s[i])) 
        { 
            int digit = s[i] - '0'; 
            if (result > (INT_MAX - digit) / 10)
            { 
                return (sign == 1) ? INT_MAX : INT_MIN; 
            } 
            result = result * 10 + digit; 
            i++; 
        } 
        
        return result * sign;
        
    }
};