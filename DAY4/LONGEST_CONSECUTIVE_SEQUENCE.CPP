/*
LONGEST CONSECUTIVE SEQUENCE
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

Problrm link : https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hash;
        int len = 0;
        int count=1;
        
        for(int num : nums){
            hash.insert(num);
        }
        
        for(int i=0;i<nums.size();i++){
            if(!(hash.count(nums[i]-1))){
                int ele = nums[i]+1;
                count =1;
                while(hash.count(ele)){
                    count++;
                    ele = ele+1;
                }
                
                len = max(len,count);
            }
            
        }
        return len;
    }
};
//O(3N) O(N)
