// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06
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

    ListNode* deleteNodes(ListNode* head, unordered_set<int> &s)
    {
        ListNode* res = new ListNode();
        res->next=head;
        ListNode* cur=head;
        ListNode* prev=res;
        while(cur)
        {
            if(s.find(cur->val)!=s.end())
            {
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        return res->next;
    }

    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* res=head;
        unordered_set<int>nums_set(nums.begin(),nums.end());
        res=deleteNodes(head,nums_set);
        return res;
    }
};
