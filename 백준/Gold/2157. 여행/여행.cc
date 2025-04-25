#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M,K,s,e,w;
vector<vector<int>> board(301,vector<int>(301,0));
vector<vector<int>> dp(301,vector<int>(301,0));

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>K;


    for(int i=0;i<K;i++){
        cin>>s>>e>>w;
        if(e<=s)continue;
        board[s][e]=max(board[s][e],w);
    }

    for(int i=2;i<=N;i++){
        dp[i][2]=board[1][i];
    }
    
    for(int i=2;i<=N;i++){
        for(int j=3;j<=M;j++){
            for(int l=1;l<i;l++){
                if(board[l][i]!=0&&dp[l][j-1]!=0){
                    dp[i][j]=max(dp[i][j],dp[l][j-1]+board[l][i]);
                }
            }
        }
    }
    cout<<*max_element(dp[N].begin(),dp[N].end());
}