#include<bits/stdc++.h>
using namespace std;
#define ll                long long
#define vll               vector<ll>
#define fastIO            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void printKMax(){
    ll n,k,i;
    cin>>n>>k;

    vll arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    deque<ll> q;
   

    for(i=0;i<k;i++){
        while(!q.empty() && arr[q.back()] <= arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }


    for(;i<n;i++){

        cout<<arr[q.front()]<<" ";
        
        while(!q.empty() && q.front()<=(i-k)){
            q.pop_front();
        }

        while(!q.empty() && arr[q.back()] <= arr[i]){
            q.pop_back();
        }

        q.push_back(i);
    }

    cout<<arr[q.front()];

    cout<<endl;

}


int main(){
    fastIO;
    ll t;
    cin>>t;

    while(t--){
        printKMax();
    }

}