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
     unordered_map<TreeNode*,int>mpp;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        if(mpp.find(root)!=mpp.end()){
            return mpp[root];
        }
        int taken=root->val; int nt_taken=0;
        if(root->left){
        taken+=solve(root->left->left)+solve(root->left->right);
      
        }
        if(root->right)
        taken+=solve(root->right->left)+solve(root->right->right);
        nt_taken=solve(root->left)+solve(root->right);
        return mpp[root]=max(taken,nt_taken);


    }

    vector<int>solve1(TreeNode* root){
        if(!root){
            return {0,0};
        }
        vector<int>left=solve1(root->left);
        vector<int>rght=solve1(root->right);
        vector<int>res(2);
        res[0]=max(left[0],left[1])+max(rght[0],rght[1]);
        res[1]=root->val+left[0]+rght[0];
        return res;
    }
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }
      vector<int>res= solve1(root);
      return max(res[0],res[1]); //max of either rob that node or not rob
    }
};