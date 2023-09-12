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
        // sort(s.begin(),s.end()); // I have to sort to make the same frequency characters to be together !
        // for(int i=0;i<n;i++){
        //     if(mpp.find(s[i])!=mpp.end()){
        //         int x=mpp[s[i]];
        //         if(x==0) continue;
        //         if(mpp1[x]>1){
        //             // s.erase(s.begin()+i);
        //             cnt++;
        //             mpp1[x]--;
        //             mpp[s[i]]--;
        //             int l=mpp[s[i]];
        //             if(l>0){
        //                 mpp1[l]++;
        //             }
        //         }
               
        //     }
        // }
        for(auto i:mpp){
            int k=i.second;
            
            if(mpp1[k]>1){
                while(mpp1[k]>1){
                    mpp1[k]--;
                    cnt++;
                    k--;
                    if(k>0)
                    mpp1[k]++;
                    else break;
                    
                }
                if(k>0){
                    i.second=k;
                }
            }
        }  
        return cnt;
    }
};