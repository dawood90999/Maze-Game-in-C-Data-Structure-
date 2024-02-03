// DAWOOD HUSSAIN (22i-2410) IBRAHIM KAYANI (22i-2686) SECTION E
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<conio.h>
#include<windows.h>
using namespace std;
#include"Asset.h"
int main() 
{
    START:
    int HEALTH, SHEILD = 0;
    char ch;
    string playername = PrintBoard();
    cout << endl;
    int SCORE = 0;
    while (1) {
        ch = _getch();
        if (ch == 's' || ch == 'S') 
        {
        MANUALMODE:
            system("cls");
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "\t\t\t\t\t\t|       EASY [E]     |" << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "\t\t\t\t\t\t|       NOMAD [N]    |" << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "\t\t\t\t\t\t|       HARD [H]     |" << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            ch = _getch();
            int n;
            if (ch == 'e' || ch == 'E')
            {
                n = 26;
                HEALTH = 5;
            }else
            if (ch == 'n' || ch == 'N')
            {
                n = 35;
                HEALTH = 3;
            }
            else if(ch=='H' || ch == 'h')
            {
                n = 40;
                HEALTH = 1;
            }
            else 
            {
                n = 20;
                HEALTH = 5;
            }
            MAze Game(n);
            Graph Path(&Game);
            char command;
            cout << " FORWARD : W" << endl;
            cout << " BACK : S" << endl;
            cout << " LEFT TURN : A" << endl;
            cout << " RIGHT TURN : D" << endl;
            cout << " WALL : |" << endl;
            cout << " COIN (+10): o" << endl;
            cout << " CROSSING : +" << endl;
            cout << " OBSTACLE (-5) : #" << endl;
            cout << " WALLBREAKER: ~" << endl;
            cout << " MULTIPLIER(x2): *" << endl;
            int STEP = 0;
            do
             {
                ShiftORANGE();
                cout << "PAUSE[P]  SCORE = "<<SCORE<< "\t\t";
                cout << "STEPS = " << STEP <<"\t\t";
                ShiftRED();
                cout << "HEALTH : " ;
                for (int a=0;a<HEALTH;a++) 
                {
                    cout << "* ";
                }
                cout << "\t\t";
                ShiftCYAN();
                cout << "SHEILD : " ;
                
                for (int a = 0; a < SHEILD; a++)
                {
                    cout << "`";
                }
                cout << "\t\t";
                ShiftYELLOW();
                cout << "COLLECTABLES : ";
                Game.COINS->Print();
                cout << endl;
                if (HEALTH == 0) 
                {
                    goto EXIT;
                }
                Game.PrintMaze();
                command= _getch();
              
               if (command=='P' || command == 'p')
               {
                   system("cls");
                   ShiftORANGE();
                   PAUSEMENU:
                   cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                   cout << "\t\t\t\t\t\t|       RESUME [R]   |" << endl;
                   cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                   cout << endl;
                   cout << "\t\t\t\t\t\t -*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                   cout << "\t\t\t\t\t\t|   CHANGE DIFFICULTY [C]  |" << endl;
                   cout << "\t\t\t\t\t\t -*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
                   cout << endl;
                   cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                   cout << "\t\t\t\t\t\t|       EXIT [E]     |" << endl;
                   cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                   cout << endl;
                   command = _getch();
                   if (command=='R' || command == 'r')
                   {
                       goto RESUME;
                   }
                   if (command == 'C' || command == 'c')
                   {
                       goto MANUALMODE;
                   }
                   if (command == 'E' || command == 'e')
                   {
                       Game.CLeanMaze();
                       Game.StoreMaze(HEALTH,SHEILD, Game.COINS->GETSIZE(),SCORE);
                       exit(0);
                   }
                   else 
                   {
                       goto PAUSEMENU;
                   }
               }
              
           RESUME:
               STEP++;
               bool a = Game.Animate(command,SCORE,HEALTH,SHEILD);
                if (a == true) 
                {
                    ShiftCYAN();
                    cout << endl;
                    ofstream file("leaderboard.csv", ios::app);

                    file << playername << "," << SCORE << "," << "WON" << "," << Game.COINS->GETSIZE() << endl;
                    file.close();
                    cout << "\t\t\t-----------------------------------------------------------------" << endl;
                    cout << "\t\t\t|                                                               |" << endl;
                    cout << "\t\t\t|                         WE HAVE A WINNER!                     |" << endl;
                    cout << "\t\t\t|                                                               |" << endl;
                    cout << "\t\t\t-----------------------------------------------------------------" << endl;
                    exit(0);
                }
                
                system("cls");
            }
            while (Game.Player->symbol != 'F' && SCORE>=0);
        EXIT:

            ShiftCYAN();
            SCORE = 0;
            ofstream file("leaderboard.csv", ios::app);
            file << playername << "," << SCORE << "," << "LOST" << "," << Game.COINS->GETSIZE() << endl;
            file.close();
            cout << "\t\t\t-----------------------------------------------------------------" << endl;
            cout << "\t\t\t|                                                               |" << endl;
            cout << "\t\t\t|                 !         YOU LOSE        !                   |" << endl;
            cout << "\t\t\t|                                                               |" << endl;
            cout << "\t\t\t-----------------------------------------------------------------" << endl;
        }
        if (ch == 'M' || ch == 'm') 
        {
            system("cls");
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "\t\t\t\t\t\t|      MANUAL [M]   |" << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << "\t\t\t\t\t\t|     AUTOMATIC [A] |" << endl;
            cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
            cout << endl;
            ch = _getch();
            if (ch == 'M' || ch == 'm')
            {
                goto MANUALMODE;
            }
            else
            if (ch == 'A' || ch == 'a')
            {
                system("cls");
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                cout << "\t\t\t\t\t\t|       EASY [E]     |" << endl;
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                cout << endl;
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                cout << "\t\t\t\t\t\t|       NOMAD [N]    |" << endl;
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                cout << endl;
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                cout << "\t\t\t\t\t\t|       HARD [H]     |" << endl;
                cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                ch = _getch();
                
                    int n;
                    if (ch == 'e' || ch == 'E')
                    {
                        n = 26;
                    }
                    else
                        if (ch == 'n' || ch == 'N')
                        {
                            n = 35;
                        }
                        else if (ch == 'H' || ch == 'h')
                        {
                            n = 40;
                        }
                        else
                        {
                            n = 20;
                        }
                    MAze Game(n);
                    Graph Path(&Game);
                    cout << " FORWARD : W" << endl;
                    cout << " BACK : S" << endl;
                    cout << " LEFT TURN : A" << endl;
                    cout << " RIGHT TURN : D" << endl;
                    cout << " WALL : |" << endl;
                    cout << " COIN (+10): o" << endl;
                    cout << " CROSSING : +" << endl;
                    cout << " OBSTACLE (-5) : #" << endl;
                    cout << " WALLBREAKER: ~" << endl;
                    cout << " MULTIPLIER(x2): *" << endl;
                    Game.PrintMaze();
                    Path.MoveCarAlongShortestPath(Game.GetAxis(n), SCORE, SHEILD);
            }
            else 
            {
                PrintBoard();
                continue;
            }
        }
        if (ch=='L' || ch=='l')
        {
            SCORETREE SCOREBOARD;
            ifstream file("leaderboard.csv");
            if (!file.is_open()) {
               cout<< "Error opening file!" << std::endl;
                return 1;
            }
             cout << "\t\t\t-*-*-*-*-*-*-*-*-*-*- LEADERBOARD -*-*-*-*-*-*-*-*-*-" << std::endl;
            string line;
            getline(file, line);
            cout << endl;
            cout << "\t" << "NAME\t\t\t\tSCORE\t\t\t RESULT\t\t\tCOINS\t\t POSITION"<<endl;
            
            int serialNumber = 1;  
            bool flag = false;
            while (getline(file, line)) {
                
                stringstream ss(line);
                string cell;
                string name, score, stat, coins;
                while (getline(ss, cell, ',')) 
                {
                    name = cell;
                    getline(ss, cell, ',');
                    score = cell;
                    getline(ss, cell, ',');
                    stat = cell;
                    getline(ss, cell, ',');
                    coins = cell;
                }
                SCOREBOARD.insert(name, score, coins, stat);
            }
            SCOREBOARD.inorder();
            file.close();

        }
        if (ch == 'e' || ch == 'E')
        {
            exit(0);
        }
        if (ch == 'R' || ch == 'r') 
        {
            ifstream file("Maze.txt");
            string key;
            getline(file, key);
            char c = key[0];
            if (c == '-') 
            {
                cout << "NO GAME RECORD FOUND" << endl;
                goto START;
            }
            int vertice = stoi(key);
            MAze Game(vertice);
            getline(file, key);
            HEALTH = stoi(key);
            getline(file, key);
            SHEILD = stoi(key);
            getline(file, key);
            int coins= stoi(key);
            for (int i=0;i<coins;i++) 
            {
                Game.COINS->Insert('o');
            }
            getline(file, key);
            SCORE = stoi(key);
            
            file.close();
            Game.UpdateMaze();
            Graph Path(&Game);
            char command;
            cout << " FORWARD : W" << endl;
            cout << " BACK : S" << endl;
            cout << " LEFT TURN : A" << endl;
            cout << " RIGHT TURN : D" << endl;
            cout << " WALL : |" << endl;
            cout << " COIN (+10): o" << endl;
            cout << " CROSSING : +" << endl;
            cout << " OBSTACLE (-5) : #" << endl;
            cout << " WALLBREAKER: ~" << endl;
            cout << " MULTIPLIER(x2): *" << endl;
            int STEP = 0;
            do
            {
                ShiftORANGE();
                cout << "PAUSE[P]  SCORE = " << SCORE << "\t\t";
                cout << "STEPS = " << STEP << "\t\t";
                ShiftRED();
                cout << "HEALTH : ";
                for (int a = 0; a < HEALTH; a++)
                {
                    cout << "* ";
                }
                cout << "\t\t";
                ShiftCYAN();
                cout << "SHEILD : ";

                for (int a = 0; a < SHEILD; a++)
                {
                    cout << "`";
                }
                cout << "\t\t";
                ShiftYELLOW();
                cout << "COLLECTABLES : ";
                Game.COINS->Print();
                cout << endl;
                if (HEALTH == 0)
                {
                    goto EXIT1;
                }
                Game.PrintMaze();
                command = _getch();

                if (command == 'P' || command == 'p')
                {
                    system("cls");
                    ShiftORANGE();
                PAUSEMENU1:
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << "\t\t\t\t\t\t|       RESUME [R]   |" << endl;
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << "\t\t\t\t\t\t|  CHANGE DIFFICULTY [C] |" << endl;
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << "\t\t\t\t\t\t|       EXIT [E]     |" << endl;
                    cout << "\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-" << endl;
                    cout << endl;
                    command = _getch();
                    if (command == 'R' || command == 'r')
                    {
                        goto RESUME1;
                    }
                    if (command == 'C' || command == 'c')
                    {
                        goto MANUALMODE;
                    }
                    if (command == 'E' || command == 'e')
                    {

                        Game.StoreMaze(HEALTH, SHEILD, Game.COINS->GETSIZE(), SCORE);
                        exit(0);
                    }
                    else
                    {
                        goto PAUSEMENU1;
                    }
                }

            RESUME1:
                STEP++;
                bool a = Game.Animate(command, SCORE, HEALTH, SHEILD);
                if (a == true)
                {
                    ShiftCYAN();
                    cout << endl;
                    ofstream file("leaderboard.csv", ios::app);

                    file << playername << "," << SCORE << "," << "WON" << "," << Game.COINS->GETSIZE() << endl;
                    file.close();
                    cout << "\t\t\t-----------------------------------------------------------------" << endl;
                    cout << "\t\t\t|                                                               |" << endl;
                    cout << "\t\t\t|                         WE HAVE A WINNER!                     |" << endl;
                    cout << "\t\t\t|                                                               |" << endl;
                    cout << "\t\t\t-----------------------------------------------------------------" << endl;
                    exit(0);
                }

                system("cls");
            } while (Game.Player->symbol != 'F' && SCORE >= 0);
        EXIT1:

            ShiftCYAN();
            SCORE = 0;
            ofstream file1("leaderboard.csv", ios::app);
            file1 << playername << "," << SCORE << "," << "LOST" << "," << Game.COINS->GETSIZE() << endl;
            file1.close();
            cout << "\t\t\t-----------------------------------------------------------------" << endl;
            cout << "\t\t\t|                                                               |" << endl;
            cout << "\t\t\t|                 !         YOU LOSE        !                   |" << endl;
            cout << "\t\t\t|                                                               |" << endl;
            cout << "\t\t\t-----------------------------------------------------------------" << endl;
        }
        }
    }
