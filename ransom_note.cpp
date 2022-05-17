//! template version 2.1
// https://leetcode.com/problems/ransom-note/
//  Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

// level:easy
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> map;
    // magazine içindeki tüm karakterleri map içerisine yerleştir.
    if (magazine.size() < ransomNote.size())
        return false;
    for (int i = 0; i < magazine.size(); i++)
    {
        // tüm magazine karakterleri sayısı kadar map içerisine yerleşti.
        map[magazine[i]]++;
    }
    // map içerisine yerleştirilen karakterler ransomNote içerisinde kullanıldıkca azatılacak
    for (int j = 0; j < ransomNote.size(); j++)
    {
        if (map[ransomNote[j]] <= 0)
        {
            return false;
        }
        map[ransomNote[j]]--;
    }
    return true;
}

int main()
{
    vector<string> ransomNotes = {"aab", "aa", "a", "aa"};
    vector<string> magazines = {"baa", "aab", "b", "ab"};
    vector<string> expected = {"true", "true", "false", "false"};
    bool result;
    for (int i = 0; i < ransomNotes.size(); i++)
    {
        result = canConstruct(ransomNotes[i], magazines[i]);
        cout << ransomNotes[i] << "---->" << magazines[i] << "---->" << expected[i] << "---->" << result << endl;
    }
    return 0;
}