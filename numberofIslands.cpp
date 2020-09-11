// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
vector<vector<bool>> visited;
int ans;
vector<int> X = {0,0,1,-1,-1,1,1,-1};
vector<int> Y = {1,-1,0,0,1,-1,1,-1};
int N, M;


void dfs(int i , int j, vector<int> A[]){
    
    for(int k=0; k<8 ; k++){
        int newx = i + X[k];
        int newy = j + Y[k];
        
        if(newx >=0 && newx<N && newy>=0 &&  newy<M){
            if(!visited[newx][newy] && A[newx][newy] == 1){
                visited[newx][newy] = true;
                dfs(newx, newy, A);
            }
        }
    }
    return;
}



int findIslands(vector<int> A[], int n, int m) {

    // Your code here
    N = n;
    M = m;
    visited = vector<vector<bool>> (N, vector<bool>(M, false));
    ans = 0;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(A[i][j] == 1 && !visited[i][j]){
                ans++;
                visited[i][j] = true;
                dfs(i,j,A);
            }
        }
    }
    
    return ans;
}
