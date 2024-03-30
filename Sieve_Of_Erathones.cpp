
#include <bits/stdc++.h>
using namespace std;



vector<int> SieveOfErathones(int n){

    vector<int> isprime(n + 1, true);
    vector<int> ans;

    for(int i = 2 ; i <= n ; i++){
        if(isprime[i]){
            ans.push_back(i);
            for(int j = i * i ; j <= n ; j += i){
                isprime[j] = false;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> temp = SieveOfErathones(100);
    for(auto x: temp){
        cout << x << " ";
    }
}
