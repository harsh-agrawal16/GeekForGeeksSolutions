#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
ll n,d;
vll arr;
ll iter;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}


void singleRotation(ll start){
    ll temp = arr[start];
    ll i = start;
    while(true){
        ll target = i + d;
        if(target>n) target = target%n;
        if(target == start){
            arr[i] = temp;
            return;
        }

        arr[i] = arr[target];
        i = target;
    }
}

void reversalAlgorithm(ll start, ll end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void solve(){
    cin>>n;
    arr = vll(n+1);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>d;

    reversalAlgorithm(1,d);
    reversalAlgorithm(d+1,n);
    reversalAlgorithm(1,n);

    for(ll i=1;i<=n;i++){
        cout<<arr[i]<<" ";
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
    return 0;
}