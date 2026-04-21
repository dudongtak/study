#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<string> words;
    vector<bool> length(message.size(),false);
    vector<pair<int,int>> idx;
    int s=0,e=0;
    string str="";
    while(e<message.size()){
        if(message[e]==' '){
            words.push_back(str);
            idx.push_back({s,e-1});
            s=e+1;
            e=s;
            str="";
            continue;
        }
        str+=message[e++];
    }
    words.push_back(str);
    idx.push_back({s,e-1});
    vector<bool> spo(words.size(),false);
    for(int i=0;i<spoiler_ranges.size();i++){
        for(int j=spoiler_ranges[i][0];j<=spoiler_ranges[i][1];j++){
            length[j]=true;
        }
    }
    for(int i=0;i<idx.size();i++){
        for(int j=idx[i].first;j<=idx[i].second;j++){
            if(length[j]){
                spo[i]=true;
                break;
            }
        }
    }
    map<string,int> check;
    
    for(int i=0;i<words.size();i++){
        if(spo[i])continue;
        check[words[i]]++;
    }
    
    for(int i=0;i<spo.size();i++){
        if(spo[i]&&check[words[i]]==0)answer++;
        check[words[i]]++;
    }
    
    return answer;
}