#include<iostream>
#include<vector>
using namespace std;

int num[3];
vector<vector<vector<bool>>> v(201,vector<vector<bool>>(201,vector<bool>(201,false)));
vector<bool> ans(201,false);
vector<int> cur(3,0);

void move(int idx1,int idx2);
void dfs();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>num[0]>>num[1]>>num[2];
    cur[2]=num[2];
    dfs();
    for(int i=0;i<=num[2];i++)if(ans[i])cout<<i<<" ";
}

void move(int idx1,int idx2){
    int tmp1=cur[idx1],tmp2=cur[idx2];
    cur[idx2]+=cur[idx1];
    cur[idx1]=0;
    if(cur[idx2]>num[idx2]){
        cur[idx1]=cur[idx2]-num[idx2];
        cur[idx2]=num[idx2];
    }
    dfs();
    cur[idx1]=tmp1;cur[idx2]=tmp2;
}

void dfs(){
    if(v[cur[0]][cur[1]][cur[2]])return;
    v[cur[0]][cur[1]][cur[2]]=true;
    if(cur[0]==0)ans[cur[2]]=true;
  
    move(2,0);
    move(2,1);

    move(1,0);
    move(1,2);

    move(0,1);
    move(0,2);
}