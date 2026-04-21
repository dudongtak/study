#include <string>
#include <vector>
#include<deque>
using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer(2,-1);
    int INF=500001;
    vector<vector<int>> first(m,vector<int>(n,INF));
    
    for(int i=0;i<drops.size();i++){
        int x=drops[i][0];
        int y=drops[i][1];
        first[x][y]=min(first[x][y],i+1);
    }
    vector<vector<int>> rowMin(m,vector<int>(n-w+1));
    
    for(int i=0;i<m;i++){
        deque<int> dq;
        for(int j=0;j<n;j++){
            while(!dq.empty()&&first[i][dq.back()]>=first[i][j])dq.pop_back();
            dq.push_back(j);
            while(!dq.empty()&&dq.front()<=j-w)dq.pop_front();
            
            if(j>=w-1)rowMin[i][j-w+1]=first[i][dq.front()];
        }
    }
    
    vector<vector<int>> rectMin(m-h+1,vector<int>(n-w+1));
    for(int i=0;i<=n-w;i++){
        deque<int> dq;
        for(int j=0;j<m;j++){
            while(!dq.empty()&&rowMin[dq.back()][i]>=rowMin[j][i])dq.pop_back();
            dq.push_back(j);
            while(!dq.empty()&&dq.front()<=j-h)dq.pop_front();
            
            if(j>=h-1)rectMin[j-h+1][i]=rowMin[dq.front()][i];
        }
    }
    
    int Max=-1;
    for(int sx=0;sx<=m-h;sx++){
        for(int sy=0;sy<=n-w;sy++){
            if(rectMin[sx][sy]>Max){
                Max=rectMin[sx][sy];
                answer[0]=sx;
                answer[1]=sy;
            }
        }
    }
    
    return answer;
}