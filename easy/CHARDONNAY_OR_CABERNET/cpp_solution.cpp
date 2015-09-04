#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
int main(int argc, char *argv[]) {
  ifstream stream(argv[1]);
  string line;
  static const int name_length=15;
  static const int remember_length=5;
  static const int wine_min_count=2;
  static const int wine_max_count = 10;
  while (getline(stream, line)){
    vector<string> wine_names(wine_max_count);
    string next; //iterating string to store in the vector
    string targetString; //letters remembered
    istringstream iss (line); //stream
    bool atLeastOne=false;
    //cout<<"LINE " <<line<<endl;
    iss >> next;
    int actualCount=0;
    //if the next character is not "|", continue
    while (next.compare("|")!=0){
      try{
        wine_names[actualCount]=next;
        iss>>next;
        actualCount++;
      }
      catch(std::out_of_range o){
        cout<<o.what()<<endl;
      }
    }
    iss>>targetString;
    //cout<<"TARGET  "<<targetString<<endl;
    bool firstCorrect=true;
    for (int i=0;i<wine_names.size();i++){
      map<char,int> char_table; //this map keeps track of which ascii table characters are in the word in lower case.
      bool goodName=false;
      string current_string = wine_names[i];
      for (int j=0;j<current_string.length();j++){
        // if (char_table[tolower(current_string[j])]==null){
        //   char_table[tolower(current_string[j])]=1;
        // } else {
          char_table[tolower(current_string[j])]++;
        //}
      }
      for (int j=0;j<targetString.length();j++){
        if (char_table[targetString.at(j)]>=1){
          goodName=true;
          char_table[targetString.at(j)]--;
        } else{
          //characters missing. move to next string.
          goodName=false;
          break;
        }
      }
      if (goodName){
        atLeastOne=true;
        if (firstCorrect){
          cout<<wine_names[i];
          firstCorrect=false;
        }
        else
          cout<<" "<<wine_names[i];
      }

    }
    if (!atLeastOne){
      cout<<"False"<<endl;
    } else {
      cout<<""<<endl;
    }
  }
  return 0;
}