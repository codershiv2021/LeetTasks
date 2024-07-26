class Solution {
public:

void marking(TreeNode* root,priority_queue<pair<pair<int,int>,int>,
vector<pair<pair<int,int>,int>>,
greater<pair<pair<int,int>,int>>>&pq, int a, int b){
    if (!root){
        return;
    }
    pq.push({{a,b},root->val});
    marking(root->left,pq,a-1,b+1);
    marking(root->right,pq,a+1,b+1);
    return;
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
priority_queue<pair<pair<int,int>,int>,
vector<pair<pair<int,int>,int>>,
greater<pair<pair<int,int>,int>>>pq; 

        marking(root,pq,0,0)        ;
        vector<vector<int>>ans;
        while (!pq.empty()){
            vector<int>temp;
            int col = pq.top().first.first;
            while(!pq.empty() && pq.top().first.first==col){
                int val = pq.top().second;
                temp.push_back(val);
                pq.pop();
            }
            ans.push_back(temp);
        }
    return ans;
    
    }
};