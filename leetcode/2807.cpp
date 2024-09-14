// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
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
    int GCD(int a,int b){
        return __gcd(a,b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* ans=head;
        while(head->next){
            int x=GCD(head->val,head->next->val);
            ListNode* temp=new ListNode(x);
            temp->next=head->next;
            head->next=temp;
            head=temp->next;
        }
        return ans;
    }
};
