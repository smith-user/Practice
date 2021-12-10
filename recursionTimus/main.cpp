#include <iostream>

using namespace std;

const int N = 4;
char arr[N][N];
int step[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0,  -1}};

int fillWord(string word, int line, int column, int index) {
    if (index == word.length() || word[index] != arr[line][column])
        return index;
    int result;
    arr[line][column] = '*';
    int newLine, newColumn;
    for(auto move : step) {
        newLine = line + move[0];
        newColumn = column + move[1];
        if (newLine < 4 && newLine >= 0 && newColumn < 4 && newColumn >= 0)
            result = fillWord(word, newLine, newColumn, index + 1);
        else
            continue;
        if (result == word.length())
            break;
    }
    arr[line][column] = word[index];
    return result;
}

int main() {
    /* Fill Field (arr)*/
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++)
            arr[i][j] = str[j];
    }
    /* Fill Field (arr)*/

    string result, word;
    int resultFunction, wordsCount;
    bool bFlag;
    cin >> wordsCount;
    for (int i = 0; i < wordsCount; i++) {
        bFlag = true;
        resultFunction = 0;
        cin >> word;
        result += (word + ": ");
        for(int line = 0; line < N && bFlag; line++)
            for(int column = 0; column < N && bFlag; column++)
                if (word[0] == arr[line][column]) {
                    resultFunction = fillWord(word,line,column,0);
                    if (resultFunction == word.length()) {
                        result += "YES\n";
                        bFlag = false;
                    }
                }
        if (bFlag)
            result += "NO\n";
    }
    result.pop_back();
    cout << result << endl;
    return 0;
}