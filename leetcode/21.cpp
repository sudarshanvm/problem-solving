//problem: https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res;
        ListNode* a=list1;
        ListNode* b=list2;

        if(!a && !b)
            return NULL;
        if(!a)
            return b;
        if(!b)
            return a;

        if(a->val <= b->val)
        {
                res = new ListNode(a->val);
                a = a->next;
        }
        else
        {
                res = new ListNode(b->val);
                b = b->next;
        }

        ListNode* dummy = res;

        while(a&&b)
        {
            if(a && b && a->val <= b->val)
            {
                ListNode* temp = new ListNode(a->val);
                res->next = temp;
                a = a->next;
            }

            else
            {
                ListNode* temp = new ListNode(b->val);
                res->next = temp;
                b = b->next;
            }
            res = res->next;
        }


        if(a)
            res->next=a;
        if(b)
            res->next=b;

        return dummy;
    }
};
