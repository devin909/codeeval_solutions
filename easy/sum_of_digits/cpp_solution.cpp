#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;
int main(int argc, char *argv[]) {
  ifstream stream(argv[1]);
  string line;

  while (getline(stream, line)){

    int sum=0;
    string number;

    istringstream iss (line);
    iss>>number;

    for (int i=0;i<number.length();i++){
      sum+=number.at(i)-'0';
      //cout<<number.at(i)<< " ";
      //cout<<sum<<" ";
    }
    cout<<sum<<endl;
  }
  return 0;
}