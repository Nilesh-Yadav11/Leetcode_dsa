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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left_height=height(root->left);
        int right_height=height(root->right);

        return 1+max(left_height,right_height);
    }

    int count_nodes(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return 1+ count_nodes(root->left)+count_nodes(root->right);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){ // no element is also considered as balanced only
            return true;
        }
        int lh=height(root->left);
        int rh=height(root->right);

        if(abs(lh-rh)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};