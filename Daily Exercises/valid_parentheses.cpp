// !template version:1.0
// https://leetcode.com/problems/valid-parentheses/
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Example 4:
// Input: s = "({[]})"
// Output: true

// Example 5:
// Input: s = "(5+5)+(5+4)"
// Output: true

// Example 6:
// Input: s = "(5+4("
// Output: false

// Example 7:
// Input: s = ")(()()())"
// Output: false

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

// level:easy
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
  // her açılan parantez karşılığı ile kapanmak zorunda.
  string acan = "{([";
  string kapatan = "})]";
  // açılan her parantez bir yerde tutulacak.
  stack<char> stack;

  for (int i = 0; i < s.length(); i++)
  {
    for (int j = 0; j < acan.size(); j++)
    {
      if (kapatan[j] == s[i] && stack.empty())
      {
        stack.push(s[i]);
        // cout<<"kapatana girdi"<<endl;
        return false;
      }
      if (acan[j] == s[i])
      {
        // cout<<"acana girdi"<<endl;
        stack.push(s[i]);
      }
      // stack içine atılanları kapatılanlarla karşılaştır eğer denk geliyorsa stackten cıkar bitene kadar.

      if (kapatan[j] == s[i] && acan[j] == stack.top())
      {
        // cout<<"pop a girdi"<<endl;
        stack.pop();
      }
      else if(kapatan[j] == s[i] && acan[j] != stack.top())
      {
        return false;
      }
    }
  }
  // sonuc durumu stackin boş ya da dolu olması durumu
  if (!stack.empty())
    return false;
  else
    return true;
}

int main()
{
  bool output;
  vector<bool> beklenen{true, true, false, true, false, false, false, false};
  vector<string> test{"()", "()[]{}", "(]", "({[]})", "[", "}", "}}}", "(])"};
  for (int i = 0; i < test.size(); i++)
  {
    output = isValid(test[i]);
    cout << "sonuc= " << output << " ------- "
         << "beklenen= " << beklenen[i] << endl;
  }
  return 0;
}