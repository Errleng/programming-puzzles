#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cmath>

using namespace std;

int partyInvitation() {
  int friendsNumber = 10;
  int roundsNumber = 2;
  vector<int> factors = {2, 3};
  vector<int> friends;
  for (int i=1; i<=friendsNumber; i++){
    friends.push_back(i);
  }
  for (int i=0; i<roundsNumber; i++){
    vector<int> eraseIndex;
    for (int j=1; j<=friends.size(); j++){
      if (j%factors[i] == 0){
        eraseIndex.push_back(j-1);
      }
    }
    for (int k=eraseIndex.size()-1; k>=0; k--){
      friends.erase(friends.begin()+eraseIndex[k]);
    }
  }
  for (int i=0; i<friends.size(); i++){
    cout << friends[i] << " " << flush;
  }
  cout << "\n";
}

int highTide() {
  int inputNumber = 8;
  vector<int> inputs = {10, 50, 40, 7, 3, 110, 90, 2};
  vector<int> highs;
  vector<int> lows;
  for (int i=0; i<inputs.size(); i++){
    if (i%2 != 0){
      highs.push_back(inputs[i]);
    }
    else {
      lows.push_back(inputs[i]);
    }
  }
  for(int i=0; i<highs.size(); i++){
    cout << highs[i] << " " << flush;
  }
  cout << "HIGHS" << endl;
  for(int i=0; i<lows.size(); i++){
    cout << lows[i] << " " << flush;
  }
  cout << "LOWS" << endl;
}

int main() {
  highTide();
  return 0;
}
