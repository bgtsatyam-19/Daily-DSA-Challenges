//Text Justification
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;

        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;

            while (last < n) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }

            string line;
            int numberOfWords = last - index;
            if (last == n || numberOfWords == 1) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - totalChars + (numberOfWords - 1);
                int spaceBetweenWords = totalSpaces / (numberOfWords - 1);
                int extraSpaces = totalSpaces % (numberOfWords - 1);

                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) {
                        line += string(spaceBetweenWords + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }
            result.push_back(line);
            index = last;
        }

        return result;
    }
};
int main(){
    Solution obj;
    vector<string> words={"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth=16;
    vector<string> result=obj.fullJustify(words,maxWidth);
    for(const auto& line:result){
        cout<<"'"<<line<<"'"<<endl; 
    }
    return 0;
}
