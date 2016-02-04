// Handle: osama_f (Osama Fathy)
// Problem: PRIME1 - Prime Generator
// Submission ID: 16229300
// Verdict: AC
// Runtime: 0.71

// Hint: Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
const int kMax = 32000;
int notprime[kMax];
vector<int>primes;
void sieve(){
    notprime[0] = notprime[1] = 1;
    for(int i=2; i*i<=kMax; i++){
        if(!notprime[i]){
            for(int j=i*2; j<kMax; j+=i){
                notprime[j] = 1;
            }
        }
    }
    for(int i=0; i<kMax;i++)
        if(!notprime[i])
            primes.push_back(i);
}

int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        for(int i=max(x, 2); i<=y; i++){
            bool pr = 1;
            for(int j=0; j<primes.size(); j++){
                if(primes[j] >= i)
                    break;
                if(i%primes[j] == 0){
                    pr=0;
                    break;
                }
            }
            if(pr)
                cout<<i<<"\n";
        }
        if(t)cout<<"\n";
    }
    return 0;
}
