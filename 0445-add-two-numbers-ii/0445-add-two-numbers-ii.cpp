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
    int Size(ListNode* head){
        int len = 0;
        while (head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* Reverse(ListNode* head){
        ListNode* temp = NULL;
        while(head){
            auto temp1= head->next;
            head->next= temp;
            temp = head;
            head = temp1;
        }
        return temp;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = Size(l1);
        int m = Size(l2);
        if (m>n){
            return addTwoNumbers(l2,l1);
        }
        l1 = Reverse(l1);
        auto L1= l1;
        l2= Reverse(l2);
        int carry =0;
        while(l1){
            int toadd=0;
            if (l2){
            toadd= l2->val;
            l2= l2->next;
            }
            int num = (toadd+carry+l1->val)%10;
            carry= (toadd+carry+l1->val)/10;
            l1->val = num;
            if (!l1->next){
                break;
            }
            l1= l1->next;
        }
        if (carry>0){
            l1->next= new ListNode(carry);
            l1= l1->next;
        }
        
        l1 = Reverse(L1);
        return l1;
    }
};