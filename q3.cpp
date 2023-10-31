#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Player class declarations
class Player
{
 private:
   string name;
   int score;
 public:
   Player(int newScore, string newName);
   Player();

   void setName(string newName){name = newName;};
   void setScore(int newScore){score = newScore;};
   
   string getName() {return name;};
   int getScore() {return score;};
};

int addPlayers(vector<Player>& team);
void findScores(vector<Player>& team, int count);
void showScores(vector<Player>& team, int count);
int removePlayers(vector<Player>& team, int count);

int main(){
  int choice=0;
  int count=0;

  vector<Player> team;

  while (choice!=5){
    cout << "\nWould you like to: \nAdd Players(1) \nFind scores(2) \nShow all scores(3) \nRemove players(4)\nQuit(5)\n\n>>";
    cin >> choice; 
    
    switch (choice){
      case 1:
        count += addPlayers(team);
        break;
      case 2:
        findScores(team,count);
        break;
      case 3:
        showScores(team,count);
        break;
      case 4:
        count -= removePlayers(team,count);
        break;
      case 5:
        break;
      default:
        cout << "\nPlease choose one of the following choices:\n";
        break;
    }
  }

}

Player::Player()
  : name("test"),score(0)
  {}

Player::Player(int newScore, string newName)
  : name(newName),score(newScore)
  {}

int addPlayers(vector<Player>& team){
  char response='y';
  int count=0;
  string newName;
  int newScore;

  while ((response=='y')&&(count<10)){
    cout << "\nWhat is the player's name?\n:";
    cin >> newName;
    cout << "\nWhat is the player's score?\n:";
    cin >> newScore;
    
    Player player(newScore,newName);
    
    team.push_back(player);
    count ++;
    cout << "\nWould you like to add a new player? (y/n)";
    cin >> response;
    while ((response!='y')&&(response!='n')){
      cout << "\nPlease respond with y or n\n:";
      cin >> response;
    }
  }
  return count;
}

void findScores(vector<Player>& team, int count){
  string name;
  cout << "\nEnter the name of the player you are looking for\n>>>";
  cin >> name;

  for (int i=0;i<count;i++){
    if (team[i].getName()==name){
      cout << "\nName"<<"\t"<<"Score\n";
      cout << name << "\t" << team[i].getScore() << "\n\n";
      return;
    }
  }
  
  cout << "\nThat player is not found\n\n";
  return;
}

void showScores(vector<Player>& team, int count){
  cout << "\nName"<<"\t"<<"Score\n";
  for (int i=0;i<count;i++){
        cout << team[i].getName() << "\t" << team[i].getScore() << "\n";
  }
}

int removePlayers(vector<Player>& team, int count){
  string name;
  cout << "Enter the name of the player you would like to remove\n:";
  cin >> name;
  for (int i=0; i<count; i++){
    if (team[i].getName()==name){
      team.erase(team.begin()+i);
      return 1;
    }
  }

  cout << "That player is not found.\n\n";
  return 0;
}
