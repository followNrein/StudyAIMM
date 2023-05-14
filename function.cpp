#include <function.h>
char PG[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int Check(){
string s;
int a;
start:
cin >> s;
    if (s.find_first_not_of("012345678") != std::string::npos)
        {   system("cls");
            Draw();
            cout << "Error! Enter from 0 to 8 to make a move: " << endl;
            goto start;
        }
    else
        {
            a = stoi(s);
            if (a<0 || a>9)
            {
                system("cls");
                Draw();
                cout << "Error! Enter from 0 to 8 to make a move: " << endl;
                goto start;
            }
        }
     return a;
}

void Draw(){
    system("cls");
    cout << "Dominate Machine System (TTT)" << endl;
    cout << " ___________" << endl;
    cout << "| " << PG[0] <<  " | " << PG[1]<< " | " << PG[2]<< " | " << endl;
    cout << "|__0|__1|__2|" << endl;
    cout << "| " << PG[3] <<  " | " << PG[4]<< " | " << PG[5]<< " | " << endl;
    cout << "|__3|__4|__5|" << endl;
    cout << "| " << PG[6] <<  " | " << PG[7]<< " | " << PG[8]<< " | " << endl;
    cout << "|__6|__7|__8|" << endl;
}

int CheckAIWin(){

if ((PG[0] == 'O' && PG[1] == 'O' && PG[2] == 'O') ||
    (PG[3] == 'O' && PG[4] == 'O' && PG[5] == 'O') ||
    (PG[6] == 'O' && PG[7] == 'O' && PG[8] == 'O') ||
    (PG[0] == 'O' && PG[3] == 'O' && PG[6] == 'O') ||
    (PG[1] == 'O' && PG[4] == 'O' && PG[7] == 'O') ||
    (PG[2] == 'O' && PG[5] == 'O' && PG[8] == 'O') ||
    (PG[0] == 'O' && PG[4] == 'O' && PG[8] == 'O') ||
    (PG[2] == 'O' && PG[4] == 'O' && PG[6] == 'O'))
    return 10;
else
    return 0;
}

int CheckPlayerWin()
{
if ((PG[0] == 'X' && PG[1] == 'X' && PG[2] == 'X') ||
    (PG[3] == 'X' && PG[4] == 'X' && PG[5] == 'X') ||
    (PG[6] == 'X' && PG[7] == 'X' && PG[8] == 'X') ||
    (PG[0] == 'X' && PG[3] == 'X' && PG[6] == 'X') ||
    (PG[1] == 'X' && PG[4] == 'X' && PG[7] == 'X') ||
    (PG[2] == 'X' && PG[5] == 'X' && PG[8] == 'X') ||
    (PG[0] == 'X' && PG[4] == 'X' && PG[8] == 'X') ||
    (PG[2] == 'X' && PG[4] == 'X' && PG[6] == 'X'))
    return -10;
else
    return 0;
}

bool FullField(){
    for (int i=0; i < 9; i++)
        {
            if(PG[i] == ' ')
            return false;
        }
    return true;
}

int Minimax(bool CurrentPlayer){
    if(CheckAIWin() == 10)
        return 10;

    if (CheckPlayerWin() == -10)
        return -10;

    if (FullField())
        return 0;

    if (!CurrentPlayer)
        {
            int WinScore = -15;
            for (int i=0; i<9; i++)
                {
                    if (PG[i] == ' ')
                        {
                            PG[i] = 'O';
                            int Score = Minimax(!CurrentPlayer);
                            PG[i] = ' ';
                            if (Score > WinScore)
                                WinScore = Score;
                        }
                }
            return WinScore;
        }
     else
        {
            int WinScore = 15;
            for (int i=0; i<9; i++)
                {
                    if (PG[i] == ' ')
                        {
                            PG[i] = 'X';
                            int Score = Minimax(!CurrentPlayer);
                            PG[i] = ' ';
                            if (Score < WinScore)
                             WinScore = Score;
                        }
                }
     return WinScore;
        }
}

int Game(){
    system("cls");
    int i;
    bool Player;
    bool gameover = false;
    for (i = 0; i <9; i++)
        {
            PG[i] = ' ';
        }
    while(!gameover)
        {
            int AIPGIndex = 9;
            int Score = -1;
            Player = true;
            Draw();
            repeat:
            cout << "Enter from 0 to 8 to make a move: ";
            i =  Check();
            if(PG[i] != 'X' && PG[i] != 'O')
                {
                    system("cls");
                    PG[i] = 'X';
                    Draw();
                }
            else
                {
                    system("cls");
                    Draw();
                    cout << "There is X or O in the field! Try again!!!" << endl;
                    goto repeat;
                }

            if (CheckPlayerWin() == -10)
                {
                    cout << "HUMAN WIN!!!" << endl;
                    system ("pause");
                    gameover = true;

                }

            for (int i=0; i<9; i++)
                {
                    if (PG[i] == ' ')
                    {
                        Player = false;
                        PG[i] = 'O';
                        int AIScore = Minimax(!Player);
                        PG[i] = ' ';
                        if (AIScore > Score)
                        {
                            AIPGIndex = i;
                            Score = AIScore;
                        }
                    }
                }
            if (FullField() == true)
                {
                    cout << "DRAW!!!" << endl;
                    return 0;
                }
            else
                PG[AIPGIndex] = 'O';

            if (CheckAIWin() == 10)
                {
                    gameover = true;
                    Draw();
                }


        }
        Draw();
        if (CheckAIWin() == 10)
           {
               cout << "AI WIN!!!" << endl;
               gameover = true;
           }
        return 0;
}


