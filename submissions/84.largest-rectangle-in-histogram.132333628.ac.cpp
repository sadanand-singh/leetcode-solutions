/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (28.13%)
 * Total Accepted:    125.4K
 * Total Submissions: 445.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    
        int size = heights.size();
        
        if (size == 0) return 0;
        
        vector<int> leftIndices(size, 0);
        vector<int> rightIndices(size, 0);
        
        leftIndices[0] = -1;
        rightIndices[size-1] = size;
        
        //collect left indices
        for(int i = 1; i < size; ++i)
        {
            int p = i - 1;
            while(p >= 0 && heights.at(p) >= heights.at(i))
            {
                p = leftIndices.at(p);
            }
            leftIndices[i] = p;
        }
        
        //collect right indices
        for(int i = size-2; i >= 0; --i)
        {
            int p = i + 1;
            while(p < size && heights.at(p) >= heights.at(i))
            {
                p = rightIndices.at(p);
            }
            rightIndices[i] = p;
        }
        
        int maxRect = 0;
        for(int i = 0; i< size; ++i)
        {
            maxRect = std::max(maxRect, heights.at(i)*(rightIndices.at(i)-leftIndices.at(i)-1));
        }
        return maxRect;
    }
};
