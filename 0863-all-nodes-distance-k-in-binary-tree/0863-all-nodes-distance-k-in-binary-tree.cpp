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
    unordered_map<TreeNode*,TreeNode*>parent;       

// jaise ki 5 ka prent 3 hai , 2 ka parent 5 h , aise map me store krne ke liye 

    void inorder(TreeNode*root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            parent[root->left]=root;
        }
        inorder(root->left);

        if(root->right!=NULL){
            parent[root->right]=root;
        }
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k , vector<int> &result){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<TreeNode*>visited;
        visited.insert(target); // to keep the track of the nodes which are being visited

        while(!q.empty()){
            int n=q.size();

            if(k==0){
                break; // jaise ki 2nd level pr pohoch gye jb tb vhi answer return krdenge , ans vhi hoga 

            }
            while(n--){
                TreeNode*curr=q.front();
                q.pop();

                // left 
                if(curr->left!=NULL && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }

                // right 
                if(curr->right!=NULL && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }

                // parent 
                // parent.count(curr) -> mtlb parent ke andar curr present tha
                //parent[curr]->val mtlb ki parent of current  

                if(parent.count(curr) && !visited.count(parent[curr])){
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        inorder(root);

        BFS(target,k,result);

        return result;
    }
};