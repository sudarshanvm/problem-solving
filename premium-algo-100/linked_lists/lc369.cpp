//problem : https://leetcode.com/problems/plus-one-linked-list/

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
    int carry = 0;
public:

    void solve(ListNode* head)
    {
        if(!head)
            return;

        if(head->next==NULL)
        {
            head->val += 1;
            carry = head->val / 10;
            head->val %= 10;
            return;
        }

        solve(head->next);
        head->val += carry;
        carry = head->val / 10;
        head->val %= 10;

        return;
    }

    ListNode* plusOne(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head;

        if(!head)
            return head;

        solve(head);

        if(carry)
        {
            ListNode* temp = new ListNode(carry, head);
            return temp;
        }

        return head;
    }
};
