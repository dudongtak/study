#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,p;
    cin>>n;
    long long cur=0;
    vector<long long> dp(n+1,0);
    for(int i=0;i<n;i++){
        cin>>t>>p;
        cur=max(cur,dp[i]);
        if(i+t<=n)dp[i+t]=max(dp[i+t],cur+p);
    }
    cout<<*max_element(dp.begin(),dp.end());
}