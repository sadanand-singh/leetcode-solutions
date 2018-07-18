#
# [290] Word Pattern
#
# https://leetcode.com/problems/word-pattern/description/
#
# algorithms
# Easy (33.72%)
# Total Accepted:    110K
# Total Submissions: 326.1K
# Testcase Example:  '"abba"\n"dog cat cat dog"'
#
# Given a pattern and a string str, find if str follows the same pattern.
#
# Here follow means a full match, such that there is a bijection between a
# letter in pattern and a non-empty word in str.
#
# Example 1:
#
#
# Input: pattern = "abba", str = "dog cat cat dog"
# Output: true
#
# Example 2:
#
#
# Input:pattern = "abba", str = "dog cat cat fish"
# Output: false
#
# Example 3:
#
#
# Input: pattern = "aaaa", str = "dog cat cat dog"
# Output: false
#
# Example 4:
#
#
# Input: pattern = "abba", str = "dog dog dog dog"
# Output: false
#
# Notes:
# You may assume pattern contains only lowercase letters, and str contains
# lowercase letters separated by a single space.
#


class Solution:
    def wordPattern(self, pattern, data):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        if not data:
            return False
        words = data.split()
        if len(pattern) != len(words):
            return False
        mapping = {}

        for char, word in zip(pattern, words):
            if char in mapping:
                if mapping[char] != word:
                    return False
            else:
                if word in mapping.values():
                    return False
                mapping[char] = word

        return True
