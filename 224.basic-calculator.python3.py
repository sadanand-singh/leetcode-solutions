#
# [224] Basic Calculator
#
# https://leetcode.com/problems/basic-calculator/description/
#
# algorithms
# Hard (29.26%)
# Total Accepted:    70.9K
# Total Submissions: 242.3K
# Testcase Example:  '"1 + 1"'
#
# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string may contain open ( and closing parentheses ), the plus
# + or minus sign -, non-negative integers and empty spaces  .
#
# Example 1:
#
#
# Input: "1 + 1"
# Output: 2
#
#
# Example 2:
#
#
# Input: " 2-1 + 2 "
# Output: 3
#
# Example 3:
#
#
# Input: "(1+(4+5+2)-3)+(6+8)"
# Output: 23
# Note:
#
#
# You may assume that the given expression is always valid.
# Do not use the eval built-in library function.
#
#
#


class Solution:
    # @param {string} s
    # @return {integer}
    def calculate(self, s):
        tokens = self.toRPN(s)
        return self.evalRPN(tokens)

    operators = ["+", "-", "*", "/"]

    def toRPN(self, s):
        tokens, stack = [], []
        number = ""
        for c in s:
            if c.isdigit():
                number += c
            else:
                if number:
                    tokens.append(number)
                    number = ""
                if c in self.operators:
                    while len(stack) and self.getPriority(
                        stack[-1]
                    ) >= self.getPriority(c):
                        tokens.append(stack.pop())
                    stack.append(c)
                elif c == "(":
                    stack.append(c)
                elif c == ")":
                    while len(stack) and stack[-1] != "(":
                        tokens.append(stack.pop())
                    stack.pop()
        if number:
            tokens.append(number)
        while len(stack):
            tokens.append(stack.pop())
        return tokens

    def evalRPN(self, tokens):
        operands = []
        for token in tokens:
            if token in self.operators:
                y, x = operands.pop(), operands.pop()
                operands.append(self.getVal(x, y, token))
            else:
                operands.append(int(token))
        return operands[0]

    def getVal(self, x, y, operator):
        return {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: int(float(x) / y),
        }[operator](x, y)

    def getPriority(self, operator):
        return {"+": 1, "-": 1, "*": 2, "/": 2}.get(operator, 0)
