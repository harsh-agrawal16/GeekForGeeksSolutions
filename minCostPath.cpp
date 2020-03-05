#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int X[] = {0,0,1,-1};
int Y[] = {1,-1,0,0};

int dijkstra(int n,vector<vector<int>> &cost, vector<vector<bool>> &visited){
    //queue<pair<int,int>> q;
    vector<vector<int>> least_cost(n,vector<int>(n,INT_MAX));
    least_cost[0][0] = cost[0][0];
    //q.push({0,0});
    visited[0][0] = true;
    set<pair<int,pair<int,int>>> pq;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.insert({least_cost[i][j], {i,j}});
        }
    }
    
    
    while(!pq.empty()){
        pair<int, pair<int,int>> z = *pq.begin();
        int min_x = z.second.first;
        int min_y = z.second.second;
        pq.erase(pq.begin());
        visited[min_x][min_y] = true;
        int curr_cost = least_cost[min_x][min_y];
        
        for(int i=0;i<4;i++){
            int new_x = min_x + X[i];
            int new_y = min_y + Y[i];
            
            if(new_x >=0 && new_x < n && new_y >=0 && new_y < n && !visited[new_x][new_y]){
                if(curr_cost + cost[new_x][new_y] < least_cost[new_x][new_y]){
                    pq.erase(pq.find({least_cost[new_x][new_y],{new_x,new_y}}));
                    least_cost[new_x][new_y] = curr_cost + cost[new_x][new_y];
                    pq.insert({least_cost[new_x][new_y],{new_x,new_y}});
                }
            }
        }
    }
    
    
    
    return least_cost[n-1][n-1];
}




int main()
 {
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> cost(n,vector<int>(n));
	    vector<vector<bool>> visited(n,vector<bool>(n,false));
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>cost[i][j];
	        }
	    }
	    
	    cout<<dijkstra(n,cost,visited)<<endl;
	    
	    
	}
	return 0;
}