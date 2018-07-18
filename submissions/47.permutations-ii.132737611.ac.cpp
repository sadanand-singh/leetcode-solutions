/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (36.00%)
 * Total Accepted:    174.9K
 * Total Submissions: 485.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> numss(nums);
        sort(numss.begin(), numss.end());
        vector<vector<int>> result;
        do {
            result.push_back(numss);
        } while (next_permutation(numss.begin(), numss.end()));
        return result;
    }
};
