#include <string>
#include <vector>
#include<math.h>
using namespace std;

int makeString(vector<string> k,string s){
    int num=0;
    for(int i=0;i<s.length();i++){
        int n=101;
        bool flag=false;
        for(int j=0;j<k.size();j++){
            for(int l=0;l<k[j].size();l++){
                if(k[j][l]==s[i]){
                    n=min(n,l+1);
                    flag=true;
                }
            }
        }
        if(flag==false)return -1;
        num+=n;
    }
    return num;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(int i=0;i<targets.size();i++){
        answer.push_back(makeString(keymap,targets[i]));
    }
    return answer;
}