#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define vvll vector<vll>
#define pb push_back


ll n;
vll arr;

void rightRotate(ll outOfPlace, ll opp){
    ll temp = arr[opp];
    for(ll i=opp;i>outOfPlace;i--){
        arr[i] = arr[i-1];
    }
    arr[outOfPlace] = temp;
}




void solve(){
    cin>>n;

    arr = vll(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    vll posi;
    vll negi;

    for(ll i=0;i<n;i++){
        if(arr[i]>=0) posi.pb(arr[i]);
        else negi.pb(arr[i]);
    }


    ll i=0,j=0;

    while(i<posi.size() && j<negi.size()){
        cout<<posi[i++]<<" "<<negi[j++]<<" ";
    }

    
    while(j<negi.size()){
        cout<<negi[j]<<" ";
        j++;
    }
   
    while(i<posi.size()){
        cout<<posi[i]<<" ";
        i++;
    }
    

    cout<<endl;
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