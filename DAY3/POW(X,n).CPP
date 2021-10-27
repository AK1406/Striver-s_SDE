/* 
POW(X,n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

Problem link : https://leetcode.com/problems/powx-n/

*/
class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        long long pow = n;
        if(pow < 0){
            pow = -1*pow;
        }
        while(pow){
        if(pow % 2){
            ans *= x;
            pow = pow-1;
        }else{
            x = x*x;
            pow = pow/2;
        }
    }
        if(n < 0){
            ans = (1.0)/ans;
        }
        return ans;
    }
};

//Binary Exponentiation
//O(log(n))
