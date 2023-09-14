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
int move=0;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        move+=abs(left);
        move+=abs(right);
        return left+right+root->val-1; //what are the numberr of coins needed till that level
        

    }
    int distributeCoins(TreeNode* root) {
        if(!root){
            return 0;
        }
       solve(root);
       return move;
    }
};