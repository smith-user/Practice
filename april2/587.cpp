#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Vector
{
private:
    double x = 0;
    double y = 0;
    double angle = 0;
public:
    Vector(){};
    Vector(double length, double degDirection)
    {
        angle = degDirection * acos(-1) / 180;
        x = length * cos(angle);
        y = length * sin(angle);
    }
    Vector(double x, double y, char t):
            x(x), y(y)
    {
        angle = tan(y/x);
    }
    ~Vector(){}

    double GetLength() const
    {
        return sqrt(x*x + y*y);
    }

    double GetAngle()
    {
        return angle;
    }

    void Add(const Vector& vector)
    {
        x += vector.x;
        y += vector.y;
        angle = tan(y/x);
    }

    static Vector Add(Vector v1, Vector v2)
    {
        v1.Add(v2);
        return v1;
    }
};

struct Engine
{
    int idx;
    Vector vector;
    Engine(int idx, const Vector& vector):
            idx(idx), vector(vector){}
};

bool bCosIsPositive(double direction)
{
    return cos(direction * acos(-1) / 180) - 10e-6 > 0;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    vector<int> turnOn;
    vector<Engine> engines;
    Vector sum;
    Vector engine90;
    Vector engine270;
    for(int i = 0; i < N; i++)
    {
        double dPower, dDirection;
        inputFile >> dPower >> dDirection;
        Vector t = Vector(dPower,dDirection);

        if(bCosIsPositive(dDirection))
        {
            sum.Add(t);
            turnOn.push_back(i + 1);
        }
        else
        {
            if (abs(t.GetAngle() - acos(-1)/2) < 10e-5)
                engine90.Add(t);
            else if (abs(t.GetAngle() - 3 * acos(-1) / 2) < 10e-5)
                engine270.Add(t);
            engines.push_back(Engine(i + 1, t));
        }
    }

    bool turnOn90 = Vector::Add(sum, engine90).GetLength() > Vector::Add(sum, engine270).GetLength();
    if(turnOn90)
        sum.Add(engine90);
    else
        sum.Add(engine270);

    for(auto engine : engines)
    {
        double angle = engine.vector.GetAngle();
        if ((abs(angle - acos(-1)/2) < 10e-5 and turnOn90) or abs(angle - 3*acos(-1)/2) < 10e-5)
            turnOn.push_back(engine.idx);
    }

    outputFile << turnOn.size() << endl;
    for (auto i : turnOn)
    {
        outputFile << i << ' ';
    }

    inputFile.close();
    outputFile.close();
}