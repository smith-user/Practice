#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class ExamBank
{
private:
    queue<int> exams;
    int CountVariants = 0;
public:
    ExamBank(){}
    ~ExamBank(){}

    int GetCountVariants() const
    {
        return CountVariants;
    }
    void ReturnVariant(int num)
    {
        exams.push(num);
    }

    int TakeVariant()
    {
        int t = exams.front();
        exams.pop();
        return t;
    }

    void IncreaseBank(int newQuantity)
    {
        if (newQuantity <= CountVariants)
            return;
        for(int i = CountVariants + 1; i <= newQuantity; i++)
            exams.push(i);
        CountVariants = newQuantity;
    }
};

struct Student
{
    int x;
    int idx;
    int exam = 0;
    Student(int idx, int x):
            idx(idx),
            x(x) {}
    ~Student(){}

    static bool CompareX(const Student& student1, const Student& student2)
    {
        return student1.x < student2.x;
    }

    static bool CompareIdx(const Student& student1, const Student& student2)
    {
        return student1.idx < student2.idx;
    }
};


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N, D;
    inputFile >> N >> D;
    vector<Student> students;
    for(int i = 0; i < N; i++)
    {
        int coord;
        inputFile >> coord;
        students.push_back(Student(i, coord));
    }

    sort(students.begin(), students.end(), Student::CompareX);

    int idxBegin = 0;
    int idxEnd = 0;
    ExamBank bank;
    bank.IncreaseBank(1);
    for(int i = 0; i < N; i++)
    {
        while( students[i].x - students[idxBegin].x > D)
        {
            bank.ReturnVariant(students[idxBegin].exam);
            idxBegin++;
        }
        while(idxEnd < N and students[idxEnd].x - students[i].x <= D)
            idxEnd++;
        bank.IncreaseBank(idxEnd - idxBegin);
        for(int j = idxBegin; j < idxEnd; j++)
            if (students[j].exam == 0)
                students[j].exam = bank.TakeVariant();
    }

    sort(students.begin(), students.end(), Student::CompareIdx);
    outputFile << bank.GetCountVariants() << endl;
    for(auto one : students)
        outputFile << one.exam << ' ';
    outputFile << endl;

    inputFile.close();
    outputFile.close();
}