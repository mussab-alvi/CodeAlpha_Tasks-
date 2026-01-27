#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    string gradeLetter[50];   // store letter grades
    double grades[50];        // store numeric values
    int credits[50];
    double totalGradePoints = 0;
    int totalCredits = 0;

    cout << "Enter number of courses: ";
    cin >> n;

    cout << "\nGrading System:\n";
    cout << "A+ : 90 and above → 4.0\n";
    cout << "A- : 85-89       -> 3.7\n";
    cout << "A  : 80-84       -> 3.5\n";
    cout << "B+ : 75-79       -> 3.3\n";
    cout << "B  : 70-74       -> 3.0\n";
    cout << "B- : 65-69       -> 2.7\n";
    cout << "C+ : 60-64       -> 2.3\n";
    cout << "C  : 55-59       -> 2.0\n";
    cout << "D  : 40-54       -> 1.0\n";
    cout << "F  : Below 33    -> 0.0\n";

    for(int i = 0; i < n; i++) {
        cout << "\nEnter grade (A+ or a+, A- or a-, A or a, B+ or b+, B or b, B- or b-, C+ or c+, C or c, D+ or d+, D or d, F ) for course " << i+1 << ": ";
        cin >> gradeLetter[i];
        cout << "Enter credit hours for course " << i+1 << ": ";
        cin >> credits[i];

        double gradeValue;
        if(gradeLetter[i] == "A+" || (gradeLetter[i] == "a+")) gradeValue = 4.0;
        else if(gradeLetter[i] == "A-" || (gradeLetter[i] == "a-")) gradeValue = 3.7;
        else if(gradeLetter[i] == "A" || (gradeLetter[i] == "a")) gradeValue = 3.5;
        else if(gradeLetter[i] == "B+" || (gradeLetter[i] == "b+")) gradeValue = 3.3;
        else if(gradeLetter[i] == "B" || (gradeLetter[i] == "b")) gradeValue = 3.0;
        else if(gradeLetter[i] == "B-" || (gradeLetter[i] == "b-")) gradeValue = 2.7;
        else if(gradeLetter[i] == "C+" || (gradeLetter[i] == "c+")) gradeValue = 2.3;
        else if(gradeLetter[i] == "C" || (gradeLetter[i] == "c")) gradeValue = 2.0;
        else if(gradeLetter[i] == "D" || (gradeLetter[i] == "d")) gradeValue = 1.0;
        else if(gradeLetter[i] == "F" || (gradeLetter[i] == "f")) gradeValue = 0.0;
        else {
            cout << "Invalid grade entered! Try again.\n";
            i--; // repeat this iteration
            continue;
        }

        grades[i] = gradeValue;
        totalCredits += credits[i];
        totalGradePoints += grades[i] * credits[i];
    }

    double cgpa = totalGradePoints / totalCredits;

    cout << "\n-----------------------------------\n";
    cout << "Course\tGrade\tValue\tCredits\n";
    cout << "-----------------------------------\n";
    for(int i = 0; i < n; i++) {
        cout << (i+1) << "\t" << gradeLetter[i] << "\t" << grades[i] << "\t" << credits[i] << endl;
    }
    cout << "-----------------------------------\n";
    cout << fixed << setprecision(2) << "Final CGPA: " << cgpa << endl;

    return 0;
}
