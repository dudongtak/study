#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

string makeNum(string x, string y){
    string tmp1,tmp2;
    
    if(x.length()>y.length()){tmp1=x;tmp2=y;}
    else{tmp1=y;tmp2=x;}
    
    vector<char> vc;
    map<char,int> m;
    for(int i=0;i<tmp2.length();i++){
        m[tmp2[i]]++;
    }
    
    for(int i=0;i<tmp1.length();i++){
        if(m[tmp1[i]]!=0){
            m[tmp1[i]]--;
            vc.push_back(tmp1[i]);
        }
    }
    sort(vc.begin(),vc.end());
    string tmp="";
    for(int i=vc.size()-1;i>=0;i--){
        tmp+=vc[i];
    }
    return tmp;
}

string solution(string X, string Y) {
    string answer = makeNum(X,Y);
    if(answer.length()==0)answer="-1";
    if(answer.length()>1&&answer[0]=='0')answer="0";
    return answer;
}