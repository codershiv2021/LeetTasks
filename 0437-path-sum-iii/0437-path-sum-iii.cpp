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
    unordered_map<long long,int>mp; int count = 0; long long sum =0;
    void T(TreeNode* root, int S){
        if (!root){
            return;
        }
        sum+= root->val;
        count += (mp[sum-S]);
        mp[sum]++;
        T(root->left,S);
        T(root->right,S);
        mp[sum]--;
        sum-=root->val;
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        T(root,targetSum);
        return count;
    }
};