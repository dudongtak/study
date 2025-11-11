#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> w;
vector<int> s;
int Max=0;

void dfs(int cur){
    if(cur==n){
        int cnt=0;
        for(int i=0;i<n;i++)if(s[i]<=0)cnt++;
        Max=max(Max,cnt);
        return;
    }
    if(s[cur]<=0){
        dfs(cur+1);
        return;
    }
    bool hit=false;
    for(int i=0;i<n;i++){
        if(i==cur||s[i]<=0)continue;
        hit=true;
        s[cur]-=w[i];
        s[i]-=w[cur];
        dfs(cur+1);
        s[cur]+=w[i];
        s[i]+=w[cur];
    }
    if(!hit)dfs(cur+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    w.resize(n);s.resize(n);
    for(int i=0;i<n;i++){
        cin>>s[i]>>w[i];
    }
    dfs(0);
    cout<<Max;
}