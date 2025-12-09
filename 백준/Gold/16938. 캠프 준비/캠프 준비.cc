#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int n,l,r,x,ans=0;
vector<int> q;

void dfs(int idx,int sum,int Max,int Min,int cnt){
    if(cnt>=2){
        if(sum>=l&&sum<=r&&Max-Min>=x)ans++;
    }

    for(int i=idx+1;i<n;i++){
        int nsum=sum+q[i];
        int nMax=max(Max,q[i]);
        int nMin=min(Min,q[i]);
        dfs(i,nsum,nMax,nMin,cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l>>r>>x;

    q.resize(n);
    for(int i=0;i<n;i++)cin>>q[i];
    for(int i=0;i<n;i++)dfs(i,q[i],q[i],q[i],1);

    cout<<ans;
}