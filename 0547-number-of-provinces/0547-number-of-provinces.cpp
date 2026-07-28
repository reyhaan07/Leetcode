class DSU{
public:
    vector<int> p,sz;

    DSU(int n){
        p.resize(n);
        sz.assign(n,1);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU dsu(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j])
                    dsu.unite(i,j);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
            if(dsu.find(i)==i) ans++;

        return ans;
    }
};