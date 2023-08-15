#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream fin("table.txt");
    int numStudents = 0;
    double avgNumGrade = 0.0;
    cout << setw(30) << "STUDENT STATISTICS" << endl;
    cout << setfill(' ') << setw(15) << "Student Name" << setw(15) << "Total Points" << setw(15) <<  "Numeric Grade" << setw(15) << "Letter Grade" << endl;
    string line;
    while (getline(fin, line)) {
        string name;
        double testGrade;
        int assnGrade;
        double totalPoints;
        double numGrade;
        char letterGrade;

        fin >> name;
        cout << setw(10) << left << name << setfill(' ');
        fin >> testGrade;
        fin >> assnGrade;
        totalPoints = testGrade + assnGrade;
        numGrade = totalPoints / 2;
        if (numGrade <= 100 && numGrade >= 89.5) {
            letterGrade = 'A';
        }
        else if (numGrade <= 89.49 && numGrade >= 79.5) {
            letterGrade = 'B';
        }
        else if (numGrade <= 79.49 && numGrade >= 69.5) {
            letterGrade = 'C';
        }
        else if (numGrade <= 69.49 && numGrade >= 59.5) {
            letterGrade = 'D';
        }
        else if (numGrade <= 59.49 && numGrade >= 0) {
            letterGrade = 'F';
        }
        cout << setw(5) << right << setprecision(3) << totalPoints << setfill(' ') << numGrade << setfill(' ');
        cout << setw(5) << letterGrade << endl;
        numStudents++;
        avgNumGrade = avgNumGrade + numGrade;
    }
    avgNumGrade = avgNumGrade / numStudents;

    cout << setw(30) << "CLASS STATISTICS" << endl;
    cout << setw(15) << left << "Number:" << setfill(' ') << numStudents << endl;
    cout << setw(15) << left << "Average:" << setfill(' ') << avgNumGrade << endl;
    fin.close();
}