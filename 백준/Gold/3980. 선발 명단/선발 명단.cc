#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int c;
int Max=-1;

void dfs(int idx,vector<vector<int>> &p,vector<bool> &v,int sum){
    if(idx>=11){
        Max=max(Max,sum);
        return;
    }
    for(int i=0;i<11;i++){
        if(p[i][idx]==0||v[i])continue;
        v[i]=true;
        dfs(idx+1,p,v,sum+p[i][idx]);
        v[i]=false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>c;

    while(c--){
        vector<vector<int>> pos(11,vector<int>(11));
        for(int i=0;i<11;i++)for(int j=0;j<11;j++)cin>>pos[i][j];

        vector<bool> visit(11,false);
        dfs(0,pos,visit,0);
        cout<<Max<<"\n";
        Max=-1;
    }
}