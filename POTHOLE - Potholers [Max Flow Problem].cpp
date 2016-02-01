// Handle: osama_f (Osama Fathy)
// Problem: POTHOLE - Potholers
// Submission ID: 16207776
// Verdict: AC
// Runtime: 0.01

// Hint: Max Flow - Ford-Fulkerson method
#include <bits/stdc++.h>
using namespace std;
int capacity[201][201];
int path[201];
int vis[201];
int n;

int findPath(int cur, int target, int curLen, int maxCap){
    path[curLen] = cur;
    if(cur == target)
        return maxCap;
    vis[cur] = 1;
    for(int i=0; i<n; i++){
        if(capacity[cur][i] <= 0 || vis[i])
            continue;
        int cap = findPath(i, target, curLen+1, min(maxCap, capacity[cur][i]));
        if(cap > 0)
            return cap;
    }
    return 0;
}
int maxFlow(int src, int sink){
    int res = 0;
    while(1){
        memset(vis, 0, sizeof(vis));
        int maxCap = findPath(src, sink, 0, 201);
        if(!maxCap)
            break;
        res += maxCap;

        int ind = 0;
        while(path[ind] != sink){
            capacity[path[ind]][path[ind+1]] -= maxCap;
            capacity[path[ind+1]][path[ind]] += maxCap;
            ind++;
        }
    }
    return res;
}
int main()
{
    int t;
    cin>>t;

    while(t--){
        memset(capacity, 0, sizeof(capacity));
        cin>>n;
        for(int i=0; i<n-1; i++){
            int num;
            cin>>num;
            for(int j=0; j<num; j++){
                int node;
                cin>>node;
                if(i == 0 || node == n)
                    capacity[i][node-1] = 1;
                else
                    capacity[i][node-1] = 201;
            }
        }

        cout<<maxFlow(0, n-1)<<endl;
    }
    return 0;
}
