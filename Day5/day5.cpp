#include "bits/stdc++.h"
using namespace std;

vector<string> text_justify (vector<string>& words, int max_width) {
    vector<string> res;
    int i = 0;

    while (i < words.size()) {
        int j = i, lineLength = 0;
        while (j < words.size() && lineLength + words[j].size() + (j - i) <= max_width) {
            lineLength += words[j].size();
            j++;
        }

        int spaces = max_width - lineLength;
        int numWords = j - i;

        string line = words[i];
        if (numWords == 1 || j == words.size()) {
            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }
            line += string(max_width - line.size(), ' ');
        } else {
            for (int k = i + 1; k < j; k++) {
                int spacesToAdd = spaces / (numWords - 1);
                if (k - i <= spaces % (numWords - 1)) {
                    spacesToAdd++;
                }
                line += string(spacesToAdd, ' ') + words[k];
                spaces -= spacesToAdd;
                numWords--;
            }
        }

        res.push_back(line);
        i = j;
    }

    return res;
}

int main() {
    int word_count,max_width;
    cin >> word_count;
    vector<string> words(word_count);
    for(int i=0;i<word_count;i++)cin >> words[i];
    cin >> max_width;
    vector<string> result = text_justify (words, max_width);
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
    return 0;
}

