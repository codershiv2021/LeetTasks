/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* flag= NULL;
    TreeNode* T(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root){
            return root;
        }
        if (root==p || root==q){
            flag= root;
            return root;
        }
        TreeNode* Left= T(root->left,p,q);
        TreeNode* Right= T(root->right,p,q);
        if (Left&& Right){
            flag= root;
        }
        if (Right){
            return Right;
        }
        return Left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return root;
        }
        T(root,p,q);
        return flag;
    }
};