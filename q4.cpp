#include <iostream> 
#include <cstdlib> // for exit()
#include <cctype>  // for tolower()

using namespace std;

class Month
{
public:
  //constructor to set month based on first 3 chars of the month name
  Month(char c1, char c2, char c3);   

  //a constructor to set month base on month number, 1 = January etc.
  Month( int monthNumber);         

  //a default constructor (what does it do? nothing)
  Month(); // done, no debugging to do

  //an input function to set the month based on the month number
  void getMonthByNumber(istream& in); 

  //input function to set the month based on a three character input
  int getMonthByName(istream& in);  

  //an output function that outputs the month as an integer,
  void outputMonthNumber(ostream& out){cout << mnth;}; 

  //an output function that outputs the month as the letters.
  void outputMonthName(ostream& out);  

  //a function that returns the next month as a month object
  Month nextMonth(); //
  //NB: each input and output function have a single formal parameter
  //for the stream
   
  
private:
  int mnth;
};


int main(){
  // initialize a Month class w/ default construcor
  Month def;
  cout << "Default constructor w/ 1st 3 of name output: ";
  def.outputMonthName(cout);

  //initialize a Month class w/ char arguments
  Month charz('n','o','v');
  cout << "\nChar argument constructor w/ number output: ";
  charz.outputMonthNumber(cout);
  
  //initialize a Month class w/ an integer argument
  Month integ(5);
  cout << "\nInteger argument constructor w/ name output: ";
  integ.outputMonthName(cout);

  //set the mnth value for def using a set of 3 characters 
  cout << "\nInput w/ first 3 letters:";
  def.getMonthByName(cin);
  def.outputMonthNumber(cout);

  cout << "\nInput w/ int value\n:";
  integ.getMonthByNumber(cin);
  integ.outputMonthName(cout);

  Month next = integ.nextMonth();

  cout << "\nNext month from previous: ";
  next.outputMonthName(cout);

  return 1;
}

int Month::getMonthByName(istream& in){
  string f3;
  string monthList[12]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
  
  in >> f3;
  
  for(int i=1;i<13;i++){
    if(f3==monthList[i]){
      mnth = i+1;
      return i+1;
    }
  }

}

void Month::getMonthByNumber(istream& in){
  in >> mnth;
}

void Month::outputMonthName(ostream& out){
  string monthList[12]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
  out << monthList[mnth-1];
}

Month Month::nextMonth(){
  int next;
  if (mnth==12){
    next=1;
  }
  else next=mnth+1;
  Month m(next);
  return m;
}

Month::Month(char c1, char c2, char c3){
  string f3;
  string monthList[12]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
  f3+=c1; f3+=c2; f3+=c3;

  for(int i=1;i<13;i++){
    if(f3==monthList[i]){
      mnth=i+1;
      return;
    }
  }
  cout << "Enter a valid month\n";
  exit(1);
}

Month::Month(int monthNumber)
  : mnth(monthNumber)
  {
    if ((monthNumber>12)||(monthNumber<1)){
      cout << "Illegal Month Value\n";
      exit(1);
    }
  }

Month::Month()
  : mnth(1)
  {}
