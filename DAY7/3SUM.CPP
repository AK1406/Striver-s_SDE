/*
3SUM 
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105


*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        
        for(int i=0;i<(int) nums.size()-2;i++){
            if(i==0 || ( i > 0 && nums[i] != nums[i-1])){
                int j=i+1,k=(int)nums.size()-1, sum = 0-nums[i];
                while(j<k){
                    if(nums[j]+nums[k]==sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                         temp.push_back(nums[j]);
                         temp.push_back(nums[k]);
                         ans.push_back(temp);
                        
                        while(j<k && nums[j] == nums[j+1]) j++;
                        while(k>j && nums[k] == nums[k-1]) k--;
                        
                        j++;k--;
                    }
                    else if(nums[j]+nums[k] < sum)j++;
                    else k--;
                }
            }
        }
        return ans;
    }
};
//O(nxn)  O(n)
