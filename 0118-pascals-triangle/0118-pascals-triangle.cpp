class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        pt.push_back({1});
        for(int i = 1; i<numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1; j<i; j++){
                int ele = pt[i-1][j]+pt[i-1][j-1];
                row.push_back(ele);
            }
            row.push_back(1);
            pt.push_back(row);
        }
        return pt;
    }
};