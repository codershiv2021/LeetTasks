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
    int Size(ListNode* head){
        int sz= 0;
        while (head){
            sz++;
            head=head->next;
        }
        return sz;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = Size(headA);
        int m = Size(headB);
        if (m>n){
            return getIntersectionNode(headB,headA);
        }

        auto fast = headA;
        auto slow = headB;
        int cnt = n-m;
        while(cnt--){
            fast = fast->next;
        }
        while(fast!=slow){
            fast= fast->next;
            slow = slow->next;
        }
        return fast;
    }
};