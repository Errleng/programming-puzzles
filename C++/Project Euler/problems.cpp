#include <cmath>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string commaNumber(int n) {
  string stringNum = to_string(n);
  int position = stringNum.length()-3;
  int endPosition = 0;
  if (n < 0)
    endPosition = 1;
  while (position > endPosition){
    stringNum.insert(position, ",");
    position -= 3;
  }
  return stringNum;
}

vector<int> fibonacciEven(int n, int limit) {
  vector<int> evenNums;
  int i;
  int a = 1;
  int b = 2;
  int c = 0;
  while (b < limit) {
    c = a;
    a = b;
    b = c + b;
    if (b % 2 == 0 && b < limit) {
      evenNums.push_back(b);
    }
  }
  return evenNums;
}

int problem2() {
  vector<int> evenTerms = fibonacciEven(5, 4*1000000);
  int termsSum = 0;
  for (int i = 0; i < evenTerms.size(); i++){
    cout << evenTerms[i] << endl;
    termsSum += evenTerms[i];
  }
  string formattedResult = commaNumber(-40000);
  cout << "Sum is " << formattedResult << endl;
}

int main() {
  cout << "Hello Holy control tower!" << endl;
  problem2();
  return 0;
}
