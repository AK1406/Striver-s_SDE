/*
4SUM
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

Problem link : https://leetcode.com/problems/4sum/

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>>res;
        
        if(nums.size() ==0){
            return res;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                
                int target2 = target- (nums[i]+nums[j]);
                
                int front = j+1;
                int back = nums.size()-1;
                
                while(front<back){
                    int two_sum = nums[front]+nums[back];

                    if(two_sum < target2){
                        front++;
                    }else if(two_sum > target2){
                        back--;
                    }else{
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        res.push_back(quad);
                        
                        //processing the duplicates
                        while(front<back && nums[front] == quad[2]){
                            ++front;
                        }
                        
                        //processing the duplicates
                        while(front<back && nums[back] == quad[3]){
                            --back;
                        }
                        
                    }
                }
                
                //processing the duplicates
                while(i+1 < nums.size() && nums[i]==nums[i+1]){
                    ++i;
                }
                
                //processing the duplicates
                while(j+1 < nums.size() && nums[j]==nums[j+1]){
                    ++j;
                }
            }
        }
        return res;
        
    }
};
