#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    for(int i=0;i<photo.size();i++){
        int point=0;
        int j;
        for(j=0;j<photo[i].size();j++){
            int k;
            for(k=0;k<name.size();k++){
                if(photo[i][j]==name[k]){
                    break;
                }
            }
            if(k<name.size()){
                point+=yearning[k];
            }
        }
        answer.push_back(point);
    }
    return answer;
}