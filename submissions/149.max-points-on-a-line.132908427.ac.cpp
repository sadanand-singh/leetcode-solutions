/*
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (15.22%)
 * Total Accepted:    96.8K
 * Total Submissions: 635.9K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given n points on a 2D plane, find the maximum number of points that lie on
 * the same straight line.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[2,2],[3,3]]
 * Output: 3
 * Explanation:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * Explanation:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 * 
 * 
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        
        int result = 0;
        
        int n = points.size();
        
        if(n<2) return n;
        
        std::function<int(int, int)> gcd;
        gcd = [&gcd](int a, int b) -> int
        {
            if (b == 0)
                return a ;
            else 
                return gcd(b, a%b);
        };
        
        for(int i = 0; i < n-1; ++i)
        {
            map<pair<int,int>,int> slopes;
            int verticals = 0; 
            int overlaps = 0;
            int localmax = 0;
            
            for(int j = i+1; j < n; ++j)
            {
                if(points.at(i).x == points.at(j).x && points.at(i).y == points.at(j).y)
                {
                    overlaps++;
                    continue;
                }
                
                int slopeDenom = points.at(i).x-points.at(j).x;
                if(slopeDenom == 0) verticals++;
                else{
                    int slopeNumerator = points.at(i).y-points.at(j).y;
                    auto gcdVal = gcd(slopeNumerator, slopeDenom);
                    slopeDenom /= gcdVal;
                    slopeNumerator /= gcdVal;
                    slopes[make_pair(slopeNumerator, slopeDenom)]++;
                    localmax=max(slopes[make_pair(slopeNumerator, slopeDenom)], localmax);
                }
                localmax = max(localmax, verticals);
            }
            result = max(localmax+overlaps+1, result);
        }
        
        return result;
        
    }
    
private:
    
    int gcd2(int a, int b)
    {
        if (b == 0)
            return a ;
        else 
            return gcd2(b, a%b);
    }
        
    
};
