#include <function.h>

int main()
{
    int Choice;
    TryAgain:
    Game();
    cout << "Do you want to play again?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> Choice;
    switch(Choice){
    case 1:
        goto TryAgain;
    case 2:
        system("cls");
        break;
    }
}
