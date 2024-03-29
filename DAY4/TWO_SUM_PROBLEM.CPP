/*
TWO SUM PROBLEM

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

Problem link : https://leetcode.com/problems/two-sum/

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        unordered_map<int,int>hmp;
        
        for(int i =0;i<nums.size();i++){
            
            if(hmp.find(target-nums[i]) != hmp.end()){
                ans.push_back(hmp[target-nums[i]]);
                ans.push_back(i);
                
                return ans;
            }
            hmp[nums[i]]=i;
        }
        return ans;
    }
};

//Hashing
//O(n) O(n)
