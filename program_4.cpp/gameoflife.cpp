/**
* Program-4: Game of Life
* Gracie Latham 
* Description:
*     This program modifies the game of life to create a glider gun and cause the moving spaces to
pass through the bottem back to the top
* Course: 1063 Data Structures
* Semester: Spring 2017
* Date:05 01 2017
*/
#include <iostream>
#include <string>
#include <fstream>

// #ifdef __cplusplus__
// #include <cstdlib>
// #else
// #include <stdlib.h>
// #endif

#include <unistd.h>

using namespace std;

class GameOfLife{
private:
    int **Board;
    int **Board2;
    int Rows;
    int Cols;
public:
    GameOfLife(string filename){
        string line;
        char ch;
        ifstream fin;
        fin.open(filename);
        fin >> Rows >> Cols;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                fin.get(ch);
                if (ch == 10){
                    continue;
                }
                Board[i][j] = int(ch) - 48;
            }
        }
    }
    
    GameOfLife(int r, int c){
        Rows = r;
        Cols = c;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        PrintBoard();
    }
    
    void InitBoardArray(int **&b){
        b = new int*[Rows];
        for (int i = 0; i < Rows; i++){
            b[i] = new int[Cols];
        }
        ResetBoardArray(b);
    }
    
    void ResetBoardArray(int **&b){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                b[i][j] = 0;
            }
        }
    }
    
    void PrintBoard(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (Board[i][j] == 1)
                    cout << char('X');
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    
    int CountNeighbors(int row, int col){
        int neighbors = 0;
        int up, down, left, right;
        
        if(row == 0){
          up = Rows - 1;
        }else{
          up = (row + 1) % Rows; 
        }
          
          down = (row + 1) % Rows;
          
        if(col == 0){
          left = Cols - 1; 
        }else{
          left = (col + 1) % Cols; 
        }
        
        right = (col + 1) % Cols; 
        
        if (Board[row][col] == 1){
            neighbors--;
        }
  
        for(int i = up; i != (down + 1) % Rows; i = (i + 1) % Rows){
          for(int j = left; j != (right + 1) % Cols; j = (j + 1) % Cols){
            if(OnBoard(i, j)){
              neighbors += Board[i][j];
            }
          }
        }
        return neighbors;
    }
    
    bool OnBoard(int row, int col){
        return (row >= 0 && row < Rows && col >= 0 && col < Cols);
    }
    
    void RandomPopulate(int num){
        int r = 0;
        int c = 0;
        for (int i = 0; i<num; i++){
            r = rand() % Rows;
            c = rand() % Cols;
            Board[r][c] = 1;
        }
    }
    
    void SetCell(int r, int c, int val){
        Board[r][c] = val;
    }
    
    void AddGens(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                Board[i][j] += Board2[i][j];
            }
        }
        ResetBoardArray(Board2);
    }
    
    void clear_screen(int lines){
      for(int i=0;i<lines;i++){
        cout<<endl;
      }
    }
    
    void Run(int generations=99999){
        int neighbors = 0;
        int g = 0;
        bool Stable = false;
        while (g < generations && Stable == false){
            for (int i = 0; i < Rows; i++){
                for (int j = 0; j < Cols; j++){
                    neighbors = CountNeighbors(i, j);
                    if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                        Board2[i][j] = -1;
                    }
                    if (Board[i][j] == 1 && iscorner(i, j)){
                      Board[i][j] = -1;
                    }
                    if (Board[i][j] == 0 && neighbors == 3){
                        Board2[i][j] = 1;
                    }
                }
            }
            Stable = stable(); 
            AddGens();
            usleep(100000);
            clear_screen(30);
            PrintBoard();
            g++;
        }
        
    }
    
    bool iscorner(int row, int col){
      if ((row == 0) || row == Rows - 1 && (col == 0) || col == Cols - 1)
          return true;
      
      return false; 
    }
    
    bool stable(){
      for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
           
           if(Board[i][j] != Board[i][j] + Board2[i][j])
              return false;
         }
      }
      
      return true; 
    
    }
    
    void glidergun(){
      if(Rows >= 11 && Cols >= 38){
        ResetBoardArray(Board);
        ResetBoardArray(Board2);
        string line;
        char ch;
        ifstream fin;
        fin.open("glider.txt");
        for (int i = 0; i <= 11; i++){
            for (int j = 0; j <= 38; j++){
                fin.get(ch);
                if (ch == 10){
                    continue;
                }
                Board[i][j] = int(ch) - 48;
            }
        }
        fin.close();
      }
      
    }
};

int main(){
  
    GameOfLife.open("gen_one.txt");
    
    G.glidergun();

    G.Run(100); 
    return 0;
}
