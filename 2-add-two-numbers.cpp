// https://leetcode.com/problems/add-two-numbers/
// space O(n)
// time O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        int sum,carry = 0;
        ListNode *last = head;
        while(l1 || l2 || carry)
        {
            sum = carry;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            last->next = new ListNode(sum%10);   
            last = last->next;
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head->next;
    }
};
