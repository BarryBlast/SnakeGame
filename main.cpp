#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

#include <conio.h>
using namespace std;



void clearscreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}



void GameBoardFill(string board[][30], int& foodXvalue, int& foodYvalue)
{


    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 30; y++)
        {
            if (x == 0 || x == 29)
            board[x][y] = "#";

            else if (y == 0 || y == 29)
            board[x][y] = "#";

            else if (y == 15 && x == 15)
            board[x][y] = "O";

            else board[x][y] = " ";
        }

    }



}

void feedSnake(string board[][30], int &length, int &foodXvalue, int &foodYvalue, char &movement)
{
    srand(time(NULL));
    if (foodXvalue == 0 && foodYvalue == 0)
    {foodXvalue = rand()%28 +1;
    foodYvalue = rand()%28 +1;
    }

    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 30; y++)
        {
            if (y == foodYvalue && x == foodXvalue)
               board[x][y] = "*";


           if (board[x][y] == "O" && board[x+1][y] == "*" && movement == 's')
            {
                length++;
             foodXvalue = 0;
            foodYvalue = 0;
            }

            if (board[x][y] == "O" && board[x-1][y] == "*" && movement == 'w' )
            {
            length++;
             foodXvalue = 0;
            foodYvalue = 0;
            }

            if (board[x][y] == "O" && board[x][y+1] == "*" && movement == 'd')
            {
            length++;
             foodXvalue = 0;
            foodYvalue = 0;
            }

            if (board[x][y] == "O" && board[x][y-1] == "*" && movement == 'a')
            {
            length++;
             foodXvalue = 0;
            foodYvalue = 0;
            }
        }
}
}

void GameBoardDraw(string board[][30])
{
    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 30; y++)
        {
            if (y == 29)
                {
                cout << board[x][y] << endl;
                }

            else cout << board[x][y];
        }
    }

}



void SnakeMovement(string board[][30], int &length, int &foodXvalue, int &foodYvalue, char &movement)
{
    for (int x = 0; x < 30; x++)
    {
        for (int y = 0; y < 30; y++)
        {

            if (board[x][y] == "O")
                    {

                        movement = _getch();


                        while (movement == 'w')
                        {
                            while (kbhit() == 0)
                            {
                            clearscreen();
                            feedSnake(board, length, foodXvalue, foodYvalue, movement);

                            if (board[0][y] == "O")
                            {
                                movement = 's';
                          //      clearscreen();
                         //       cout << "GAME OVER";
                                break;

                            }
                            for (int k = 1; k < length;k++)
                            {
                                board[x-k][y] = "O";
                                board[x--][y] = " ";
                            }

                            GameBoardDraw(board);
                            }
                            break;

                        }



                        while (movement == 'a')
                        {
                            if (kbhit() == 0)
                            {clearscreen();
                            feedSnake(board, length, foodXvalue, foodYvalue, movement);

                            if (board[x][0] == "O")
                            {
                                movement = 'd';
                       //         clearscreen();
                        //        cout << "GAME OVER";
                                break;

                            }




                            for (int k = 1; k < length;k++)
                            {
                                board[x][y-k] = "O";
                                board[x][y--] = " ";
                            }


                            GameBoardDraw(board);
                            }
                            else break;
                        }

                        while (movement == 's')
                        {
                            if (kbhit() == 0)
                            {
                            clearscreen();
                            feedSnake(board, length, foodXvalue, foodYvalue, movement);

                             if (board[29][y] == "O")
                            {
                                movement = 'w';
                           //     clearscreen();
                           //     cout << "GAME OVER";
                                break;

                            }



                            for (int k = 1; k < length;k++)
                            {
                                board[x+k][y] = "O";
                                board[x++][y] = " ";
                            }

                            GameBoardDraw(board);
                            }
                            else break;
                        }

                       while (movement == 'd')
                        {
                            if (kbhit() == 0)
                            {clearscreen();
                             feedSnake(board, length, foodXvalue, foodYvalue, movement);

                             if (board[x][29] == "O")
                            {
                                movement = 'a';
                         //       clearscreen();
                         //       cout << "GAME OVER";
                                break;

                            }




                             for (int k = 1; k < length;k++)
                            {
                                board[x][y+k] = "O";
                                board[x][y++] = " ";
                            }


                            GameBoardDraw(board);
                            }
                        else break;
                        }
                    }




        }
    }
}



int main()
{
    string board[30][30];
    int length = 2;
    int foodXvalue;
    int foodYvalue;
    char movement;
    GameBoardFill(board, foodXvalue, foodYvalue);

    GameBoardDraw(board);
    while(1)
    {


        SnakeMovement(board,length, foodXvalue, foodYvalue, movement);

    }
}
