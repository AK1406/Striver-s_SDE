/*REPEATING AND MISSING NO IN GIVEN ARRAY

Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N

Problem Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

*/
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
    int *ans = new int[2];
       unordered_map<int,int> frq;
       
       for(int i = 0; i < n; i++)
           frq[arr[i]]++;
      //repeating no     
       for(auto i:frq)
           if(i.second > 1) ans[0] = i.first;
      //missing no     
       for(int i = 1; i <= n; i++)
           if(frq[i] == 0) ans[1] = i;
           
       return ans;
    }
};

//Striver's sol

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans=new int[2];
        long long int missingNo=0,repeatingNo=0;
        long long int S = (n*(n+1))/2;
        long long int P = (n*(n+1)*((2*n)+1))/6;
    
        for(int i=0;i<n;i++){
            S -= (long long int)arr[i];
            P-= (long long int)arr[i]*(long long int)arr[i];
        }
        missingNo = ((P/S) + S)/2;
        repeatingNo = missingNo-S;
        ans[0] = repeatingNo;
        ans[1]=missingNo;
        
        return ans;
    }
};

