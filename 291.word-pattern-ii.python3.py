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
# Input: pattern = "abba", str = "dogcatcatdog"
# Output: true
#
# Example 2:
#
#
# Input:pattern = "abba", str = "dogcatcatfish"
# Output: false
#
# Example 3:
#
#
# Input: pattern = "aaaa", str = "dogcatcatdog"
# Output: false
#
# Example 4:
#
#
# Input: pattern = "abba", str = "dogdogdogdog"
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
        self.char_mapping = {}
        self.word_set = set()
        if len(pattern) == 0 and len(data) == 0:
            return True
        if len(pattern) == 0:
            return False
        return self.helper(pattern, data, 0, 0)

    def helper(self, pattern, data, i, j):
        if i == len(pattern) and j == len(data):
            return True
        if i >= len(pattern) or j >= len(data):
            return False

        c = pattern[i]
        for k in range(j + 1, len(data) + 1):
            word = data[j:k]
            if c not in self.char_mapping and word not in self.word_set:
                self.char_mapping[c] = word
                self.word_set.add(word)
                if self.helper(pattern, data, i + 1, k):
                    return True
                self.char_mapping.pop(c, None)
                self.word_set.remove(word)
            elif c in self.char_mapping and self.char_mapping[c] == word:
                if self.helper(pattern, data, i + 1, k):
                    return True

        return False


if __name__ == "__main__":
    sol = Solution()
    patterns = ["abab", "aaaa", "aabb"]
    datalist = ["redblueredblue", "asdasdasdasd", "xyzabcxzyabc"]

    for pattern, data in zip(patterns, datalist):
        print(sol.wordPattern(pattern, data))
