// https://leetcode.com/problems/word-break/

// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Example 1:
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

// Constraints:
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

// level:medium

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<char, int> map;

        // verilen stringteki harf sayılarını bul
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
        }
        // verilen sözlükteki kelimeleri tek tek gez
        for (int j = 0; j < wordDict.size(); j++)
        {
            // her bir kelimenin karakterleri verilen stringte var mı kontrol et
            for (int k = 0; k < wordDict[j].size(); k++)
            {
                if (map[wordDict[j][k]] <= 0)
                {
                    return false;
                }
                map[wordDict[j][k]]--;
            }
        }

        return true;
    }
};
int main()
{
    Solution test{};
    bool result{false};
    string s{"leetcode"};
    vector<string> dict{"leet", "code"};
    result = test.wordBreak(s, dict);
    cout << endl;
    return 0;
}