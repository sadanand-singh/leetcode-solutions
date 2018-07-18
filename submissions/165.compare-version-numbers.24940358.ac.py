#
# [165] Compare Version Numbers
#
# https://leetcode.com/problems/compare-version-numbers/description/
#
# algorithms
# Medium (21.18%)
# Total Accepted:    105K
# Total Submissions: 495.7K
# Testcase Example:  '"0.1"\n"1.1"'
#
# Compare two version numbers version1 and version2.
# If version1 > version2 return 1; if version1 < version2 return -1;otherwise
# return 0.
#
# You may assume that the version strings are non-empty and contain only digits
# and the . character.
# The . character does not represent a decimal point and is used to separate
# number sequences.
# For instance, 2.5 is not "two and a half" or "half way to version three", it
# is the fifth second-level revision of the second first-level revision.
#
# Example 1:
#
#
# Input: version1 = "0.1", version2 = "1.1"
# Output: -1
#
# Example 2:
#
#
# Input: version1 = "1.0.1", version2 = "1"
# Output: 1
#
# Example 3:
#
#
# Input: version1 = "7.5.2.4", version2 = "7.5.3"
# Output: -1
#
#
class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        if version1.find(".") == -1:
            nums1 = [version1]
        else:
            nums1 = version1.split(".")

        if version2.find(".") == -1:
            nums2 = [version2]
        else:
            nums2 = version2.split(".")

        l1 = len(nums1)
        l2 = len(nums2)

        if l1 < l2:
            zeros = ["0"] * (l2 - l1)
            nums1.extend(zeros)
        if l1 > l2:
            zeros = ["0"] * (l1 - l2)
            nums2.extend(zeros)

        ls = len(nums1)

        for l in range(0, ls):
            if float(nums1[l]) > float(nums2[l]):
                return 1
            if float(nums1[l]) < float(nums2[l]):
                return -1

        return 0
