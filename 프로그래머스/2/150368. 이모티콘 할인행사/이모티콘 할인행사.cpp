#include <string>
#include <vector>
#include<algorithm>
#include<stack>

using namespace std;
//할인율 10,20,30,40;
vector<int> answer={-1,-1};
void dfs(int depth,vector<vector<int>> &u,vector<int> &e,stack<int> s){
    if(depth==e.size()){
        vector<int> total(u.size(),0);
        for(int i=e.size()-1;i>=0;i--){
            int rate=s.top();
            s.pop();
            int price=e[i]*(100-rate)/100;
            for(int j=0;j<u.size();j++)if(u[j][0]<=rate)total[j]+=price;
        }
        vector<int> res={0,0};
        for(int i=0;i<u.size();i++)
            if(u[i][1]<=total[i])res[0]++;
            else res[1]+=total[i];
        if(res[0]>answer[0])answer=res;
        else if(res[0]==answer[0]&&res[1]>answer[1])answer=res;
        return;
    }
    s.push(10);
    dfs(depth+1,u,e,s);
    s.pop();
    s.push(20);
    dfs(depth+1,u,e,s);
    s.pop();
    s.push(30);
    dfs(depth+1,u,e,s);
    s.pop();
    s.push(40);
    dfs(depth+1,u,e,s);
    s.pop();
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    dfs(0,users,emoticons,{});
    
    
    
    return answer;
}