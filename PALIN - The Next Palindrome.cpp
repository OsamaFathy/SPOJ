// Handle: osama_f (Osama Fathy)
// Problem: PALIN - The Next Palindrome
// Submission ID: 16225436
// Verdict: AC
// Runtime: 0.08

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n = str.size();
        bool bigger = 0;
        for(int i=0; i*2<n; i++){
            if(str[n-i-1] > str[i])
                bigger = 0;
            else if(str[n-i-1] < str[i])
                bigger = 1;
            str[n-i-1] = str[i];
        }

        if(!bigger){
            for(int i=(n-1)/2; i>=0; i--){
                if(str[i] != '9'){
                    str[i] = str[n-i-1] = (str[i]+1);
                    bigger = true;
                    break;
                }else{
                    str[i] = str[n-i-1] = '0';
                }
            }
            if(!bigger)
                str = "1" + string(n-1, '0') + "1";

        }
        cout<<str<<endl;
    }
    return 0;
}
