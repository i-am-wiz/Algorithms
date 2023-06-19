int N; //works for N <= 10
vector<vector<int>> adj;
int dp[11][1 << 11];

int rec(int node, int mask) {
    if(mask == (1 << (N + 1)) - 1) {
        return 1;
    }
    if(dp[node][mask] != -1) return dp[node][mask];
    int ans = 0;
    for (auto nbr: adj[node]) {
        if(mask & (1 << nbr)) continue;
        ans += rec(nbr, mask | (1 << nbr));
    }
    return dp[node][mask] = ans;
}

int countHamiltonianPaths(int n, int m, vector<vector<int>> &edges)
{
    //m is number of edges
    memset(dp, -1, sizeof dp);
    N = n;
    adj = vector<vector<int> >(N + 1);
    for (auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    for (int i = 1; i <= n; ++i) adj[0].push_back(i);
    return rec(0, 1);
}