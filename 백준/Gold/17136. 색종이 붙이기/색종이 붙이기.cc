#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

vector<int> square(5,5);
vector<vector<int>> board(10,vector<int>(10,0));
vector<vector<bool>> visit(10,vector<bool>(10,false));
vector<pair<int,int>> coords;
int Min=1000;

bool canAttach(int x,int y,int k){
    if(x+k>=10||y+k>=10)return false;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(board[x+i][y+j]==0||visit[x+i][y+j])return false;
        }
    }
    return true;
}

void attach(int x,int y,int k){
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            visit[x+i][y+j]=true;
        }
    }
}

void unattach(int x,int y,int k){
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            visit[x+i][y+j]=false;
        }
    }
}

pair<int,int> findCoord(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(board[i][j]==1&&!visit[i][j])return {i,j};
        }
    }
    return {-1,-1};
}

void dfs(int c_cnt){
    int sum=25-accumulate(square.begin(),square.end(),0);
    if(sum>Min)return;
    if(c_cnt==coords.size()){
        Min=min(Min,sum);
        return;
    }

    pair<int,int> coord=findCoord();
    if(coord.first==-1)return;
    int x=coord.first;
    int y=coord.second;

    for(int i=0;i<5;i++){
        if(canAttach(x,y,i)){
            if(square[i]==0)continue;
            attach(x,y,i);
            square[i]--;
            dfs(c_cnt+(i+1)*(i+1));
            unattach(x,y,i);
            square[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>board[i][j];
            if(board[i][j]==1)coords.push_back({i,j});
        }
    }
    if(coords.size()==0){
        cout<<0;
        return 0;
    }
    dfs(0);
    
    if(Min==1000)cout<<-1;
    else cout<<Min;
}