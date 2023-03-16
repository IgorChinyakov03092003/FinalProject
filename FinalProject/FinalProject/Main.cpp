#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Mover.h"
#include "Corrector.h"
#include "Additional.h"
using namespace std;
int RandomNumbers[] = { 2,2,2,2,4,2,2,2,2,2 };  // array of random numbers (90% - 2, 10% - 4)
int TotalScore = 0;     // Total Score
struct Cell {
    int x = 0;
    int y = 0;
};  // Cell structure
void generator(std::vector<Cell>& AlivePoints, std::vector<Cell>& DeadPoints) { // generate 2 random nums at the beginning of the game
    srand(time(NULL));
    int R1 = 0 + rand() % (DeadPoints.size() - 1 - 0 + 1);
    auto iter = DeadPoints.cbegin();
    AlivePoints.push_back(DeadPoints[R1]);
    DeadPoints.erase(iter + R1);
    iter = DeadPoints.cbegin();
    int R2 = 0 + rand() % (DeadPoints.size() - 1 - 0 + 1);
    AlivePoints.push_back(DeadPoints[R2]);
    DeadPoints.erase(iter + R2);
}
int GetRandomNumber(int arr[], int N) {
    return arr[0 + rand() % (N - 1 - 0 + 1)];       // Number generation
}
void filler(int** Gamepole, std::vector<Cell>& AlivePoints, std::vector<Cell>& DeadPoints) {
    srand(time(NULL));
    for (int i = 0; i < AlivePoints.size(); i++) {
        Gamepole[AlivePoints[i].x][AlivePoints[i].y] = GetRandomNumber(RandomNumbers, 10);
    }
    for (int i = 0; i < DeadPoints.size(); i++) {
        Gamepole[DeadPoints[i].x][DeadPoints[i].y] = 0;
    }
}   // fill GamePole using Dead and Alive Points
void NewNum(int** GamePole, std::vector<Cell>& DeadPoints, int N, Cell cell) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (GamePole[i][j] == 0) {
                cell.x = i;
                cell.y = j;
                DeadPoints.push_back(cell);
            }
        }
    }
    auto iter = DeadPoints.cbegin();
    int R = 0 + rand() % (DeadPoints.size() - 1 - 0 + 1);
    GamePole[DeadPoints[R].x][DeadPoints[R].y] = GetRandomNumber(RandomNumbers, 10);
    DeadPoints.erase(iter + R);
}   // adding a new num after move
int main() {
    int N;
    cout << "Game2048 by @i_v_c. Version 1.0.1" << endl;
    cout << "Enter the size of Game Pole:" << endl;
    std::cin >> N;
    if ((N <= 2) || (N > 8)) {
        std::cout << "Error!" << std::endl;
    }   // Game Pole Size
    else {
        cout << endl;
        int** GamePole;
        GamePole = new int* [N];
        for (int i = 0; i < N; i++) {
            GamePole[i] = new int[N];
        }   // new game pole
        int** PrevPole;
        PrevPole = new int* [N];
        for (int i = 0; i < N; i++) {
            PrevPole[i] = new int[N];
        }   // to save previous moves
        std::vector<Cell> AlivePoints;
        std::vector<Cell> DeadPoints;
        Cell cell;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cell.x = i;
                cell.y = j;
                DeadPoints.push_back(cell);
            }
        }
        generator(AlivePoints, DeadPoints);
        filler(GamePole, AlivePoints, DeadPoints);
        PrintPole(GamePole, N);
        cout << "Possible commands:" << endl;
        cout << "w - Up; s - Down; a - Left; d - Right; c - Cancel Your Last Move; e - End the game" << endl;
        cout << "Don't forget to set ENG lang and lowercase on your keyboard!" << endl;
        cout << "Remember that you can cancel only your 1 move!" << endl;
        cout << "Good luck!" << endl;
        char c; // for commands
        void(*Move)(int**, int, int&) = NULL;   // to make moves
        int(*TryMove)(int**, int) = NULL;       // to try if the move is correct
        AlivePoints.clear();
        int PrevScore = 0;
        int IsWinned = 0;       // victory indicator
        Copy(GamePole, PrevPole, N);    // save starting position
        while (1) {     // game process
            c = _getch();
            if (c == 'c') {
                system("cls");
                Copy(PrevPole, GamePole, N);
                TotalScore = PrevScore;
                PrintPole(GamePole, N);
                cout << "Your total score is: " << TotalScore << endl;
                continue;
            }   // cancel 1 last move
            if ((c != 'w') && (c != 's') && (c != 'a') && (c != 'd') && (c != 'e')) {
                cout << "Impossible command!" << endl;
                continue;
            }
            else {
                if (c == 'e') {
                    cout << "You ended the game!" << endl;
                    break;
                }
                if (c == 'w') {
                    Move = Up;
                    TryMove = TryUp;

                }
                if (c == 's') {
                    Move = Down;
                    TryMove = TryDown;
                }
                if (c == 'a') {
                    Move = Left;
                    TryMove = TryLeft;
                }
                if (c == 'd') {
                    Move = Right;
                    TryMove = TryRight;
                }   // save moves
                system("cls");
                if (TryMove(GamePole, N) == 0) {
                    cout << "Impossible Move!" << endl;
                    PrintPole(GamePole, N);
                    cout << "Your total score is: " << TotalScore << endl;
                    continue;
                }   // check if the move is possible
                Copy(GamePole, PrevPole, N);
                PrevScore = TotalScore;
                Move(GamePole, N, TotalScore);  // make correct move
                DeadPoints.clear();
                NewNum(GamePole, DeadPoints, N, cell);
                PrintPole(GamePole, N);
                cout << "Your total score is: " << TotalScore << endl;
                // GameOver situation
                if (TryUp(GamePole, N) == 0 && TryDown(GamePole, N) == 0 && TryLeft(GamePole, N) == 0 && TryRight(GamePole, N) == 0) {
                    cout << "Gameover!" << endl;
                    cout << "Wanna cancel your last move? Press c for that! Press any other key to exit!" << endl;
                    c = _getch();
                    if (c == 'c') {
                        system("cls");
                        Copy(PrevPole, GamePole, N);
                        TotalScore = PrevScore;
                        PrintPole(GamePole, N);
                        cout << "Your total score is: " << TotalScore << endl;
                        continue;
                    }
                    else {
                        break;
                    }
                }
                // Victory situation
                if ((IsVictory(GamePole, N) == 1) && (IsWinned == 0)) {
                    IsWinned = 1;   // update victory indicator
                    cout << "You've won! My congratulations!" << endl;
                    cout << "Wanna continue the game? Press c for that! Press any other key to exit!" << endl;
                    c = _getch();
                    if (c == 'c') {
                        system("cls");
                        PrintPole(GamePole, N);
                        cout << "Your total score is: " << TotalScore << endl;
                        continue;
                    }   // continue the game after victory (to make a high-score)
                    else {
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            delete[] GamePole[i];
        }
        delete[] GamePole;
        for (int i = 0; i < N; i++) {
            delete[] PrevPole[i];
        }
        delete[] PrevPole;
    }
}