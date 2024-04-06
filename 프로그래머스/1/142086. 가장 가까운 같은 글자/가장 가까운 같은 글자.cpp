#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alpa(26,-1);
    for(int i=0;i<s.length();i++){
        int c=s[i]-'a';
        if(alpa[c]==-1){
            answer.push_back(-1);
        }
        else{
            answer.push_back(i-alpa[c]);
        }
        alpa[c]=i;
    }
    return answer;
}