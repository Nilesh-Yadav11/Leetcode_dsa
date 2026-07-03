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

    int max_sum=INT_MIN;
    int fill(TreeNode*root){
        if(root==NULL){
        return 0;
        }
        int leftsum=max(fill(root->left),0);
        int rightsum=max(fill(root->right),0);

        int peaksum=root->val+leftsum+rightsum;
        max_sum=max(max_sum,peaksum);

        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        fill(root);
        return max_sum;
    }
};