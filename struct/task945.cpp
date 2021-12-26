#include <iostream>
#include <fstream>
#include <map>

using namespace std;

struct Student
{
    int id;
    long scores;
};

int main() {
    ifstream inputFile("INPUT.TXT");
    ofstream outputFile("OUTPUT.TXT");
    if (!inputFile) {
        outputFile << "File Reading Error!" << endl;
        return 1;
    }

    int countStudents;
    inputFile >> countStudents;
    int countRequest;
    inputFile >> countRequest;
    auto *students = new Student[countStudents];
    long scores = 0;
    for (int i = 0; i < countStudents; i++)
    {
        inputFile >> scores;
        students[i] = {i, scores};
    }

    long request;
    for (int i = 0; i < countRequest; i++) {
        inputFile >> request;
        bool studentFound = false;
        for(int j = 0; j < countStudents && !studentFound; j++)
            studentFound = students[j].scores == request;
        if (studentFound)
            outputFile << "YES";
        else
            outputFile << "NO";
        outputFile << ' ';
    }

    outputFile.close();
    return 0;
}