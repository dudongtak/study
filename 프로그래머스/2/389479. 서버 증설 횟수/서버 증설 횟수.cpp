#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int,queue<int>> piq;
vector<int> servers(24);
vector<piq> add(24,{0,{}});

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    servers[0]=players[0]/m;
    add[0].first=servers[0];
    if(add[0].first>0)add[0].second.push(k);
    answer+=add[0].first;
    
    for(int i=1;i<24;i++){
        int plan=players[i]/m;
        bool can_add=false;
        if(plan>servers[i-1]){
            servers[i]=plan;
            can_add=true;
            add[i].first+=plan-servers[i-1];
        }
        else {
            servers[i]=servers[i-1];
        }
        while(!add[i-1].second.empty()){
            int t=add[i-1].second.front();
            add[i-1].second.pop();
            t--;
            if(t>0){
                add[i].second.push(t);
            }
            else{
                int diff;
                if(i-k>0)diff=add[i-k].first;
                else diff=add[0].first;
                servers[i]-=diff;
                if(plan>servers[i]){
                    can_add=true;
                    add[i].first+=plan-servers[i];
                    servers[i]=plan;
                }
            }
        }
    if(can_add)add[i].second.push(k);
    answer+=add[i].first;
    }
    
    return answer;
}