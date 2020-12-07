// FirstProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int classroom1[7][2][7][6] = { 0 };
int StudentNums[5][4];
int curX[7];
int curY[7];
int group[7];

int arrSize = 0;
int counted = 0;
int student;
bool checkIf(int x, int y[]) {
    for (int i = 0; i < arrSize; i++) {
        if (x == y[i]) {
            return false;
        }
    }
    return true;
}
void printStudentList(int x[]) {
    for (int i = 0; i < arrSize; i++) {
        if (x[i] != 0) {
            cout << x[i] << " ";
        }
    }
}
void chairCounter() {

    for (int i = 0; i < 7; i++) {
        int xP1 = curX[i] + 1;
        int xM1 = curX[i] - 1;
        int yP1 = curY[i] + 1;
        int yM1 = curY[i] - 1;
        if (classroom1[i][group[i]][xP1][curY[i]] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][xP1][yP1] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][xP1][yM1] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][xM1][curY[i]] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][xM1][yP1] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][xM1][yM1] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][curX[i]][yP1] != 0) {
            arrSize++;
        }
        if (classroom1[i][group[i]][curX[i]][yM1] != 0) {
            arrSize++;
        }
    }

}
void allTwoDPrint() {
    for (int k = 0; k < 7; k++) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 6; j++) {
                if (classroom1[k][group[k]][i][j] == 0) {
                    cout << "*\t";
                }
                else {
                    cout << classroom1[k][group[k]][i][j] << "\t";
                }
            }
            cout << endl;
        }
        cout << endl << endl << endl;
    }
}
void findLocation(int x) {
    for (int k = 0; k < 7; k++) {
        for (int i = 1; i < 6; i++) {
            for (int j = 1; j < 5; j++) {
                if (x == classroom1[k][0][i][j]) {
                    curX[k] = i;
                    curY[k] = j;
                    group[k] = 0;
                }
                else if (x == classroom1[k][1][i][j]) {
                    curX[k] = i;
                    curY[k] = j;
                    group[k] = 1;
                }
            }
        }
    }

}
void defineStudentNums() {
    int counter = 0;
    for (int i = 0; i < 5; i++) {
        for (int g = 0; i < 4; i++) {
            StudentNums[i][g] = 100000 + counter;
            counter++;
        }
    }
}
int randRange(int low, int high) {
    return rand() % (high - low + 1) + low;
}
int main()
{
    srand(time(NULL));
    int randClass = 0;
    int randRow = 0;
    int randCol = 0;
    char cont = ' ';
    for (int j = 0; j < 7; j++) {
        for (int i = 1; i < 41; i++) {
            randClass = randRange(0, 1);
            randRow = randRange(1, 5);
            randCol = randRange(1, 4);
            while (classroom1[j][randClass][randRow][randCol] != 0) {
                randClass = randRange(0, 1);
                randRow = randRange(1, 5);
                randCol = randRange(1, 4);
            }
            classroom1[j][randClass][randRow][randCol] = i;
        }
    }
    cout << "Input the student number of the student that has tested positive, all students that sit around them will be listed in order to find who needs to be quarantined." << endl;
    cin >> student;
    cout << endl;
    findLocation(student);
    chairCounter();
    int* stuList = new int[arrSize];
    for (int i = 0; i < 7; i++) {
        int xP1 = curX[i] + 1;
        int xM1 = curX[i] - 1;
        int yP1 = curY[i] + 1;
        int yM1 = curY[i] - 1;
        if (classroom1[i][group[i]][xP1][curY[i]] != 0 && checkIf(classroom1[i][group[i]][xP1][curY[i]], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xP1][curY[i]];
            counted++;
        }
        if (classroom1[i][group[i]][xP1][yP1] != 0 && checkIf(classroom1[i][group[i]][xP1][yP1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xP1][yP1];
            counted++;
        }
        if (classroom1[i][group[i]][xP1][yM1] != 0 && checkIf(classroom1[i][group[i]][xP1][yM1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xP1][yM1];
            counted++;
        }
        if (classroom1[i][group[i]][xM1][curY[i]] != 0 && checkIf(classroom1[i][group[i]][xM1][curY[i]], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xM1][curY[i]];
            counted++;
        }
        if (classroom1[i][group[i]][xM1][yP1] != 0 && checkIf(classroom1[i][group[i]][xM1][yP1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xM1][yP1];
            counted++;
        }
        if (classroom1[i][group[i]][xM1][yM1] != 0 && checkIf(classroom1[i][group[i]][xM1][yM1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][xM1][yM1];
            counted++;
        }
        if (classroom1[i][group[i]][curX[i]][yP1] != 0 && checkIf(classroom1[i][group[i]][curX[i]][yP1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][curX[i]][yP1];
            counted++;
        }
        if (classroom1[i][group[i]][curX[i]][yM1] != 0 && checkIf(classroom1[i][group[i]][curX[i]][yM1], stuList) == true) {
            stuList[counted] = classroom1[i][group[i]][curX[i]][yM1];
            counted++;
        }
    }
    for (int i = counted; i < arrSize; i++) {
        stuList[i] = 0;
    }
    cout << "The students that have been contact traced are:" << endl << endl;
    printStudentList(stuList);
    cout << endl << endl << "Would you like to see the student's schedule? (Y/N) \n";
    cin >> cont;
    cout << endl;
    if (cont == 'y' || cont == 'Y') {
        allTwoDPrint();
    }

    delete[] stuList;
}


