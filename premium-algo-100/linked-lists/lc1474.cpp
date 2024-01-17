//problem: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/?envType=study-plan-v2&envId=premium-algo-100

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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *res = head, *prev=head;
        int mcount=0, ncount=0;
        while(head!=NULL)
        {
            for(int mcount=0;mcount<m;mcount++)
            {
                prev=head;
                if(head) head=head->next;
            }

            for(int ncount=0;ncount<n;ncount++)
                if(head)head=head->next;
            if(prev)
            prev->next=head;
        }
        return res;
    }
};
