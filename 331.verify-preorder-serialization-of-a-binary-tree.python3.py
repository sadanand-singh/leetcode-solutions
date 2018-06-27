#
# [331] Verify Preorder Serialization of a Binary Tree
#
# https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
#
# algorithms
# Medium (37.35%)
# Total Accepted:    47.1K
# Total Submissions: 126.2K
# Testcase Example:  '"9,3,4,#,#,1,#,#,2,#,6,#,#"'
#
# One way to serialize a binary tree is to use pre-order traversal. When we
# encounter a non-null node, we record the node's value. If it is a null node,
# we record using a sentinel value such as #.
#
#
# ⁠    _9_
# ⁠   /   \
# ⁠  3     2
# ⁠ / \   / \
# ⁠4   1  #  6
# / \ / \   / \
# # # # #   # #
#
#
# For example, the above binary tree can be serialized to the string
# "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
#
# Given a string of comma separated values, verify whether it is a correct
# preorder traversal serialization of a binary tree. Find an algorithm without
# reconstructing the tree.
#
# Each comma separated value in the string must be either an integer or a
# character '#' representing null pointer.
#
# You may assume that the input format is always valid, for example it could
# never contain two consecutive commas such as "1,,3".
#
# Example 1:
#
#
# Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
# Output: true
#
# Example 2:
#
#
# Input: "1,#"
# Output: false
#
#
# Example 3:
#
#
# Input: "9,#,#,1"
# Output: false
#
#
class Solution:
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """

        # data = preorder.split(',')
        # stack = []
        # top = -1

        # def endsWithTwoNull(l, t):
        #     if t < 1:
        #         return False
        #     if l[t] =='#' and l[t-1] =='#': return True
        #     return False

        # for d in data:
        #     stack.append(d)
        #     top += 1
        #     while endsWithTwoNull(stack, top):
        #         stack.pop()
        #         top -= 1
        #         stack.pop()
        #         top -= 1
        #         if top < 0: return False
        #         stack.pop()
        #         stack.append('#')
        # if len(stack) == 1 and stack[0] == '#': return True
        # return False

        p = preorder.split(',')

        #initially we have one empty slot to put the root in it
        slot = 1
        for node in p:

            # no empty slot to put the current node
            if slot == 0:
                return False

            # a null node?
            if node == '#':
                # ocuppy slot
                slot -= 1
            else:
                # create new slot
                slot += 1

        #we don't allow empty slots at the end
        return slot==0

