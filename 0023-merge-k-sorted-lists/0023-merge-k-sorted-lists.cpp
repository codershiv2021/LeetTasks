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
    static bool cmp(ListNode* headA, ListNode* headB){
        if (!headA){
            return false;
        }
        if (!headB){
            return true;
        }
        return headA->val<headB->val;
    }
    ListNode* Merge(ListNode* head, ListNode* tempB){
        auto Head = head;
        ListNode* tempA = head->next;
        while(head && tempA && tempB){
            if (tempA->val<tempB->val){
                head->next= tempA;
                head = tempA;
                tempA= tempA->next;
            }
            else{
                head->next= tempB;
                head = tempB;
                tempB= tempB->next;
            }
        }
        if (tempA){
            head->next= tempA;
        }
        else{
            head->next= tempB;
        }
        return Head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n==0){
            return NULL;
        }
        
        sort(lists.begin(),lists.end(),cmp);
        if (!lists[0]){
            return NULL;
        }
        auto head = lists[0];
        
        //all null
        //nulls at last
        for (int i=1; i<n; i++){
            if (!lists[i]){continue;}
            head = Merge(head,lists[i]);
        }
        return head;
    }
};