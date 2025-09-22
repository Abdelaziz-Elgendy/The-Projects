#include<bits/stdc++.h>
using namespace std;
//paper scissors rock
char computerMove()
{
    char c[]= {'p','s','r'};
    srand(time(NULL));
    int mv=rand()%3;
    return c[mv];
}

int check_winner(char player, char computer)  //0:draw,  1:player, -1:computer
{
    if(player=='p' && computer=='r')
        return 1;
    if(player=='s' && computer=='p')
        return 1;
    if(player=='r' && computer=='s')
        return 1;
    if(player==computer)
        return 0;
    return -1;
}

void paper_scissors_rock_game()
{
    cout<<"------paper scissors rock Game---------\n";
    cout<<"Enter r(rock), p(paper), s(scissors)\n\n";
    int round;
    cout<<"Enter the number of rounds you want: \n";
    cin>>round;
    for(int i=0; i<round; i++)
    {
        cout<<"round :"<<(i+1)<<"\n--------\n";
        char playerMove, comMove;
        cout<<"Enter your move: \n";
        do
        {
            cin>>playerMove;
            if(playerMove!='p' && playerMove!='s' && playerMove!='r')
                cout<<"Invalid move, try again.\n";
        }
        while(playerMove!='p' && playerMove!='s' && playerMove!='r');
        comMove=computerMove();
        //user:1     computer:-1     draw:0
        cout<<"Your move: "<<playerMove<<" - computer move: "<<comMove<<'\n';

        if(check_winner(playerMove, comMove)==1)
            cout<<"Player win\n";
        else if(check_winner(playerMove, comMove)==-1)
            cout<<"computer win\n";
        else
            cout<<"draw\n";
        cout<<"---------------------------------\n";
    }
}
int main()
{
    paper_scissors_rock_game();
    return 0;
}
