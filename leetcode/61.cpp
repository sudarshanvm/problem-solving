//problem: https://leetcode.com/problems/rotate-list/

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
        int n=0;
        if(!head || !head->next)
            return head;

        ListNode* cur = head;
        while(cur)
        {
            n++;
            cur = cur->next;
        }

        k = n-k%n;

        ListNode* prev = NULL;
        cur = head;

        for(int i=1;i<=k;i++)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = NULL;
        ListNode* res = cur;
        while(cur && cur->next)
        {
            cur = cur->next;
        }

        if(!cur)
            res = head;
        else
            cur->next = head;

        return res;


        
    }
};
