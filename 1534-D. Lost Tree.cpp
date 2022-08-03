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
     
    const int mod = 1e9 + 7;
     
    auto ask(int v, int n){
        cout << "? " << v + 1 << endl;
        vector<int> s(n);
        for (int& x : s)
            cin >> x;
        return s;
    }
     
    void trueMain() {
        int n;
        cin >> n;
        vector<set<int>> edges(n);
        auto d = ask(0, n);
        int cnto = 0, cnte = 0;
        for (int i = 0; i < n; i++){
            if (d[i] == 1){
                edges[0].insert(i);
                edges[i].insert(0);
            }
            if (d[i] & 1)
                cnto++;
            else
                cnte++;
        }
        int k = cnte <= cnto ? 0 : 1;
        for (int i = 1; i < n; i++){
            if (d[i] % 2 == k){
                auto dd = ask(i, n);
                for (int j = 0; j < n; j++){
                    if (dd[j] == 1){
                        edges[j].insert(i);
                        edges[i].insert(j);
                    }
                }
            }
        }
        cout << "!" << '\n'; 
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j : edges[i]){
                if (i < j){
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    cnt++;
                }
            }
        }
        assert(cnt == n - 1);
        cout << endl;
    }
     
     
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        int t = 1;
        // cin >> t;
        for (int i = 0; i < t; i++)
            trueMain();
    }