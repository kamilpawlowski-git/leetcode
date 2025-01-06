/* You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4]. */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        // bez zmiany liczby elementow gdy nie ma 9
        int lastIndex = digits.size() - 1;
        if(digits[lastIndex] != 9)
        {
            digits[lastIndex]++;
            return digits;
        }else
        {
            // ze zmiana liczby elementow gdy 9 jest na koncu, ale jest samo (jeden przypadek: (9) -> (1,0))
            if(digits.size() == 1)
            {
                vector<int> vec = {1, 0};
                return vec;
            }
            // bez zmiany liczby elemetnow gdy jest 9 (przyklad (1,9) -> (2,0))
            // ze zmiana liczby elementow gdy jest 9 na koncu (przyklad: (9,9) -> (1,0,0))
            // trzba sprawdzac zawsze element wczesniej
            digits[lastIndex] = 0;
            for(int i = digits.size() - 2; i >= 0; i--)
            {
                // 1,0,0,0,0
                if(digits[i] == 9 && i != 0)
                {
                    digits[i] = 0;
                }else if(digits[i] == 9 && i == 0)
                {
                    digits[i] = 0;
                    digits.insert(digits.begin(), 1);
                }else
                {
                    digits[i]++;
                    break;
                }
            }
            
        }
        return digits;
    }
};