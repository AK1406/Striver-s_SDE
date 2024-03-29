/*
REVERSE NODES IN K GROUP

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:/**
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k == 1) return head;
        
        ListNode* dn = new ListNode(0);
        dn->next = head;
        ListNode* pre = dn;
        ListNode* curr = dn;
        ListNode* nxt = dn;
        
        int len =0;
        
        while(curr->next!=NULL){
            len++;
            curr = curr->next;
        }
        
        while(len >= k){
            curr = pre->next;
            nxt = curr->next;
            
            for(int i=1;i<k;i++){
            curr->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt= curr->next;
            
            }   
            
        pre = curr;
        len -= k;
        }
        
        
        return dn->next;
    }
};
// O((N/K)*K)  O(1)



Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz

Problem link : https://leetcode.com/problems/reverse-nodes-in-k-group/

*/

