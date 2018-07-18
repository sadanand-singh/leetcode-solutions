#
# [329] Longest Increasing Path in a Matrix
#
# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
#
# algorithms
# Hard (37.61%)
# Total Accepted:    57K
# Total Submissions: 151.7K
# Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
#
# Given an integer matrix, find the length of the longest increasing path.
# 
# From each cell, you can either move to four directions: left, right, up or
# down. You may NOT move diagonally or move outside of the boundary (i.e.
# wrap-around is not allowed).
# 
# Example 1:
# 
# 
# Input: nums = 
# [
# ⁠ [9,9,4],
# ⁠ [6,6,8],
# ⁠ [2,1,1]
# ] 
# Output: 4 
# Explanation: The longest increasing path is [1, 2, 6, 9].
# 
# 
# Example 2:
# 
# 
# Input: nums = 
# [
# ⁠ [3,4,5],
# ⁠ [3,2,6],
# ⁠ [2,2,1]
# ] 
# Output: 4 
# Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
# is not allowed.
# 
# 
#
class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        rows = len(matrix)
        if rows == 0:
            return 0
        cols = len(matrix[0])
        if cols == 0:
            return 0
        
        cache = [[0]*cols]*rows
        
        m = 0
        for i in range(rows):
            for j in range(cols):
                cmax = self.findMax(j, i, matrix, cache, float("inf"))
                m = max(m,cmax)
                
        return m
    
    def findMax(self, i, j, mat, cache, prev):
        """ Do all movements until >= number found"""
        
        cols = len(mat[0])
        rows = len(mat)
        if i < 0 or i >= rows or j < 0 or j >= cols or mat[i][j] >= prev:
            return 0
        if cache[i][j] > 0:
            return cache[i][j]
        
        cur = mat[i][j]
        tempMax = 0
        tempMax = max(self.findMax(i - 1, j, mat, cache, cur), tempMax)
        tempMax = max(self.findMax(i + 1, j, mat, cache, cur), tempMax)
        tempMax = max(self.findMax(i, j - 1, mat, cache, cur), tempMax)
        tempMax = max(self.findMax(i, j + 1, mat, cache, cur), tempMax)
        tempMax += 1
        cache[i][j] = tempMax
        
        return tempMax
        
        
# public class Solution {
#     public int longestIncreasingPath(int[][] matrix) {
#         if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
#             return 0;
#         }
#         int[][] cache = new int[matrix.length][matrix[0].length];
#         int max = 0;
#         for (int i = 0; i < matrix.length; i++) {
#             for (int j = 0; j < matrix[0].length; j++) {
#                 int length = findSmallAround(i, j, matrix, cache, Integer.MAX_VALUE);
#                 max = Math.max(length, max);
#             }
#         }
#         return max;
#     }
#     private int findSmallAround(int i, int j, int[][] matrix, int[][] cache, int pre) {
#         // if out of bond OR current cell value larger than previous cell value.
#         if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || matrix[i][j] >= pre) {
#             return 0;
#         }
#         // if calculated before, no need to do it again
#         if (cache[i][j] > 0) {
#             return cache[i][j];
#         } else {
#             int cur = matrix[i][j];
#             int tempMax = 0;
#             tempMax = Math.max(findSmallAround(i - 1, j, matrix, cache, cur), tempMax);
#             tempMax = Math.max(findSmallAround(i + 1, j, matrix, cache, cur), tempMax);
#             tempMax = Math.max(findSmallAround(i, j - 1, matrix, cache, cur), tempMax);
#             tempMax = Math.max(findSmallAround(i, j + 1, matrix, cache, cur), tempMax);
#             cache[i][j] = ++tempMax;
#             return tempMax;
#         }
#     }
# }        
        
