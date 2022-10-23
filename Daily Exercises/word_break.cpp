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
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        size_t N = s.size();
        vector<bool> dp(N + 1, false);

        dp[N] = true;

        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = i + 1; j <= N; j++)
            {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(i, j - i)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution test{};
    bool result{false};
    vector<bool> expected{false, true, true, true};

    vector<string> s{"leetcode", "bb", "applepenapple", "catsandog"};
    vector<string> dict1{"leet", "code"};
    vector<string> dict2{"a", "b", "bbb", "bbbb"};
    vector<string> dict3{"apple", "pen"};
    vector<string> dict4{"cats", "dog", "sand", "and", "cat"};

    vector<vector<string>> dicts{dict4, dict2, dict3, dict1};
    for (int i = 0; i < dicts.size(); i++)
    {
        result = test.wordBreak(s[i], dicts[i]);
        cout << "beklenen"
             << "---->" << expected[i] << "  "
             << "sonuc"
             << "---->" << result << endl;
    }
    return 0;
}