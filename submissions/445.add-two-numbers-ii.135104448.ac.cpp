/*
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (46.70%)
 * Total Accepted:    54.8K
 * Total Submissions: 117.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int m = length(l1);
        int n = length(l2);
        
        if(m > n) l2 = padNode(l2, m-n);
        if(n > m) l1 = padNode(l1, n-m);
        m = max(m,n);
        
        int carry;
        ListNode* result;
        std::tie(result, carry) = getSum(l1, l2);
        
        if(carry != 0) result = insertBefore(result, carry);
        
        return result;
        
    }
    
    std::pair<ListNode*, int> getSum(ListNode* l1, ListNode* l2)
    {
        if(not l1 and not l2) return make_pair(nullptr, 0);
        
        ListNode* sum;
        int carry;
        
        std::tie(sum, carry) = getSum(l1->next, l2->next);
        
        int val = carry + l1->val + l2->val;
        carry = val/10;
        
        return make_pair(insertBefore(sum, val%10), carry);
    }
    
    int length(ListNode* n)
    {
        int l = 0;
        while(n)
        {
           ++l;
            n = n->next;
        }
        return l;
    }
    
    ListNode* padNode(ListNode* n, int count)
    {
        if(count == 0) return n;
        for(int  i = 0; i < count; ++i)
        {
            n = insertBefore(n, 0);
        }
        
        return n;       
    }
    
    ListNode* insertBefore(ListNode* n, int val)
    {
        ListNode *p = new ListNode(val);
        if(n) p->next = n;
        return p;
    }
};
