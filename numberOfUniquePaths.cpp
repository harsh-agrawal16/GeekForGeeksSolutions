#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back

ll m,n;

ll rec(vvll &dp, ll i, ll j){
    if(dp[i][j] != -1) return dp[i][j];

    if(i==m-1 || j==n-1){
        dp[i][j] = 1;
        return dp[i][j];
    }

    dp[i][j] = rec(dp,i+1,j)  + rec(dp,i,j+1);
    return dp[i][j];
}



void solve(){
    cin>>m>>n;
   
    vvll dp(m,vll(n,-1));

    cout<<rec(dp,0,0)<<endl;

}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}