/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.32%)
 * Total Accepted:    226.3K
 * Total Submissions: 859.6K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 * 
 * 
 */
class Solution {
public:
    double myPow(double x, int n) {
        int div=n,mod=0;
        if(div==0){
            return 1;
        }
        if(div==1){
            return x;
        }
        else if(div==-1){
            return 1.0/x;
        }
        else{
            mod=n%2;
            div=n/2;
            double tmp=myPow(x,div);
            if(mod==0){
                return tmp*tmp;
            }
            else if(mod==-1){
                return tmp*tmp*1.0/x;
            }
            else{
                return tmp*tmp*x;
            }
        }
    }
};
