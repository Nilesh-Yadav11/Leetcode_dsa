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
    vector<vector<int>>result;

    void fill(TreeNode*root,vector<int>temp,int curr_sum,int targetSum){
        if(root==NULL){
            return ;
        }
        curr_sum=curr_sum+root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(curr_sum==targetSum){
                result.push_back(temp);
            }
            return;
        }
        fill(root->left,temp,curr_sum,targetSum);
        fill(root->right,temp,curr_sum,targetSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int curr_sum=0;
        vector<int>temp;
        fill(root,temp,curr_sum,targetSum);
        if(result.size()!=0){
            return true;
        }
        return false;
    }
};