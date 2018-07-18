#include <iostream>

using namespace std;

class Board{
    char positions[16];
    char win;
public:
    Board(){
        win = 'z';
        int i;
        for(i=0;i<16;i++)
            positions[i] = '_';
    }

    void printwhere(){
        int i;
        cout << "\n\ttype the written numbers to play on that position\n\n";
        for(i=0;i<16;i++)
        {
            if(i<10)
            cout <<"| "<< i <<"  |" ;
            else
            cout <<"| "<< i <<" |" ;

            if(i%4==3)
                cout << endl;
        }
    }

    void printBoard(){
        int i;
        cout << endl;
        for(i=0;i<16;i++)
        {
            cout << "|" << positions[i] ;
            if(i%4==3)
                cout << "|\n";
        }
    }

    void printuserprompt(string &s,char c){
        int i;
        while(1)
        {
        cout << "\n\t" << s << " choose no. from 0 to 15\n";
        cin >> i;
        if(i>15 || i<0 || !cin)
            cout << "\n\tWrong input ";
        else if(positions[i] =='_' )
            {
                positions[i] = c;
                break;
            }
        else
            cout << "\n\tWrong input ";

        }
    }

    char checkrows(char x){
        int i,j,p=0;
        for(i=0;i<16;i=i+4)
        {
            p=0;
            for(j=0;j<4;j++)
            {
                if(positions[i+j]==x)
                {
                    p++;
                }
            }
            if(p==4)
            return x;

        }
        return 'z';
    }

    char checkcolumn(char x){
        int i,j,p=0;
        for(i=0;i<4;i++)
        {
            p=0;
            for(j=0;j<16;j=j+4)
            {
                if(positions[i+j]==x)
                p++;
            }
            if(p==4)
            return x;
        }
        return 'z';
    }

    char checkdiagonal(char x){
        int i,j,p=0;
        for(i=0;i<16;i=i+5){
            if(positions[i]==x)
            {
                p++;
                //cout << p;
            }
        }
        if(p==4)
        return x;
        else{
            p=0;
            for(i=3;i<13;i=i+3){
                if(positions[i]==x)
                {
                    p++;
                    //cout << p;
                }
            }
        if(p==4)
            return x;
        }
        return 'z';

    }

    bool gamewinner(char x){
        win = checkrows(x);
        if(win=='z')
            win = checkcolumn(x);
        if(win =='z')
            win = checkdiagonal(x);

        if(win=='z')
        return 0;
        else
        return 1;
    }


};

