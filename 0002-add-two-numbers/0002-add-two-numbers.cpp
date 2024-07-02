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
    int sizeiof( ListNode* l){
        int n =0;
        while(l){
            n++;
            l= l->next;
        }
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1= sizeiof(l1);
        int n2 = sizeiof(l2);
        if (n2>n1){
            return addTwoNumbers(l2, l1);
        }
        // int carry =0;
        // auto ans = l1;
        // while(l1){
        //     int sec_no =0;
        //     if (l2){
        //          sec_no = l2->val;
        //          l2= l2->next;
        //     }
        //     int yt = l1->val+ sec_no + carry;
        //     l1->val = yt%10;
        //     carry = yt/10;
        //     if (!l1->next && carry>0){
        //         l1->next= new ListNode(carry);
        //         break;
        //     }
        //     l1= l1->next;
        // }
        auto ans = l1;
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

        return ans;
    }
};