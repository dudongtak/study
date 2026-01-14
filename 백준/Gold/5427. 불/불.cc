#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define INF 1e9;
using namespace std;

int t,w,h;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;

    while(t--){
        pii s;
        queue<pii> fq;
        cin>>w>>h;
        int Min=w*h;
        vector<string> board(h);
        for(int i=0;i<h;i++){
            cin>>board[i];
            for(int j=0;j<w;j++){
                if(board[i][j]=='@')s={i,j};
                if(board[i][j]=='*')fq.push({i,j});
            }
        }
        queue<pii> sq;
        sq.push(s);
        int cnt=0;
        bool flag=false;
        while(!sq.empty()){
            cnt++;
            //불 옮기기
            int f_size=fq.size();
            for(int i=0;i<f_size;i++){
                int x=fq.front().first;
                int y=fq.front().second;
                fq.pop();

                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||ny<0||nx>=h||ny>=w)continue;
                    if(board[nx][ny]=='.'||board[nx][ny]=='@'){
                        board[nx][ny]='*';
                        fq.push({nx,ny});
                    }
                }
            }
            //상근이 움직이기
            int s_size=sq.size();
            for(int i=0;i<s_size;i++){
                int x=sq.front().first;
                int y=sq.front().second;
                sq.pop();
                if(x==0||y==0||x==h-1||y==w-1){
                    flag=true;
                    break;
                }
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx<0||ny<0||nx>=h||ny>=w||board[nx][ny]!='.')continue;
                    board[nx][ny]='@';
                    sq.push({nx,ny});
                }
            }
            if(flag){
                cout<<cnt<<"\n";
                break;
            }
        }
        if(!flag)cout<<"IMPOSSIBLE\n";
    }
}