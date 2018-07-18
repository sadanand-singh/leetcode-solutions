/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (48.73%)
 * Total Accepted:    254.8K
 * Total Submissions: 522.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> numss(nums);
        sort(numss.begin(), numss.end());
        vector<vector<int>> result;
        do {
            result.push_back(numss);
        } while (next_permutation(numss.begin(), numss.end()));
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
        
//         vector<vector<int>> res;
        
//         permuteRec(nums, 0, res);
        
//         return res; 
//     }
    
//     void permuteRec(vector<int>& nums, int b, vector<vector<int>>& res)
//     {
//         int sz = nums.size();
//         if(b == sz) res.emplace_back(nums);
        
//         for(int i = b; i < sz; ++i)
//         {
//             std::swap(nums.at(b), nums.at(i));
//             permuteRec(nums, b+1, res);
//             std::swap(nums.at(b), nums.at(i));
//         }
//     }
// };
