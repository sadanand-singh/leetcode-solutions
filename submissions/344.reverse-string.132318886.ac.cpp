/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (60.90%)
 * Total Accepted:    269.5K
 * Total Submissions: 442.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 * 
 * 
 * Example:
 * Given s = "hello", return "olleh".
 * 
 */
class Solution {
public:
    string reverseString(string s) {
        
        int i = 0;
        int j = s.size()-1;
        while(i<j)
        {
            std::swap(s[i++],s[j--]);
        }
        return s;
        
    }
};
