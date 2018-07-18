/*
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (23.89%)
 * Total Accepted:    98.9K
 * Total Submissions: 413.9K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 *
 * Example 1:
 *
 *
 * Input: [10,2]
 * Output: "210"
 *
 * Example 2:
 *
 *
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 *
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto sortOrder = [](const int& a, const int& b) -> bool
        {
            auto s1 = to_string(a);
            auto s2 = to_string(b);

            return (s1+s2) > (s2+s1);
        };

        sort(nums.begin(), nums.end(), sortOrder);

        //remove multiple zeros from begining of nums
        auto start = 0u;
        while(start < nums.size() && nums.at(start) == 0)
            start++;

        if(start == nums.size())
            start -= 1;

        string s = "";
        for(int i=start; i < nums.size(); i++)
        {
            auto x = nums.at(i);
            s += to_string(x);
        }

        return s;

    }
};
