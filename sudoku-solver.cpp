#include<bits/stdc++.h>
using namespace std;
#define N 9

class Solution{
    private:
    bool findUnassignedLocation(int mat[N][N], int &x, int &y){
        for (x = 0; x < N;x++){
            for (y = 0; y < N;y++){
                if(mat[x][y] == 0){
                    return true;
                }
            }
        }
        return false;
    }

    bool findInRow(int mat[N][N], int row, int num){
        for (int i = 0; i < N;i++){
            if(mat[row][i] == num){
                return false;
            }
        }
        return true;
    }

    bool findInColumn(int mat[N][N], int col, int num){
        for (int i = 0; i < N;i++){
            if(mat[i][col] == num){
                return false;
            }
        }
        return true;
    }

    bool findInSubMatrix(int mat[N][N], int row, int col, int num){
        int r = row / 3 * 3;
        int c = col / 3 * 3;
        for (int i = r; i < r + 3;i++){
            for (int j = c; j < c + 3;j++){
                if(mat[i][j] == num){
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(int mat[N][N], int row, int col, int num){
        return findInRow(mat, row, num) && findInColumn(mat, col, num) && findInSubMatrix(mat, row, col, num);
    }

    public:
    bool solveSudoku(int mat[N][N]){
        int x = -1, y = -1;
        if (!findUnassignedLocation(mat, x, y)){
            return true;
        }
        for (int num = 1; num <= 9;num++){
            if(isSafe(mat, x, y, num)){
                mat[x][y] = num;
                if(solveSudoku(mat)){
                    return true;
                }
                mat[x][y] = 0;
            }
        }
        return false;
    }
};

int main(void){
    int mat[N][N];
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin >> mat[i][j];
        }
    }
    (new Solution())->solveSudoku(mat);
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}