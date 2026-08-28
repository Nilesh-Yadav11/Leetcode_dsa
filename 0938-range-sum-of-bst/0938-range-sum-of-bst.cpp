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

    vector<int>range;
    vector<int>ans;
    int sum=0;

    void inorder(TreeNode*root){
        if (root==NULL){
            return;
        }
        inorder(root->left);
        range.push_back(root->val);
        inorder(root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {

        inorder(root);
        
        for(int i=0;i<range.size();i++){
            if(range[i]>=low && range[i]<=high){
                ans.push_back(range[i]);
            }
        }

        for(int i=0;i<ans.size();i++){
            sum=sum+ans[i];
        }
        return sum;
    }
};