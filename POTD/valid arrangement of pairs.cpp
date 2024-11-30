
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;
    inline void build_graph(vector<vector<int>>& pairs){
        for(auto& edge: pairs){
            int start=edge[0], end=edge[1];
            adj[start].push_back(end);
            deg[start]++;
…    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
