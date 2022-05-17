//! template version 2.2
// https://leetcode.com/problems/valid-anagram/
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// level:easy
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t)
{
    
}

int main()
{
    vector<string> s = {"anagram", "rat"};
    vector<string> t = {"nagaram", "car"};
    vector<string> expected = {"true", "false"};
    bool result;
    for (int i = 0; i < s.size(); i++)
    {
        result = isAnagram(s[i], t[i]);
        cout << s[i] << "---->" << t[i] << "---->" << expected[i] << "---->" << result << endl;
    }
    return 0;
}