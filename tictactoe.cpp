#include <iostream>
#include<stdlib.h>
using namespace std;
void printarray(char A[3][3])
{
    int i,j;
     for(i=0;i<3;i++)
    {
        cout<<"\t\t\t\t\t\t| ";
        for(j=0;j<3;j++)
        {
            cout<< A[i][j]<<" | ";
        }
        cout<<endl;
    }

}
int checkfull(char A[3][3])
{
    int i,j,c,cx,cy;
    char ch;

     for(i=0;i<3;i++)
    {
                ch=A[i][0];
                c=0;
                 for(j=0;j<3;j++)
                 {
                  if(A[i][j]!=ch)
                  c=1;
                 }
        if(c!=1)
        {
            if(ch=='X')
                return 2;
            else if(ch=='O')
                return 3;
        }

  }
     for(i=0;i<3;i++)
    {
        ch=A[0][i];
            c=0;
            for(j=0;j<3;j++)
        {
            if(A[j][i]!=ch)
            c=1;
        }
        if(c!=1)
        {
            if(ch=='X')
                return 2;
            else if(ch=='O')
                return 3;
        }

    }

    ch=A[0][0];
    cx=0;
    cy=0;
    for(i=0;i<3;i++)
    {
    if(A[i][i]!='X')
    cx=1;
    if(A[i][i]!='O')
    cy=1;
    }
    if(cx==0)
        return 2;
    else if(cy==0)
        return 3;
    cx=0;
    cy=0;
     for(i=0;i<3;i++)
    {
    if(A[i][2-i]!='X')
    cx=1;
    if(A[i][2-i]!='O')
    cy=1;
    }
    if(cx==0)
        return 2;
    else if(cy==0)
        return 3;

             for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(A[i][j]=='.')
                return 1;
        }
    }


    return 4;
}
int main()
{
    system("Color B0");

    string X;
    string O;
    string N;
    string y="Y";
    string n="N";
    string p;

        int i,j,b,c,f,e;
        int cf=1;

    char A[3][3];
    for( i=0;i<3;i++)
    {
        for( j=0;j<3;j++)
        {
            A[i][j]='.';
        }
    }
    flag1:
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "\t\t\t\t\t###################  TIC TAC TOE #####################"<< endl;
    flag:
    cout<<endl;
    cout<<endl;
    cout << "* Enter name of X player: ";
    cin>>X;
    cout << "* Enter name of O player: ";
    cin>>O;
    if(X==O)
    {
        cout<<"*****Enter different names******";
        goto flag;
    }
    cout<<"* Who will play first "<<X<<" or "<<O<<" ? ";
    cin>>N;
    cout<<endl;
    if(N==X)
        b=0;
    else if(N==O)
        b=1;
    else
    {
        cout<<"******************************Invalid name...Please enter the names again**********************************"<<endl;
        goto flag;
    }
    cout<<"* First row and column is 0(zero)"<<endl;
    cout<<"* Last row and column is 2(two)"<<endl;
    while(checkfull(A)==1)
    {
           printarray(A);
           cout<<endl;
        if(b==0)
        {
             cout<<X <<"  will play now"<<endl;
             e1:
             cout<<"->Enter row: ";
             cin>>e;
             if(e<0||e>2)
            {
                cout<<e<<" is not a valid row"<<endl;
                goto e1;
            }
            f1:
            cout<<"->Enter column: ";
            cin>>f;
            if(f<0||f>2)
            {
                cout<<f<<" is not a valid column"<<endl;
                goto f1;
            }
            if(A[e][f]!='.')
            {
            cout<<"**************** Invalid row or column ***********************"<<endl;
            continue;
            }
            A[e][f]='X';
        }

        else
        {
            cout<<O<<"  will play now"<<endl;
            cout<<"->Enter row: ";
            e2:
            cin>>e;
            if(e<0||e>2)
            {
                cout<<e<<" is not a valid row"<<endl;
                goto e2;
            }
            f2:
            cout<<"->Enter column: ";
            cin>>f;
            if(f<0||f>2)
            {
                cout<<f<<" is not a valid column"<<endl;
                goto f2;
            }
            if(A[e][f]!='.')
            {
                cout<<"**************** Invalid row or column ***********************"<<endl;
                continue;
            }
            A[e][f]='O';
        }
            if(b==0)
                b=1;
            else
                b=0;
    }
    printarray(A);
    cout<<endl;
    if(checkfull(A)==2)
    {
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<<"********************CONGRATULATIONS "<<X<<"  WON******************************"<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
    }
    if(checkfull(A)==3)
    {
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<<"********************CONGRATULATIONS "<<O<<"  WON******************************"<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
    }
    if(checkfull(A)==4)
    {
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<<"************************It is a tie***********************************"<<endl;
        cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl<<endl;
    }
    s:
    cout<<"Would you like to play again? (Y/N) ";
    cin>>p;
    cout<<endl;
    if(p==y)
    {
        goto flag1;
    }
    else if(p==n)
    {
        cout<<"Bye";
        cout<<endl;
        exit(0);
    }
    else
    {
        cout<<p<<" is not a valid option "<<endl;
        goto s;
    }

return 0;
}
