#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int X[] = {0 , 0, 1 , -1};
int Y[] = {1 , -1, 0, 0 };


void rottenOranges(vector<vector<int>> &a,int r, int c){
    
    int count = 0;
    bool visited[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j] = false;
        }
    }
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    
    while(!q.empty()){
       //count++;
        int flag = 0;
        int x = q.size();
        for(int k=0;k<x;k++){
            int new_x = q.front().first;
            int new_y = q.front().second;
            q.pop();
            
            visited[new_x][new_y] = true;
            
            for(int o=0;o<4;o++){
                int temp_x = new_x + X[o];
                int temp_y = new_y + Y[o];
                
                if(temp_x>=0 && temp_y>=0 && temp_x < r && temp_y < c){
                    if(a[temp_x][temp_y] == 1) {
                        if(flag==0){
                            count++;
                            flag = 1;
                        }
                        a[temp_x][temp_y] = 2;
                        q.push({temp_x,temp_y});
                    }
                }
            }
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]==1){
                cout<<-1<<endl;
                return;
            }
        }
    }
    
    cout<<count<<endl;
    return;
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    
	    vector<vector<int>> a(r,vector<int> (c,0));
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            cin>>a[i][j];
	        }
	    }
	    
	    rottenOranges(a,r,c);
	}
	return 0;
}