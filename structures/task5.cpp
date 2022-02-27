#include <iostream>

using namespace std;

struct Student {
    string name;
    string element;
    int victories;
};

int isWinner(string playerElem, string opponentElem) {
    if (playerElem == "scissors") {
        if (opponentElem == "stone") return -1;
        if (opponentElem == "paper") return 1;
    }
    else if (playerElem == "stone") {
        if (opponentElem == "paper") return -1;
        if (opponentElem == "scissors") return 1;
    }
    else if (playerElem == "paper") {
        if (opponentElem == "scissors") return -1;
        if (opponentElem == "stone") return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    auto* students = new Student[n];
    string t;
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].element;
    }

    int game;
    int maxVictories = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) {
            game = isWinner(students[i].element, students[j].element);
            if (game == 1)
                students[i].victories++;
            else if (game == -1)
                students[j].victories++;
            maxVictories = max(maxVictories, max(students[i].victories, students[j].victories));
        }
    for (int i = 0; i < n; i++)
        if (students[i].victories == maxVictories)
            cout << students[i].name << ": " << students[i].victories << endl;
}

