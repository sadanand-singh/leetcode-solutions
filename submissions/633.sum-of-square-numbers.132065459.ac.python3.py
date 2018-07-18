#
# [633] Sum of Square Numbers
#
# https://leetcode.com/problems/sum-of-square-numbers/description/
#
# algorithms
# Easy (32.39%)
# Total Accepted:    27.4K
# Total Submissions: 84.7K
# Testcase Example:  '5'
#
# 
# Given a non-negative integer c, your task is to decide whether there're two
# integers a and b such that a2 + b2 = c.
# 
# 
# Example 1:
# 
# Input: 5
# Output: True
# Explanation: 1 * 1 + 2 * 2 = 5
# 
# 
# 
# 
# Example 2:
# 
# Input: 3
# Output: False
# 
# 
# 
#
class Solution:
    def judgeSquareSum(self, c):
        def is_square(N):
            return int(N**.5)**2 == N
        
        return any(is_square(c - a*a) for a in range(int(c**.5) + 1))
        
