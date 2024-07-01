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
        //fast->next ho 
        if (!head){
            return head;
        }
        int len = 0;
        auto H = head;
        while(head){
            len++;
            head = head->next;
        }
        head = H;
        k = k%len;
        if(k==0){
            return head;
        }
        
        auto fast = head;
        auto slow = head;
        // while(k--){
        //     fast = fast->next;
        // }
        for (int i = 0; i < k; i++) {
        fast = fast->next;
    }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        //slow 
        auto Head = slow->next;
        slow->next= NULL;
        auto temp = Head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next= head;
        return Head;
      
    }
};