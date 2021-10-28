/*
REVERSE PAIRS
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1

Problem link : https://leetcode.com/problems/reverse-pairs/
*/

class Solution {
public:
    
    
    int merge(vector<int> &arr,int l,int mid,int r){
        
        int j=mid+1;
        int count =0;
        for(int i=l;i<=mid;i++){
            while(j <= r && arr[i] > (2 * (long)arr[j])){
               j++; 
            }
            count += (j-(mid+1));
        }
        
        vector<int>temp;
        
        int left = l,right = mid+1;
        while(left <= mid && right <= r){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        
        while(right <= r){
            temp.push_back(arr[right++]);
        }
        
        for(int i=l;i<=r;i++){
            arr[i] = temp[i-l];
        }
        return count;
        
    }
    
    int mergeSort(vector<int> &arr,int l,int r){
        if(l>=r){
            return 0;
        }
        
        int mid = (l+r)/2;
        int inv = mergeSort(arr,l,mid);
        inv += mergeSort(arr,mid+1,r);
        inv += merge(arr,l,mid,r);
            
        return inv;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
       return mergeSort(nums,0,nums.size()-1);
    }
};

//Merge sort
//O(nlogn)[merge operation]+O(n)[count]   O(n)
