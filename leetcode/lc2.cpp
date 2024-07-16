//problem: https://leetcode.com/problems/add-two-numbers/

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>s1;
        vector<int>s2;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL)
        {
            s1.push_back(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            s2.push_back(temp2->val);
            temp2 = temp2->next;
        }

        ListNode* res = new ListNode(0);
        ListNode* orig_res = res;
        int extra = 0;
        while(1)
        {

            if(s1.empty() && s2.empty())
            {
                if(extra)
                {
                    res->val = extra;
                    res->next = new ListNode();
                }
                break;
            }

            int num1=0, num2=0;
            if(!s1.empty())
                 {num1 = s1.front();s1.pop();}

            if(!s2.empty())
             {num2 = s2.front();s2.pop();}

            int sum = num1+num2+extra;
            extra = sum / 10;
            sum = sum % 10;

            res->val = sum;
            res->next = new ListNode();
        }


        return orig_res;
    }
};
