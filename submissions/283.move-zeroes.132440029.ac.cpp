/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (52.00%)
 * Total Accepted:    314.5K
 * Total Submissions: 604.9K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        int sz = nums.size();
        
        for(int i = 0, k=0; i < sz ; ++i)
        {
            if(nums.at(i) != 0)
            {
                if (k != i)
                    std::swap(nums[k++], nums[i]);
                else
                    k++;
            }
        }
        
        
    }
};
