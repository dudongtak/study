#include <string>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

bool cmp(const pair<string,int> &a,const pair<string,int> &b){
    return a.second<b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> mP;
    map<int,string> mR;
    for(int i=0;i<players.size();i++){
        mP[players[i]]=i;
        mR[i]=players[i];
    }
    for(int i=0;i<callings.size();i++){
        int idx=mP[callings[i]];
        string name=mR[idx-1];
        mR[idx-1]=callings[i];
        mR[idx]=name;
        mP[name]++;
        mP[callings[i]]--;
    }
    vector<string> answer;
    for(int i=0;i<players.size();i++){
        answer.push_back(mR[i]);
    }
    return answer;
}