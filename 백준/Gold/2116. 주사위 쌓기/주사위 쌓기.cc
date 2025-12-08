#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Max=0,n;
int loc[]={5,3,4,1,2,0};
vector<vector<int>> dices;

void dfs(int cur,int sum,int bottom){
    if(cur==n){
        Max=max(Max,sum);
        return;
    }
    int idx=find(dices[cur].begin(),dices[cur].end(),bottom)-dices[cur].begin();
    int topIdx=loc[idx];
    int top=dices[cur][topIdx];

    int tmp=0;
    for(int i=0;i<6;i++){
        if(dices[cur][i]==top||dices[cur][i]==bottom)continue;
        tmp=max(tmp,dices[cur][i]);
    }
    dfs(cur+1,sum+tmp,top);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dices.resize(n,vector<int>(6));

    for(int i=0;i<n;i++){
        vector<int> dice(6);
        for(int j=0;j<6;j++)cin>>dice[j];
        dices[i]=dice;
    }

    for(int i=1;i<=6;i++)dfs(0,0,i);

    cout<<Max;
}