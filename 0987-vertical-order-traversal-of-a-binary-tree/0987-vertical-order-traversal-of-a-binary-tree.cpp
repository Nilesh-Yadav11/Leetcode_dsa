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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        
        map<int,map<int,vector<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>>ans;
        
        if(root==NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        // pair ke liye make_pair fxn call krdiya aur horizontal distance aur level starting mein toh 0 hi the 
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>temp=q.front();
            q.pop();
            TreeNode* frontnode=temp.first;
            int horizontal_distance=temp.second.first;
            int level=temp.second.second;
            
            nodes[horizontal_distance][level].push_back(frontnode->val);
            
            if(frontnode->left!=NULL){
                q.push(make_pair(frontnode->left,make_pair(horizontal_distance-1,level+1)));
            }
            if(frontnode->right!=NULL){
                q.push(make_pair(frontnode->right,make_pair(horizontal_distance+1,level+1)));
            }
        }
        for(auto it:nodes){
            // it-> represnting horizontal_distance<int,vector<int>> int for horizontal_distance and vector<int> for listofnodes 
            vector<int>col;
            
            for(auto j:it.second){
                // j - <int,vector<int>>
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    // k -> vector<int>>
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};