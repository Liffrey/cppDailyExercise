//https://leetcode.com/problems/roman-to-integer/
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

//level: easy
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<numeric>
#include <bits/stdc++.h>
using namespace std;

    int romanToInt(string s) {
        //1. adım symbolleri sayıya çevir
        //2. adım matematiksel işlemler
        vector<int> result;
        map<char, int> roman;
        int r=0;
        roman.insert(pair<char,int>('I',1));
        roman.insert(pair<char,int>('V',5));
        roman.insert(pair<char,int>('X',10));
        roman.insert(pair<char,int>('L',50));
        roman.insert(pair<char,int>('C',100));
        roman.insert(pair<char,int>('D',500));
        roman.insert(pair<char,int>('M',1000));

        //roman['M']=1000;
        //value=roman.at('M');
        for(int i=0;i<s.size();i++)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                r+=roman[s[i+1]]-roman[s[i]];
                i++;
                continue;
            }
        r += roman[s[i]];
        }
        return r;
    }

int main()
{
    romanToInt("IX"); 
    //std::cout<<"hello world";
    return 0;
}