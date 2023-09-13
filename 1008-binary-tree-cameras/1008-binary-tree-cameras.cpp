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

    // unordered_map<TreeNode*,TreeNode*>mpp;
    // void par(TreeNode* root){
    //     if(!root){
    //         return;
    //     }

    //     if(root->left){
    //         mpp[root->left]=root;
    //         par(root->left);
    //     }
    //     if(root->right){
    //         mpp[root->right]=root;
    //         par(root->right);
    //     }
    // }
    // int solve(TreeNode* root){
    //     if(!root){
    //         return 0;
    //     }
    //     int taken=1;
    //     int nt_taken=0;
    //     if(root->left){
    //         taken+=solve(root->left->left)+solve(root->left->right);
    //     }
    //     if(root->right){
    //         taken+=solve(root->right->left)+solve(root->right->right);
    //     }
    //     if(mpp.find(root)!=mpp.end()){
    //         taken+=solve(mpp[root]->left)+solve(mpp[root]->right);
    //     }
    //     nt_taken=solve(root->left)+solve(root->right)+solve(mpp[root]);

    //     return min(taken,nt_taken);
    // }

    int camera=0;  //1->covered 0->i have camera -1->i need camera
    int solve(TreeNode* root){
        if(!root){
            return 1; //1-->covered
        }
        int lc=solve(root->left);
        int rc=solve(root->right);
        if(lc==-1 || rc==-1){ //-1-->there is a need of cameras 
            camera++;
            return 0;
        }
        if(lc==0|| rc==0){
            return 1;  //child is covering me so i will return 1 stating that i am covered
        }
        return -1; //i need camera 

    }
    int minCameraCover(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        if(solve(root)==-1){
            camera++;
        }
        return camera;
    }
};