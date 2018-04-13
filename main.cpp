#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector <int> >);// creating a new funtion called Scoreboard
int randomBetween( int,int);

int main()
{ srand((int) time(0));
  int periods;
  int teams;

vector< vector<int> >scoreBoard;

  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
       scoreBoard.resize(teams);//make scoreboard and fill it with zeros
       for(int row=0; row<teams; row++)
       {
            scoreBoard[row].resize(periods);// going throuhg every row and resizing it to period/col
            for(int col=0; col<periods; col++)
            {
                scoreBoard[row][col]=0;
            }
       }
       printScoreboard(scoreBoard);

       for(int row=0; row<scoreBoard.size(); row++)
       {
        for(int col=0; col<scoreBoard[row].size(); col++)
       {
            scoreBoard[row][col]= randomBetween(5,5);
       }
       
       }
       printScoreboard(scoreBoard);

 /*    cout<<"SCOREBOARD"<<endl;
     for(int row=0; row<teams; row++)
       {
        cout<< "Player "<< row+1<<": ";
        for(int col=0; col<periods; col++)
        cout<< scoreBoard[row][col]<< "|";
        cout<<endl;
       }
  
*///once created, display the scoreboard
  }
  return 0;
}

  void printScoreboard(vector< vector<int> > scoreBoard)

{        cout<<"SCOREBOARD"<<endl;

     for(int row=0; row<scoreBoard.size(); row++)
       {
        cout<< "Player "<< row+1<<": ";
        for(int col=0; col<scoreBoard[row].size(); col++)
       {
            cout<< scoreBoard[row][col]<< "|";
       }
       cout<<endl;
       }
   
}
int randomBetween(int first,int second)
{
    if(first>second)
    {
        return second + rand()%(first-second+1);
    }
    else if(second>first) 
    {
        return first + rand()%(second-first+1);
    }    
}
