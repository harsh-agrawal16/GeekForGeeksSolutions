/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>> &K,int x,int y,int k,int n,int  m)
{
    //vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    q.push({x,y});
    
    int value = K[x][y];
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        K[i][j] = k;
        
        if((i+1 < n) && K[i+1][j]==value){
            //K[i+1][j] = k;
            q.push({i+1,j});
        }
        if((i-1 >= 0) && K[i-1][j]==value){
            //K[i+1][j] = k;
            q.push({i-1,j});
        }
        if((j+1 < m) && K[i][j+1]==value){
            //K[i+1][j] = k;
            q.push({i,j+1});
        }
        if((j-1 >= 0) && K[i][j-1]==value){
            //K[i+1][j] = k;
            q.push({i,j-1});
        }
        
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    int x,y,k;
	    cin>>n>>m;
	    vector<vector<int>> T(n,vector<int> (m));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>T[i][j];
	        }
	    }
	    cin>>x>>y>>k;
	    
	    floodFill(T,x,y,k,n,m);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<T[i][j]<<" ";
	        }
	    }
	    cout<<endl;
	    
	}
	return 0;
}