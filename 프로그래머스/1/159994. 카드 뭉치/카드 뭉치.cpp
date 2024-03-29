#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int i=0;
    int j=0;
    for(int k=0;k<goal.size();k++){
        if(i<cards1.size()&&cards1[i]==goal[k]){
            i++;
        }
        else if(j<cards2.size()&&cards2[j]==goal[k]){
            j++;
        }
        else{
            return "No";
        }
    }
    return "Yes";
}