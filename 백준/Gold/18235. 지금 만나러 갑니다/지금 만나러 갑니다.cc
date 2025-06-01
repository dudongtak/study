#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;

int N,A,B;
vector<vector<int>> board(500000);

void Abfs(){
    queue<pair<int,int>> aq;
    aq.push({A-1,0});

    while(!aq.empty()){
        int cur=aq.front().first;
        int cnt=aq.front().second;
        int move=pow(2,cnt);
        aq.pop();

        for(int i=0;i<2;i++){
            int next=-1;
            if(i==0&&cur+move<N)next=move+cur;
            if(i==1&&cur-move>=0)next=cur-move;

            if(next==-1)continue;
            board[next].push_back(cnt);
            
            aq.push({next,cnt+1});
        }
    }
}

int Bbfs(){
    queue<pair<int,int>> bq;
    bq.push({B-1,0});

    while(!bq.empty()){
        int cur=bq.front().first;
        int cnt=bq.front().second;

        int move=pow(2,cnt);
        bq.pop();

        for(int i=0;i<2;i++){
            int next=-1;
            if(i==0&&cur+move<N)next=move+cur;
            if(i==1&&cur-move>=0)next=cur-move;

            if(next==-1)continue;
            for(int j=0;j<board[next].size();j++)if(board[next][j]==cnt)return cnt+1;
            
            bq.push({next,cnt+1});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>A>>B;
    Abfs();

    cout<<Bbfs();
}