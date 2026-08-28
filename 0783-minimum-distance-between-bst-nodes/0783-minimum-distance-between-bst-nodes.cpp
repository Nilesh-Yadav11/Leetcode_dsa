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

    vector<int>ans;
    int difference=0;

    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {

        inorder(root);
        int difference=INT_MAX;
        for(int i=1;i<ans.size();i++){
            difference=min(difference,ans[i]-ans[i-1]); // we need to check every pair 
        }
        return difference;
    }
};