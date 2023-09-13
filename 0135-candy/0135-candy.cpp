class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int mini=n;
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){

            if(i>0){
                if(ratings[i]>ratings[i-1]){
                    if(cnt[i]<=cnt[i-1]){
                        cnt[i]=cnt[i-1]+1;
                    }
                }
            }
           
            }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                if(cnt[i]<=cnt[i+1]){
                    cnt[i]=cnt[i+1]+1;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cnt[i];
        }
        return sum;
    }
};