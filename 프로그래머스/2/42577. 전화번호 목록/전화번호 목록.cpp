#include <string>
#include <vector>
#include<map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string,int> m;
    for(int i=0;i<phone_book.size();i++){
        m[phone_book[i]]=i+1;
    }
    for(int i=0;i<phone_book.size();i++){
        string tmp="";
        for(int j=0;j<phone_book[i].size();j++){
            tmp+=phone_book[i][j];
            if(m[tmp]!=0&&m[tmp]!=i+1){
                answer=false;
                break;
            }
        }
        if(!answer)break;
    }
    return answer;
}