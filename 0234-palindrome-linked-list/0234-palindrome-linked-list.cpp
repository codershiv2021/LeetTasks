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
    ListNode* Reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            auto Next = head->next;
            head->next= prev;
            prev = head;
            head = Next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        auto fast = head;
        auto slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = Reverse(slow);
        while(head && slow){
            if (head->val!= slow->val){
                return false;
            }
            head= head->next;
            slow = slow->next;
        }
        return true;

    }
};