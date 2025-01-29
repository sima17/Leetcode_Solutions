class Solution {
public:
    vector<int> check;

    int findFunc(int a){
        if(check[a] == a){
            return a;
        }
        return check[a] = findFunc(check[a]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0; i <= n; i++){
            check.push_back(i);
        }
        for(auto e : edges){
            int a = findFunc(e[0]);
            int b = findFunc(e[1]);
            if(a == b){
                return e;
            }
            check[a] = b;
        }
        return {0,0};
    }
};