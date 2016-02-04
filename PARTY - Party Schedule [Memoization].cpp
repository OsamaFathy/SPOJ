// Handle: osama_f (Osama Fathy)
// Problem: PARTY - Party Schedule
// Submission ID: 16229210
// Verdict: AC
// Runtime: 0.00

// Hint: Memoization to get the max fun + Recursion on the mem array to get minimum fees
#include <bits/stdc++.h>
using namespace std;
const int kMaxEntrances = 101;
const int kMaxFees = 501;
int budget, entrances;
int fee[kMaxEntrances];
int fun[kMaxEntrances];
int mem[kMaxEntrances][kMaxFees];

int solve(int ind, int remaining){
    if(ind >= entrances)
        return 0;
    int &ret = mem[ind][remaining];
    if(ret != -1)
        return ret;

    int ch1 = solve(ind+1, remaining);
    int ch2 = 0;
    if(remaining >= fee[ind])
        ch2 = fun[ind] + solve(ind+1, remaining - fee[ind]);
    return ret = max(ch1, ch2);

}
int getFees(int ind, int remaining){
    if(ind >= entrances)
        return 0;

    int ch1 = solve(ind+1, remaining);
    int ch2 = 0;
    if(remaining >= fee[ind])
        ch2 = fun[ind] + solve(ind+1, remaining-fee[ind]);

    if(ch1 == ch2)
        return min(fee[ind] + getFees(ind+1, remaining - fee[ind]),
                    getFees(ind+1, remaining));
    else if(ch2 > ch1)
        return fee[ind] + getFees(ind+1, remaining - fee[ind]);
    return getFees(ind+1, remaining);
}
int main()
{
    while(cin>>budget>>entrances && (budget || entrances)){
        memset(mem, -1, sizeof(mem));
        for(int i=0; i<entrances; i++){
            cin>>fee[i]>>fun[i];
        }
        int fun = solve(0, budget);
        int fees = getFees(0, budget);
        cout<<fees<<" "<<fun<<endl;
    }
    return 0;
}
