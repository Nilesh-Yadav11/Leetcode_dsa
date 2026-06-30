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
    vector<vector<int>>result;
    void fill(TreeNode*root,vector<int>temp){
         if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            result.push_back(temp); // condition of when the leaf node occurs
        }
        fill(root->left,temp);
        fill(root->right,temp);
    }
    int maxDepth(TreeNode* root) {
       vector<int>temp;
       fill(root,temp);
       
       int maxsize=0;
       for(auto &row:result){
        maxsize=max(maxsize,(int)row.size());
       }

       return maxsize;
    }
};