#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,a,b;
vector<vector<int>> board;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    board.resize(n+1,vector<int>(n+1,101));
    for(int i=1;i<=n;i++)board[i][i]=0;
    while(true){
        cin>>a>>b;
        if(a==-1&&b==-1)break;
        board[a][b]=1;
        board[b][a]=1;
    }

    for(int i=1;i<=n;i++){
        for(int s=1;s<=n;s++){
            for(int e=1;e<=n;e++){
                board[s][e]=min(board[s][e],board[s][i]+board[i][e]);
            }
        }
    }

    vector<int> answer;
    vector<int> point(n+1,0);
    for(int i=1;i<=n;i++){
        point[i]=*max_element(board[i].begin()+1,board[i].end());
    }

    int Min=*min_element(point.begin()+1,point.end());
    for(int i=1;i<=n;i++)if(point[i]==Min)answer.push_back(i);
    cout<<Min<<" "<<answer.size()<<"\n";
    for(int i=0;i<answer.size();i++)cout<<answer[i]<<" ";
}