#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int Max=-1000000000;
int Min=1000000000;
vector<int> num;
int op[]={0,0,0,0};

void dfs(int depth,int res){
    if(depth==n-1){
        Max=max(Max,res);
        Min=min(Min,res);
        return;
    }
    depth++;
    for(int i=0;i<4;i++){
        if(op[i]==0)continue;
        op[i]--;
        if(i==0)dfs(depth,res+num[depth]);
        else if(i==1)dfs(depth,res-num[depth]);
        else if(i==2)dfs(depth,res*num[depth]);
        else dfs(depth,res/num[depth]);
        op[i]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    num.resize(n);
    for(int i=0;i<n;i++)cin>>num[i];

    for(int i=0;i<4;i++)cin>>op[i];

    dfs(0,num[0]);

    cout<<Max<<"\n"<<Min;
}