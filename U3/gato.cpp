#include <iostream>
#include <stdalign.h>
#include <time.h>
using namespace std;

void makeBoard();
int selectMove();
bool checkMove(int, string);
void putMove(int, string, string);
bool win(string);
int getMovePC();
void cloneMatrix();
int getBetterMovefrom(string);

char structure[6][11];
char gameArea[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char gameAreaPC[3][3];
int playerTurn = 1;
int row, col;
const string PC = "Machine";
const string HUMAN = "Human";
const string BOARD = "Real";
const string IMAGINARYBOARD = "Imaginary";

int main()
{
    bool gameover = false;
    int move;
    bool placeOccupied = true;
    int mode;
    cout << "Welcome to the Tic tac toe game <3 \n";
    cout << "Which game mode you want to play (choose between number 1 and 2) \n";
    cout << "1 - play with single mode \n";
    cout << "2 - play with multiplayer mode \n";
    cin >> mode;
    if (mode == 1)
    {
        do
        {
            system("clear");
            if (playerTurn % 2 == !0)
            {
                do
                {
                    makeBoard();
                    move = selectMove();
                    placeOccupied = checkMove(move, BOARD);
                    if (placeOccupied == true)
                    {
                        system("clear");
                        cout << "try again \n";
                    }
                } while (placeOccupied == true);
                putMove(move, BOARD, HUMAN);
                gameover = win(BOARD);
            }
            else
            {
                makeBoard();
                move = getMovePC();
                putMove(move, BOARD, PC);
                gameover = win(BOARD);
            }
        } while (gameover == false and playerTurn < 10);
        system("clear");
        makeBoard();
    }
    else if (mode == 2)
    {
        do
        {
            system("clear");
            do
            {
                makeBoard();
                move = selectMove();
                placeOccupied = checkMove(move, BOARD);
                if (placeOccupied == true)
                {
                    system("clear");
                    cout << "Just give it another try \n";
                }
            } while (placeOccupied == true);
            putMove(move, BOARD, HUMAN);
            gameover = win(BOARD);
        } while (gameover == false and playerTurn < 10);
        system("clear");
        makeBoard();
    }
    else
    {
        cout << "Gamer over";
    }

    if (gameover == true)
    {
        if (playerTurn % 2 == 0)
        {
            cout << "Player 1 is the winner" << endl;
        }
        else
        {
            if (mode == 1)
            {
                cout << "The winner is the pc";
            }
            else
            {
                cout << "Player 2 is the winner" << endl;
            }
        }
    }
    else if (gameover == false and playerTurn >= 9)
    {
        cout << "Tie" << endl;
    }
    return 0;
}

void makeBoard()
{
    row = 0;
    col = 0;
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (col1 == 3 || col1 == 7)
            {
                structure[row1][col1] = '|';
            }
            else if (row1 == 1 || row1 == 3)
            {
                structure[row1][col1] = '_';
            }
            else if (row1 != 5 && (col1 == 1 || col1 == 5 || col1 == 9))
            {
                structure[row1][col1] = gameArea[row][col];
                col++;
                if (col == 3)
                {
                    col = 0;
                    row++;
                }
            }
            else
            {
                structure[row1][col1] = ' ';
            }
        }
    }
    for (int row1 = 0; row1 < 6; row1++)
    {
        for (int col1 = 0; col1 < 11; col1++)
        {
            if (structure[row1][col1] == 'X')
            {
                cout << "\033[0;35m" << structure[row1][col1] << "\033[0m";
            }
            else if (structure[row1][col1] == 'O')
            {
                cout << "\033[0;31m" << structure[row1][col1] << "\033[0m";
            }
            else
            {
                cout << structure[row1][col1];
            }
        }
        cout << endl;
    }
}

int selectMove()
{
    int jugada1;
    do
    {
        cout << "Insert the number : ";
        cin >> jugada1;
    } while (jugada1 > 9 && jugada1 < 0);
    return jugada1;
}

bool checkMove(int move, string board)
{
    bool placeOccupied = false;
    int fila = 0, columna = 0;
    if (move >9 || move <=0 and board == BOARD)
    {
        return true;
    }
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (move == numjuada)
        {
            row = fila;
            col = columna;
            break;
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (board == BOARD)
    {
        if (gameArea[row][col] == 'O' || gameArea[row][col] == 'X')
        {
            placeOccupied = true;
        }
    }
    else if (board == IMAGINARYBOARD)
    {
        if (gameAreaPC[row][col] == 'O' || gameAreaPC[row][col] == 'X')
        {
            placeOccupied = true;
        }
    }
    return placeOccupied;
}

void putMove(int move, string board, string Jugador)
{
    char valorJugada;
    if (playerTurn % 2 == 0)
    {
        valorJugada = 'X';
    }
    else
    {
        valorJugada = 'O';
    }
    int fila = 0, columna = 0;
    for (int numjuada = 1; numjuada < 10; numjuada++)
    {
        if (move == numjuada)
        {
            if (board == BOARD)
            {
                gameArea[fila][columna] = valorJugada;
                break;
            }
            else if (board == IMAGINARYBOARD)
            {
                if (Jugador == HUMAN)
                {
                    valorJugada = 'O';
                }
                else if (Jugador == PC)
                {
                    valorJugada = 'X';
                }
                gameAreaPC[fila][columna] = valorJugada;
                break;
            }
        }
        else
        {
            columna++;
            if (columna == 3)
            {
                columna = 0;
                fila++;
            }
        }
    }
    if (board == BOARD){
        playerTurn++;
    }
}

bool win(string board)
{
    bool win = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if (board == BOARD)
        {
            if (gameArea[posicion][0] == gameArea[posicion][1] && gameArea[posicion][posicion] == gameArea[posicion][2] && gameArea[posicion][1] == gameArea[posicion][2])
            {
                win = true;
                break;
            }
            if (gameArea[0][posicion] == gameArea[1][posicion] && gameArea[0][posicion] == gameArea[2][posicion] && gameArea[1][posicion] == gameArea[2][posicion])
            {
                win = true;
                break;
            }
        }
        else if (board == IMAGINARYBOARD)
        {
            if (gameAreaPC[posicion][0] == gameAreaPC[posicion][1] && gameAreaPC[posicion][posicion] == gameAreaPC[posicion][2] && gameAreaPC[posicion][1] == gameAreaPC[posicion][2])
            {
                win = true;
                break;
            }
            if (gameAreaPC[0][posicion] == gameAreaPC[1][posicion] && gameAreaPC[0][posicion] == gameAreaPC[2][posicion] && gameAreaPC[1][posicion] == gameAreaPC[2][posicion])
            {
                win = true;
                break;
            }
        }
    }
    if (board == BOARD)
    {
        if (gameArea[0][0] == gameArea[1][1] && gameArea[0][0] == gameArea[2][2] && gameArea[1][1] == gameArea[2][2]) 
        {
            win = true;
        }
        else if (gameArea[2][0] == gameArea[1][1] && gameArea[2][0] == gameArea[0][2] && gameArea[0][2] == gameArea[1][1])
        {
            win = true;
        }
    } 
    else if (board == IMAGINARYBOARD)
    {
        if (gameAreaPC[0][0] == gameAreaPC[1][1] && gameAreaPC[0][0] == gameAreaPC[2][2] && gameAreaPC[1][1] == gameAreaPC[2][2])
        {
            win = true;
        }
        else if (gameAreaPC[2][0] == gameAreaPC[1][1] && gameAreaPC[2][0] == gameAreaPC[0][2] && gameAreaPC[0][2] == gameAreaPC[1][1])
        {
            win = true;
        }
    }
    return win;
}

int getMovePC()
{
    bool placeOccupied = false;
    int move;
    srand(time(NULL));
    move = getBetterMovefrom(PC);
    if (move != -1)
    {
        return move;
    }
    move = getBetterMovefrom(HUMAN);
    if (move != -1)
    {
        return move;
    }
    do
    {
        move= 1 + rand() % 9;
        placeOccupied= checkMove (move,BOARD);
    }while (placeOccupied == true);
    return move;
}

void cloneMatrix(){
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            gameAreaPC[fila][columna] = gameArea[fila][columna];
        }
    }
}

int getBetterMovefrom(string player)
{
    bool placeOccupied = false;
    bool gameover = false;
    int move = 0;
    cloneMatrix();
    if (player == PC)
    {
        do
        {
            move++;
            placeOccupied=checkMove(move, IMAGINARYBOARD);
            if (placeOccupied == false){
                putMove(move, IMAGINARYBOARD, PC);
                gameover = win(IMAGINARYBOARD);
            }
            cloneMatrix();
        } while (move <= 9 && gameover == false);
    } 
    else if (player == HUMAN)
    {
        do
        {
            move++;
            placeOccupied=checkMove(move, IMAGINARYBOARD);
            if (placeOccupied== false){
                putMove(move, IMAGINARYBOARD, HUMAN);
                gameover = win(IMAGINARYBOARD);
            }
            cloneMatrix();
        } while (move <= 9 && gameover == false);
    }
    if (move >= 10){
        move= -1;
    }
    return move;
}