//https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    vector<int> visited(26,-1);
	    int curr_len = 0;
	    int max_len = 0;
	    int prev=0;
	    
	    for(int i=0;i<a.length();i++){
	        
	        if(visited[a[i]-'a'] == -1){
	            curr_len+=1;
	            visited[a[i]-'a'] = i;
	        }
	        else{
	            if(i-curr_len>visited[a[i] - 'a']){
	                curr_len+=1;
	            }
	            else{
	                max_len = max(curr_len,max_len);
	                curr_len = i - visited[a[i] - 'a'];
	            }
	            visited[a[i] - 'a'] = i;
	        }
	    }
	    
	    max_len = max(curr_len,max_len);
	    cout<<max_len<<endl;
	    
	}
	return 0;
}