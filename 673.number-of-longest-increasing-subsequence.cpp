/*
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (31.97%)
 * Total Accepted:    18.2K
 * Total Submissions: 56.9K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 *
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 *
 *
 * Example 1:
 *
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 *
 *
 *
 * Example 2:
 *
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 *
 *
 *
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 *
 */
class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        if (nums.size() <=1) return nums.size();

        std::vector<std::pair<int, int>> dp(nums.size(), std::make_pair(1, 1));  // {length, count} pair
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    if (dp[j].first >= dp[i].first) dp[i] = std::make_pair(dp[j].first + 1, dp[j].second);
                    else if (dp[j].first == dp[i].first - 1) dp[i].second += dp[j].second;
        auto ans = 0;
        auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool
        {
            return a.first < b.first;
        };
        auto result = std::max_element(dp.begin(), dp.end(), std::less<std::pair<int, int>>());
        auto longest = (*result).first;
        for (const auto& elem : dp) {
            auto length = elem.first;
            if (length == longest) {
                ans += elem.second;
            }
        }
        return ans;
    }
};
