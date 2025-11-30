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
    int d = 0; int cnt =0; TreeNode* ans;
    void T(TreeNode* root, int ind){
        if (!root){
            return;
        }
        if(ind > d){
            cnt = 0;
            cnt++;
        }
        else if (ind == d){
            cnt++;
        }
        d = max(d, ind);
        T(root->left, ind+1);
        T(root->right, ind+1);
        return;
    }
    int P(TreeNode* root, int temp){
        if (!root){
            return 0;
        }
        if (cnt==1 && temp ==d){
            ans = root;
            return -1;
        }
        if (temp == d){
            return 1;
        }
        int a1= P(root->left, temp+1);
        int a2= P(root->right, temp+1);
        if (a1+a2==cnt){
            ans = root;
            return -1;
        }
        return a1+a2;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root){
            return root;
        }
        T(root, 0);
        //depth mil gya
        ans = root;
        int num = P(root, 0);
        return ans;
    }
};