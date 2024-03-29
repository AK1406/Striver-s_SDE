/*
MERGE SORT WITH NO EXTRA SPACE
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Problem link : https://leetcode.com/problems/merge-sorted-array/

*/

//GAP method//
class Solution {
public:
    
    //calculatr gap
    int gapCal(int gap){
        int newGap = 0;
        if(gap<=1){
            return 0;
        }
        newGap= (gap/2)+(gap%2);
        return newGap;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int G = m+n;
        int i,j;
         for(G=gapCal(G);G>0;G=gapCal(G)){
             for(i=0;G+i<m;i++){
                 if(nums1[i]>nums1[i+G]){
                     swap(nums1[i],nums1[i+G]);
                 }
             }
             for(j= G > m ? G-m:0;i < m && j < n;i++,j++){
                 if(nums1[i] > nums2[j]){
                     swap(nums1[i],nums2[j]);
                 }
             }
             if(j<n){
                 for(j=0;j+G < n;j++){
                     if(nums2[j] > nums2[j+G]){
                         swap(nums2[j],nums2[j+G]);
                     }
                 }
             }
         }
    }
};

//Rather than traversing from front which will require an extra space, traverse the arrays backwards and it will become similar 
//to normal problem of merging two sorted arrays.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        int i =m-1,j=n-1,k=m+n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }else{
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        
        while(i>=0){
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};



