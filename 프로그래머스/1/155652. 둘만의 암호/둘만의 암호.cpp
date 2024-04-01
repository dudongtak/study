#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> vec(26,0);
    for(int i=0;i<skip.length();i++){
        int j=skip[i]-'a';
        vec[j]=1;
    }
    for(int i=0;i<s.length();i++){
        char c=s[i];
        int j=c-'a';
        int k=0;
        while(true){
            int l=k+j+1;
            l%=26;
            if(vec[l]==1){
                j++;
            }
            else{
                k++;
            }
            if(k>=index)break;
        }
        j+=k;
        j%=26;
        c=j+'a';
        answer+=c;
    }
    return answer;
}