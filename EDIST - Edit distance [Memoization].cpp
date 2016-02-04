// Handle: osama_f (Osama Fathy)
// Problem: EDIST - Edit distance
// Submission ID: 16228162
// Verdict: AC
// Runtime: 0.85

// Hint: Memoization
#include <bits/stdc++.h>
using namespace std;
const int kMax = 2010;
string str1, str2;
int mem[kMax][kMax];
int solve(int i, int j){
    if(i>=str1.size())
        return (int)str2.size()-j;
    if(j>=str2.size())
        return (int)str1.size()-i;
    if(mem[i][j] != -1)
        return mem[i][j];
    if(str1[i] == str2[j])
        return mem[i][j] = solve(i+1, j+1);

    int ch1 = solve(i+1, j+1) + 1;
    int ch2 = solve(i+1, j) + 1;
    int ch3 = solve(i, j+1) + 1;

    return mem[i][j] = min(ch1, min(ch2, ch3));
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(mem, -1, sizeof(mem));
        cin>>str1>>str2;
        cout<<solve(0, 0)<<endl;
    }
    return 0;
}
