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

//  bool cmp(ListNode* a, ListNode* b){
//         return a->val<b->val;
//     }

class Solution {
public:
        static bool cmp(ListNode* a, ListNode* b) {
        return a->val < b->val;
    }

    ListNode* t(ListNode* head, ListNode* mx){
        if (!head){return mx;}
        ListNode* mp= head;
        ListNode* pq= mp;
        head= head->next;
        while (head && mx){
        if (head->val>=mx->val){
            mp->next= mx;
            mp= mp->next;
            mx= mx->next;
        }
        else{
            mp->next= head;
            mp= mp->next;
            head= head->next;
        }
        }
        while (head){
            mp->next= head;
            mp= mp->next;
            head= head->next;
        }
        while (mx){
            mp->next= mx;
            mp= mp->next;
            mx= mx->next;
        }
        return pq;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>v;
        for (auto i: lists){
            if (i){
                v.push_back(i);
            }
        }
        if (v.empty()){
            return NULL;
        }
        
        sort(v.begin(),v.end(),cmp);
        ListNode* head= v[0];
        for (int i=1; i<v.size(); i++){
            head= t(head,v[i]);
        }
        return head;

    }
};