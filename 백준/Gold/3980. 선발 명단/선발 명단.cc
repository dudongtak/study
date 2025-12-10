#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int c;
int Max=-1;

void dfs(vector<int> &r,int idx,vector<vector<int>> &p,vector<bool> v){
    if(idx>=11){
        int sum=0;
        for(int i=0;i<11;i++){
            if(r[i]==0)return;
            sum+=r[i];
        }
        Max=max(Max,sum);
        return;
    }
    for(int i=0;i<11;i++){
        if(p[i][idx]==0||v[i])continue;
        v[i]=true;
        r[idx]=p[i][idx];
        dfs(r,idx+1,p,v);
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

        vector<int> roster(11,0);
        vector<bool> visit(11,false);
        dfs(roster,0,pos,visit);
        cout<<Max<<"\n";
        Max=-1;
    }
}