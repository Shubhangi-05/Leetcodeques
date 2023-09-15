

//kuruskal's algorithm!!!!

class disjointSet{
vector<int>par;
vector<int>sz;
public:
    disjointSet(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    public:
    int findBysize(int node){
        if(par[node]==node){
            return par[node];
        }
        return findBysize(par[node]);
    }
    public:
    void unionn(int i, int j){
        int pu=findBysize(i);
        int pv=findBysize(j);
        if(pu!=pv){
            if(sz[pu]<=sz[pv]){
                par[pu]=pv;
                sz[pv]+=sz[pu];
            }
            else{
                par[pv]=pu;
                sz[pu]+=sz[pv];
            }
        }
    }

};


class Solution {
public:
   
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int wt;
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                int x=points[i][0];
                int y=points[i][1];
                int x1=points[j][0];
                int y1=points[j][1];
                
                
                edges.push_back({wt,{i,j}});
            }
        }
        sort(edges.begin(),edges.end());
        //performing kuruskal's algo
        disjointSet ds(n); int sum=0;
        for(int i=0;i<edges.size();i++){
            int w=edges[i].first;
            int u=edges[i].second.first;
            int v=edges[i].second.second;
            int pu=ds.findBysize(u);
            int pv=ds.findBysize(v);
            if(pu!=pv){
                sum+=w;
                ds.unionn(u,v);
            }
        }
        return sum;

    }
};