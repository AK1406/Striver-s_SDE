/*
CHECK FOR PALINDROMIC LINKED LIST
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Problem link : https://leetcode.com/problems/palindrome-linked-list/
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
    
    
    ListNode* reverseHalfList(ListNode* head){
        ListNode* pre =NULL;
        ListNode* nxt = NULL;
        while(head != NULL){
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* f = head;
        ListNode* s =head;
        
        while(f->next != NULL && f->next->next != NULL){
            f= f->next->next;
            s=s->next;
        }
        
        s->next = reverseHalfList(s->next);
        s = s->next;
        
        while(s != NULL){
            if(head->val != s->val){
                return false;
            }
            head = head->next;
            s=s->next;
        }
        return true;
        
    }
};
