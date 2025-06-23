#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,K,inf=1000000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>K;

    vector<int> coin(N);
    vector<int> dp(K+1,inf);
    for(int i=0;i<N;i++){
        cin>>coin[i];
        if(coin[i]<=K)dp[coin[i]]=1;
    }

    for(int i=1;i<=K;i++){
        for(int j=0;j<N;j++){
            if(i-coin[j]>=0&&dp[i-coin[j]]!=inf){
                dp[i]=min(dp[i-coin[j]]+1,dp[i]);
            }
        }
    }

    if(dp[K]==inf)cout<<-1;
    else cout<<dp[K];
}