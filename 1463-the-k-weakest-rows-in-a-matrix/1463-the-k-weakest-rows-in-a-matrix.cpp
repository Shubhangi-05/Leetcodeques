class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;

        // unordered_map<int,vector<int>>mpp;
        vector<pair<int,int>>rowStrengths;
        for(int i=0;i<mat.size();i++){
           int str=accumulate(mat[i].begin(),mat[i].end(),0);
           rowStrengths.push_back({str,i});
            }
            sort(rowStrengths.begin(),rowStrengths.end());

        

       for(int i=0;i<k;i++){
           ans.push_back(rowStrengths[i].second);
       }
       return ans;
        

    }
};