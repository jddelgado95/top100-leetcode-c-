/*
https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

/*
Create a hash table and check for the freq of each element or sort the array and compare them
*/

#include<iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t; 
    }
};

int main() {
    Solution sol;

    string str1 = "listen";
    string str2 = "silent";
    string str3 = "hello";

    cout << "Test 1 (\"listen\" vs \"silent\"): ";
    cout << (sol.isAnagram(str1, str2) ? "True" : "False") << endl;

    cout << "Test 2 (\"listen\" vs \"hello\"): ";
    cout << (sol.isAnagram(str1, str3) ? "True" : "False") << endl;

    return 0;
}