/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void T(TreeNode* root, vector<int>&v){
        if (!root){
            return;
        }
        T(root->left,v);
        v.push_back(root->val);
        T(root->right,v);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2;
        T(root1,v1);
        T(root2,v2);
        if (v1.size()==0){
            return v2;
        }
        if(v2.size()==0){
            return v1;
        }
        int i=0; int j=0;vector<int>v;
        int n = v1.size(); int m = v2.size();
        while(i<n && j<m){
            if (v1[i]<=v2[j]){
                v.push_back(v1[i]);
                i++;
            }
            else if (v1[i]>v2[j]){
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i<n){
            v.push_back(v1[i]);
            i++;
        }
        while(j<m){
            v.push_back(v2[j]);
            j++;
        }
        return v;
    }
};