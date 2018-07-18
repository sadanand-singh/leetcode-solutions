#
# [5] Longest Palindromic Substring
#
# https://leetcode.com/problems/longest-palindromic-substring/description/
#
# algorithms
# Medium (25.58%)
# Total Accepted:    342.1K
# Total Submissions: 1.3M
# Testcase Example:  '"babad"'
#
# Given a string s, find the longest palindromic substring in s. You may assume
# that the maximum length of s is 1000.
# 
# Example 1:
# 
# 
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# 
# Input: "cbbd"
# Output: "bb"
# 
# 
#
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        start = 0
        end = 0
        
        def expand(s, left, right):
            i = left
            j = right
            
            while i>=0 and j<len(s) and s[i]==s[j]:
                j+=1
                i-=1
            return j-i-1
        
        for i in range(len(s)):
            l1 = expand(s,i,i)
            l2 = expand(s,i,i+1)
            print(l1, l2)
            l = max(l1,l2)
            
            if l > (end-start):
                start = i - (l-1)//2
                end = i + l//2
        
        return s[start:end+1]
    
        
        
        
        
