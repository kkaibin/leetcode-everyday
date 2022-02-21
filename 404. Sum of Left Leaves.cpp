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
    int sumOfLeftLeaves(TreeNode* root) {
        //iterate through the treenodes
        //sum += left
        int sum=0;
        helper(root, sum);
        return sum;


    }
    void helper(TreeNode* root, int& sum){
        if (root==NULL) return;
        if (root->left){
            if (!root->left->left && !root->left->right)
            sum+=root->left->val;
        }
        helper(root->left, sum);
        helper(root->right,sum);
    }

};
