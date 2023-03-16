#include "Mover.h"
#include <iostream>
using namespace std;
// moves algorithms in different directions
void Up(int** A, int N, int& TotalScore) {
    int temp;
    int stop = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < N;i++) {
            if (A[i][j] == 0) {
                continue;
            }
            else {
                temp = i;
                while (temp > stop) {
                    if (A[temp - 1][j] == A[temp][j]) {
                        A[temp - 1][j] += A[temp][j];
                        TotalScore += A[temp - 1][j];
                        stop = temp;
                        A[temp][j] = 0;
                        break;
                    }
                    if ((A[temp - 1][j] != A[temp][j]) && (A[temp - 1][j] != 0)) {
                        break;
                    }
                    std::swap(A[temp - 1][j], A[temp][j]);
                    temp--;
                }
            }
        }
        stop = 0;
    }
}
void Down(int** A, int N, int& TotalScore) {
    int temp;
    int stop = N - 1;
    for (int j = 0; j < N; j++) {
        for (int i = N - 2; i >= 0; i--) {
            if (A[i][j] == 0) {
                continue;
            }
            else {
                temp = i;
                while (temp < stop) {
                    if (A[temp + 1][j] == A[temp][j]) {
                        A[temp + 1][j] += A[temp][j];
                        TotalScore += A[temp + 1][j];
                        stop = temp;
                        A[temp][j] = 0;
                        break;
                    }
                    if ((A[temp + 1][j] != A[temp][j]) && (A[temp + 1][j] != 0)) {
                        break;
                    }
                    std::swap(A[temp + 1][j], A[temp][j]);
                    temp++;
                }
            }
        }
        stop = N - 1;
    }
}
void Right(int** A, int N, int& TotalScore) {
    int temp;
    int stop = N - 1;
    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (A[i][j] == 0) {
                continue;
            }
            else {
                temp = j;
                while (temp < stop) {
                    if (A[i][temp + 1] == A[i][temp]) {
                        A[i][temp + 1] += A[i][temp];
                        TotalScore += A[i][temp + 1];
                        stop = temp;
                        A[i][temp] = 0;
                        break;
                    }
                    if ((A[i][temp + 1] != A[i][temp]) && (A[i][temp + 1] != 0)) {
                        break;
                    }
                    std::swap(A[i][temp + 1], A[i][temp]);
                    temp++;
                }
            }
        }
        stop = N - 1;
    }
}
void Left(int** A, int N, int& TotalScore) {
    int temp;
    int stop = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (A[i][j] == 0) {
                continue;
            }
            else {
                temp = j;
                while (temp > stop) {
                    if (A[i][temp - 1] == A[i][temp]) {
                        A[i][temp - 1] += A[i][temp];
                        TotalScore += A[i][temp - 1];
                        stop = temp;
                        A[i][temp] = 0;
                        break;
                    }
                    if ((A[i][temp - 1] != A[i][temp]) && (A[i][temp - 1] != 0)) {
                        break;
                    }
                    std::swap(A[i][temp - 1], A[i][temp]);
                    temp--;
                }
            }
        }
        stop = 0;
    }
}
