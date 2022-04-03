//! template version 1.4
// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0

// level:easy

#include <string>
#include <iostream>
#include <vector>
using namespace std;

int findSecond(string s)
{
    int secondOccurance = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[0] == s[i])
        {
            secondOccurance = i;
            return secondOccurance;
        }
    }
    return s.length();
}

int strStr(string haystack, string needle)
{
    int counter = 0;
    int firstMatch = 0;
    bool fullMatch = true;

    if (needle == "")
        return 0;

    if (needle.length() > haystack.length())
    {
        return -1;
    }

    // for: ilk for needle'ı hay tamanında ara for: tek karakter; bu da needle ilk karaketeri
    for (int i = 0; i < haystack.length(); i++)
    {
        fullMatch = true;
        //      if: ilk karakter eşleşmişse  // aaaaa : bb , // hello : la  // "helallo", "ll"
        if (needle[0] == haystack[i])
        {
            //for: eşleşme olduktan sonraki karakterler arasında needle'ın boyu kadar ara
            for (int j = i + 1, k = 1; k < needle.length(); j++, k++)
            {
                //  if: needle'ın geri kalan tüm karakterleri haystack'ın içinde var mı?
                // hello - ll --> lo - l 
                // mississippi - sippi 
                // mississippi - sippi  *  i=2, j=3, k=1
                // 01234567890 - 01234

                // mississippi - sippi  *  i=3, j=4, k=2
                // 01234567890 - 01234
                //    *-/
                
                // mississippi - sippi  *  i=5, j=6, k=1
                // 01234567890 - 01234
                //      */
                if (needle[k] != haystack[j])
                {
                    fullMatch = false;
                    cout<<"k="<<k<<" "<<"j="<<j<<" "<<"i="<<i<<endl;
                    i += min(k, findSecond(needle));
                    cout<<"artacak i= "<<i<<endl;
                }
            }
            // if: needle var ise sonucu dön
            if (fullMatch)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    // cout << strStr("aaaaa", "bb") << "-->-1" << endl;
    // cout << strStr("hello", "ll") << "-->2" << endl;
    // cout << strStr("helallo", "ll") << "-->4" << endl;
    // cout << strStr("helallo", "") << "-->0" << endl;
    // cout << strStr("helallo", "lllllllll") << "-->-1" << endl;
    // cout << strStr("", "") << "-->0" << endl;
    // cout << strStr("looloooloolloo", "ollo") << "-->9" << endl;
    //cout << strStr("mississippi", "issip") << " --> 4" << endl;
    cout << strStr("mississippi", "sippi") << " --> 6" << endl;
    // cout << strStr("huseyihuseyihuseyin husey", "ihuseyin") << " --> 11" << endl;
    return 0;
}
