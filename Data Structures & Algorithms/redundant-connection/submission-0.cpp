class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> sz(n+1, 1);
        vector<int> par(n+1);
        for(int i {0} ;i <n ;i++) par[i] = i;
        auto findp = [&](int i){
            int j = i;
            while(j != par[j]) j = par[j];
            while(j != i)
            {
                int temp = par[i];
                par[i] = j;
                i = temp;
            }
            return j;
        };
        auto uni =[&](int i, int j){
            int pi = findp(i);
            int pj = findp(j);
            if(pi == pj) return false;
            if (sz[pi] < sz[pj]) swap(pi, pj);
            par[pj] = pi;
            sz[pi] += sz[pj];
            return true;
        };
        for(auto& e : edges){
            if(!uni(e[0], e[1])) return e;
        }
        return {};
    }
};
