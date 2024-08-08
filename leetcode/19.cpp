//problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* a=head;
        while(a)
        {
            count++;
            a=a->next;
        }
        count=count-n;
        a=head;
        ListNode* prev=head;

        if(count<0)
            return NULL;
        if(count==0)
            return head->next;

        for(int i=1;i<=count;i++)
        {
            prev = a;
            a = a->next;
        }

        prev->next = a->next;
        return head;
            
    }
};
