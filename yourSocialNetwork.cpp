#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void DFS(vector<vector<pair<int,int>>> &ans, int root, int frnd,int x,int A[]){
    if(frnd == 1){
        ans[root].push_back({frnd,x+1});
        //ans.push_back({{root,1},x+1});
        return;
    }
    else{
        ans[root].push_back({frnd,x+1});
        //ans.push_back({{root,frnd},x+1});
        DFS(ans,root,A[frnd-1],x+1,A);
    }
    
}


void friendsBook(vector<vector<pair<int,int>>> &ans, int n, int A[]){
    
    for(int i=2;i<=n;i++){
        int x=0;
        DFS(ans,i,A[i-1],x,A);
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[n];
	    //vector<vector<int>> adList(n+1,vector<int>(1));
	    for(int i=1;i<=n-1;i++){
	        cin>>A[i];
	    }
	    
	    vector<vector<pair<int,int>>> ans(n+1);
	    
	    friendsBook(ans,n,A);
	    
	     for(int i=0;i<ans.size();i++){
	        sort(ans[i].begin(),ans[i].end());
	        //cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<" ";
	    }
	    for(int i=2;i<ans.size();i++){
	        for(int j=0;j<ans[i].size();j++)
	        cout<<i<<" "<<ans[i][j].first<<" "<<ans[i][j].second<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}