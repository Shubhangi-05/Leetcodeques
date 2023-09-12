class Solution {
public:
    int minDeletions(string s) {
        
        int n=s.length();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        } 
        unordered_map<int,int>mpp1;

        for(auto i:mpp){
            int k=i.second;
            mpp1[k]++;

        }
        int cnt=0;
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                int x=mpp[s[i]];
                if(x==0) continue;
                if(mpp1[x]>1){
                    // s.erase(s.begin()+i);
                    cnt++;
                    mpp1[x]--;
                    mpp[s[i]]--;
                    int l=mpp[s[i]];
                    if(l>0){
                        mpp1[l]++;
                    }
                }
               
            }
        }
        return cnt;
    }
};