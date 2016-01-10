//
//  main.cpp
//  Connect 4
//
//  Created by Ricardo Rodriguez on 1/9/16.
//  Copyright © 2016 Ricardo Rodriguez. All rights reserved.
//

#include <iostream>

using namespace std;

char board[6][7];

void display(){
    cout << " 1 2 3 4 5 6 7"<< endl;
    for (int i = 0; i < 6; i++) {
        cout << " _ _ _ _ _ _ _"<< endl;
        for (int j = 0; j < 7; j++) {
            cout << "|" << board[i][j];
        }
        cout << "|" <<endl;
    }
    cout << " _ _ _ _ _ _ _"<<endl;
}

bool dropChip(int col, char token){
    if (board[5][col-1] == ' ') {
        board[5][col-1] = token;
        return true;
    }
    for (int i = 0; i < 5; i++) {
        if (board[i][col-1] == ' ' && board[i+1][col-1] != ' ') {
            board[i][col-1] = token;
            return true;
        }
    }
    return false;
}

bool checkWin(char token){
    //Check for vertical wins
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[j][i] == token && board[j+1][i] == token && board[j+2][i] == token && board[j+3][i] == token) {
                return true;
            }
        }
    }
    //Check for horizontal wins
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == token && board[i][j+1] == token && board[i][j+2] == token && board[i][j+3] == token) {
                return true;
            }
        }
    }
    //Check for diagonal forward /
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            if (board[i][j] == token && board[i+1][j-1] && board[i+2][j-2] && board[i+3][j-3]) {
                return true;
            }
        }
    }
    /* Check for diagonal reverse \ */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == token && board[i+1][j+1] && board[i+2][j+2] && board[i+3][j+3]) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    bool isX = true;
    bool isWin = false;
    int col;
    
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }
    /*board[0][0] = 'X';
    board[5][6] = 'O';
    display();*/
    
    display();
    
    while (true) {
        if (isX) {
            cout << "Player X select column from 1-7 to drop token in: ";
            cin >> col;
            if (!dropChip(col, 'X')) {
                cerr << "column full"<<endl;
            }else{
                if (checkWin('X')) {
                    display();
                    cout << "X Wins!"<<endl;
                    break;
                }else{
                    display();
                    isX = false;
                }
            }
        } else{
            cout << "Player O select column from 1-7 to drop token in: ";
            cin >> col;
            if (!dropChip(col, 'O')) {
                cerr << "column full"<<endl;
            }else{
                if (checkWin('O')) {
                    display();
                    cout << "O Wins!"<<endl;
                    break;
                }else{
                    display();
                    isX = true;
                }
            }
        }
    }
    
    
    return 0;
}




