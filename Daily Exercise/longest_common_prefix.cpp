// https://leetcode.com/problems/longest-common-prefix/
// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.

// level:easy
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string result="";
    string temp=strs[0];
    int i=0,j=0,k=0;
//en az harfli kelimeyi bul???
    for(k=0;k<strs.size();k++)
    {
    if(strs[k].length()<temp.length())
    temp=strs[k];
    }

//vectorün en az karaktere sahip elemanının ilk harfini (n. satır elemanı) al vektorün diğer elemanlarının ilk harfi (n. satır elemanı ile) karşılaştır.
//eğer harf vektordeki tüm elemanlarının ayrı satırıyla aynı ise o harflari bir string içince tut.    
    for(j=0;j<temp.length();j++)
    {
        bool ortaksa = true;
        char ch;
        for(i=0;i<strs.size();i++)
        {

            if(temp[j]!=strs[i][j])
            {
            ortaksa = false;
            break;
            }
            ch = temp[j];
        }
        if (ortaksa) {result.push_back(ch);} else break;
    }
    cout<<result<<endl;

//edge caseleri belirle

    if(result!="" && strs.size()>1)
    return result;
    else if(strs.size()==1)
    return temp;
    else return "";
}


int main()
{
    string output;
    vector<string> test{"flower","flow","floght","fleak"};
    vector<string> test2{""};
    vector<string> test3{"flow123"};
    longestCommonPrefix(test); 
    //cout<<output<<endl;
    //std::cout<<"hello world";
    return 0;
}