class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        for(int i=0;i<groupSizes.size();i++){
            if(mpp[groupSizes[i]].size()>0){
                int k=groupSizes[i];
                vector<int>arr;
                for(int j=0;j<k;j++){
                    arr.push_back(mpp[k][j]);
                }
                ans.push_back(arr);
                mpp[k].erase(mpp[k].begin(),mpp[k].begin()+k);
            }
        }
        return ans;
    }
};