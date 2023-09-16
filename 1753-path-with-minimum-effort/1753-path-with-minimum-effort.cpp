
class Solution {
public:
   
    int ans;
    void dfs(int row, int col , int diff, vector<vector<int>>& v, vector<vector<int>>& h){
        if(row>h.size()-1 && col>h[0].size()-1){
       return;
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};

        for(int i=0 ; i<4 ; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<h.size() && ncol>=0 && ncol<h[0].size()){
                int newdiff = max(diff, abs(h[row][col] - h[nrow][ncol]));
                if(newdiff < v[nrow][ncol]){
                    v[nrow][ncol]=newdiff;
                    dfs(nrow,ncol,newdiff,v,h);
                }
            }
        }
        return ;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // int n = h.size();
        // int m = h[0].size();
        // vector<vector<int>> v(n,vector<int>(m,INT_MAX));
        // v[0][0]=0;
        // dfs(0,0,0,v,h);
       
        // return v[n-1][m-1];
         int n=heights.size();
        int m=heights[0].size();
        if(n==1 && m==1){
            return 0;
        }
        queue<pair<int,pair<int,int>>>q;
        
        q.push({0,{0,0}});
   
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        ans[0][0]=0;  //int maxi=INT_MIN; int mini=INT_MAX;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second.first;
            int wt=q.front().second.second;
            q.pop();
           for(int i=0;i<4;i++){
               int nrow=row+x[i];
               int ncol=col+y[i];
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                       int diff=max(abs(heights[row][col]-heights[nrow][ncol]),wt);
                       if(ans[nrow][ncol]>diff)
                       q.push({nrow,{ncol,diff}});
                    
                        ans[nrow][ncol]=min(diff,ans[nrow][ncol]);
                   }
                
               }
           }
        
        return ans[n-1][m-1];
    }
};
 