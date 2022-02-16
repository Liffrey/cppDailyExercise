//Given an integer x, return true if x is palindrome integer.
//An integer is a palindrome when it reads the same backward as forward.
//For example, 121 is a palindrome while 123 is not.

//level: easy

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i,j;
        if(x==0) return true;
            for (int i = 0; i < s.length() / 2; i++) 
            {
                if (s[i] != s[s.length() - i - 1]) 
                {
                return false;
                }
            }   
        return true;
    return false;
    }
};