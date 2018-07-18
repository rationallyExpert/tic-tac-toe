#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "gameClass.hpp"

using namespace std;

int main()
{
    Board game;
    string x,o;
    int turns=0;
    char c;
    bool who;

    cout << "\n\tlets start the game\n";
    cout << "\n\tname of the player choosing x ";
    getline(cin,x);
    cout << "\n\tname of the player choosing o ";
    getline(cin,o);
    cout << "\n\t" << x << " VS " << o << "\n\tlets GO!\n";
    cout << "\n\tBoard will look like this";
    game.printBoard();

    while(turns<8)
    {
        game.printwhere();
        cout << "\n\tplease ENTER";
        getchar();
        game.printuserprompt(x,'x');
        game.printuserprompt(o,'o');
        game.printBoard();

        who = game.gamewinner('x');

        if(who)
        {
            cout << "\n\tWinner is " << x << endl;
            game.printBoard();
            break;
        }
        who = game.gamewinner('o');

        if(who)
        {
            cout << "\n\tWinner is " << x << endl;
            game.printBoard();
            break;
        }



        turns++;
    }


    if(turns>=8)
        cout << "\n\t****game tie****";

    getchar();
    return 0;
}
