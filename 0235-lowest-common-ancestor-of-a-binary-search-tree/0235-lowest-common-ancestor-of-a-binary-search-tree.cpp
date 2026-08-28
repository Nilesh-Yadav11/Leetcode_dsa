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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL){
            return NULL;
        }
        // case1 ) when both p and q are on the left 
        if(p->val< root->val && q->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        //case2) when both p and q are on the right
        else if(p->val>root->val && q->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        // No need 

        // // case 3 ) jb dono alg alg directions mein ho 
        // else if(p->val<root->val && q->val>root->val){
        //     return root;
        // }
        // // case 4) jb dono me so koi ek root ke hi baraabar aa jaye 
        // else if (root->val==p->val){
        //     return p;
        // }
        // else if(root->val==q->val){
        //     return q;
        // }

        else{
            return root;
        }
    }
};