//! template version 2.0
// https://leetcode.com/problems/first-unique-character-in-a-string/
//  Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:

// Input: s = "leetcode"
// Output: 0
// Example 2:

// Input: s = "loveleetcode"
// Output: 2
// Example 3:

// Input: s = "aabb"
// Output: -1

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

// level:easy
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// tüm karakterlerin üzerinden geç
// her karakterin kaç kere karşılatığını bul
// eğer tekrar eden karakter yoksa ilk tekrar etmeyen karakterin indexini don
// değilse -1 dön

// map ve queue

int firstUniqChar(string s)
{
    //MAP (arancak kelimedeki karakterler, karakterlerle kaç defa karşılaşıldığı sayısı)
    unordered_map<char,int> map;

    for (int i = 0; i < s.size(); i++)
    {
        //map olustur
        map[s[i]] = 0; //yazma
    }
    for (int i=0;i<s.size();i++)
    {
        map[s[i]] /*yazma*/= map.at(s[i])+1;/*oku+1*/
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (map.at(s[i])==1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<string> test = { "loveleetcode" };
    int result;
    result = firstUniqChar(test[0]);
    cout << result;
    return 0;
}