/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (38.79%)
 * Total Accepted:    150.2K
 * Total Submissions: 387.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        std::unordered_set<int> s(nums.begin(), nums.end());
        
        int longestStreak = 0;
        
        auto isContained = [&s](const int& n)->bool
        {
            return (s.find(n)==s.end())?false:true;
        };
        
        for(const auto& n : s)
        {
            if (!isContained(n-1))
            {
                int currentNum = n;
                int currentStreak = 1;
                
                while(isContained(currentNum+1))
                {
                    ++currentNum;
                    ++currentStreak;
                }
                
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
        
    }
};
