    #include <iostream>
    #include <vector>
    #include <set>
    #include <map>
    #include <math.h>
    #include <unordered_set>
    #include <unordered_map>
    #include <numeric>
    #include <cassert>
    #include <algorithm>
    #include <bitset>
     
    using namespace std;
     
    #define ll long long
    #define dbl double
    #define prev aasdasd
    #define rank asldjnaksdas
     
    const int MAX = 4e5 + 7;
     
    int down[MAX], color[MAX];
    vector<int> g[MAX], back[MAX], euler;
     
    void dfs_f(int v){
        color[v] = 1;
        for (int u : g[v]){
            if (!color[u])
                dfs_f(u);
        }
        euler.push_back(v);
    }
     
    void dfs_b(int v, int c){
        color[v] = c;
        for (int u : back[v])
            if (!color[u])
                dfs_b(u, c);
    }
     
     
    void trueMain() {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& x : s)
            cin >> x;
        for (int i = 0; i < m; i++)
            down[i] = -1;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j < m; j++){
                if (s[i][j] != '#')
                    continue;
                for (int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '#')
                        g[i * m + j].push_back(x * m + y);
                }
                for (int k = -1; k <= 1; k++){
                    int x = i, y = j + k;
                    if (y >= 0 && y < m && down[y] != -1)
                        g[i * m + j].push_back(down[y] * m + y);
                }
            }
            for (int j = 0; j < m; j++)
                if (s[i][j] == '#')
                    down[j] = i;
        }
        
        for (int i = 0; i < n * m; i++){
            if (s[i / m][i % m] == '#' && !color[i])
                dfs_f(i);
        }
        reverse(euler.begin(), euler.end());
        for (int i = 0; i < n * m; i++){
            for (int u : g[i])
                back[u].push_back(i);
        }
        int cnt = 0;
        fill(color, color + n * m, 0);
        for (int v : euler){
            if (!color[v]){
                dfs_b(v, ++cnt);
            }
        }
        vector<int> ok(cnt);
        for (int v : euler){
            for (int u : g[v]){
                // cout << v << ' ' << u << ' ' << color[v] << ' ' << color[u] << endl;
                if (color[u] != color[v])
                    ok[color[u] - 1] = 1;
            }
        }
        cnt = 0;
        for (int v : ok)
            cnt += v == 0;
        cout << cnt << endl;
    }
     
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        int t = 1;
        // cin >> t;
        for (int i = 0; i < t; i++)
            trueMain();
    }