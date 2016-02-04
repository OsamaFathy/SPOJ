// Handle: osama_f (Osama Fathy)
// Problem: COINS - Bytelandian gold coins
// Submission ID: 16225295
// Verdict: AC
// Runtime: 0.00

// Hint: Memoization
#include <bits/stdc++.h>
using namespace std;

map<int, long long> mem;
long long solve(int coins){
    if(coins == 0)
        return 0;
    if(mem[coins]!=0)
        return mem[coins];
    return mem[coins] = max((long long)coins, solve(coins/2) + solve(coins/3) + solve(coins/4));
}
int main()
{
    int coins;
    while(cin>>coins){
        cout<<solve(coins)<<endl;
    }
    return 0;
}
