/*
ROTATE LINKED LIST
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

Problem link : https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head ==NULL || head-> next == NULL || k==0) return head;
        
        ListNode* curr = head;
        int len =1;
        
        while(curr->next != NULL){
            len++;
            curr = curr->next;
        }
        
        curr-> next = head;
        k=k%len;
        k= len-k;
        
        while(k--){
            curr=curr->next;
        }
        
        head=curr->next;
        curr->next = NULL;
        
        return head;
    }
};
// O(n)+O(n-(n%k))  O(1)
