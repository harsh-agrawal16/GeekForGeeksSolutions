#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define CHAR_NO 256

int longestSubstring(string s)
{
    int x = s.size();
    int max_len = 1;
    int curr_len = 1;
    int visited[CHAR_NO];
    int prev_index;
    
    
    for(int i=0;i<CHAR_NO;i++){
        visited[i] = -1;
    }
    
    visited[s[0]] = 0;
    
    for(int i=1;i<x;i++)
    {
        prev_index = visited[s[i]];
        
        //if the current character is not a part of the already processed part or if present it is not a 
        //part of the current NRCS
        if(prev_index == -1 || i - prev_index > curr_len){
            curr_len +=1;
        }
        
        //if the current character is already visited and is part of the current NRCS
        else{
            
            max_len = (max_len > curr_len)? max_len : curr_len;
            curr_len = i-prev_index;
            
        }
        
        visited[s[i]] = i;
        
    }
    
    return (max_len > curr_len)? max_len : curr_len;
    
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<longestSubstring(s)<<endl;
	}
	return 0;
}