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
    int sum=0;

    void reverse_inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        reverse_inorder(root->right);
        // adding the value of current node to the sum 
        sum=sum+root->val;
        // to replace the value of node to the current sum
        root->val=sum;

        reverse_inorder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        reverse_inorder(root);

        return root;
    }
};