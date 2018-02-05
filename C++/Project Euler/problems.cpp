#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

int problem1() {
  int multipleSum = 0;
  int number1 = 3;
  int number2 = 5;
  for (int i = 0; i < 1000; i++) {
    if (i%number1 == 0 || i%number2 == 0){
      multipleSum += i;
    }
  }
  cout << "Sum " << multipleSum << endl;
}

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
    if (b % 2 == 0 && b < limit) {
      evenNums.push_back(b);
    }   c = a;
    a = b;
    b = c + b;
  }
  return evenNums;
}

string problem2() { //Sum of even Fibonacci numbers less than 4000000
  cout << "This function computes the sum of all even Fibonacci terms under 4 million" << endl;
  vector<int> evenTerms = fibonacciEven(5, 4000000);
  int termsSum = 0;
  for (int i = 0; i < evenTerms.size(); i++){
    cout << evenTerms[i] << endl;
    termsSum += evenTerms[i];
  }
  string formattedResult = commaNumber(termsSum);
  cout << "Sum is " << formattedResult << endl;
  return formattedResult;
}

vector<int> primeFactorize(long n, vector<long> primes) {
  vector<int> primeFactors;
  for (long long i = 0; i < primes.size(); i++){
    if (n % primes[i] == 0){
      primeFactors.push_back(primes[i]);
    }
  }
  return primeFactors;
}

vector<long> sieve_Eratosthenes(long long n) {
  long long number = n;
  vector<long> primeFactor;
  vector<bool> primeTruth(number, true);
  long long i = 2;
  while (i * i <= number) {
    if (primeTruth[i]){
      for (long long j = i*i; j<=number+1; j+=i){
        primeTruth[j] = false;
      }
    }
    i += 1;
  }
  for (long long k = 2; k <= number; k++){
    if (primeTruth[k]){
      primeFactor.push_back(k);
    }
  }
  return primeFactor;
}

long long largestPrimeFactor(long long n) {
  long long largestFactor = 0;
  long squareFactors[2]; //Factors less than square root have factors larger than square root
  bool isPrime = true; //EX: √24 = 4.8. Factors 2, 3, 4 < 4.8. 24/2 = 12, 24/3 = 8, etc...
  for (long i = 2; i * i < n; i++) {
    if (n%i == 0){
      squareFactors[0] = i;
      squareFactors[1] = n/i;
      for (int j = 0; j < 2; j++){
        isPrime = true;
        for (long k = 2; k * k < squareFactors[j]; k++){
          if (squareFactors[j]%k == 0){
            isPrime = false;
            break;
          }
        }
        if (isPrime && squareFactors[j] > largestFactor){
          largestFactor = squareFactors[j];
        }
      }
    }
  }
  return largestFactor;
}

int problem3() {
  cout << "This function finds the greatest prime factor of a number" << endl;
  long long numberToFactor = 600851475143;
  //vector<long> primeNumbers = sieve_Eratosthenes(numberToFactor); 
  //vector<int> primeFactors = primeFactorize(numberToFactor, primeNumbers);
  //cout << "Prime factors of " << numberToFactor << " are:" << endl;
  //for (int i = 0; i < primeFactors.size(); i++){
  //  cout << primeFactors[i] << " " << flush;
  //}
  //cout << "\n";
  long long primeFactor = largestPrimeFactor(numberToFactor);
  cout << "Largest prime factor is " << primeFactor << endl;
}

bool isPalindrome(string str) {
  string reverseStr = str;
  reverse(reverseStr.begin(), reverseStr.end());
  if (reverseStr == str){
    return true;
  }
  return false;
}

vector<int> palindromeProducts(int start, int end) {
  vector<int> palindromes;
  int product = 0;
  if (start > end) {
    end = start + end;
    start = end - start;
    end = end - start;
  }
  for (int i = end; i > start; i--){
    for (int j = end; j > start; j--){
      product = i*j;
      if (isPalindrome(to_string(product))){
        palindromes.push_back(product);
      }
    }
  }
  return palindromes;
}

int problem4() {
  cout << "This function finds the greatest palindrome product in a range" << endl;
  vector<int> palindromeNumbers = palindromeProducts(900, 1000);
  int largestPalindromeNumber = *max_element(palindromeNumbers.begin(), palindromeNumbers.end());
  cout  << "Largest palindrome number is " << largestPalindromeNumber << endl;
}

int LCM(vector<int> numbers) {
  vector<int> erase;
  numbers.erase(remove(numbers.begin(), numbers.end(), 0), numbers.end());
  numbers.erase(remove(numbers.begin(), numbers.end(), 1), numbers.end());
  for (int i = numbers.size()-1; i > 1; i--){
    int j = 0;
    while (j < i) {
      if (numbers[i]%numbers[j] == 0){
        cout << numbers[j] << " " << numbers[i] << endl;
        erase.push_back(j);
        break;
      }
      j++;
    }
  }
  for (int k = 0; k < erase.size(); k++){
    numbers.erase(numbers.begin() + erase[k]);
  }
  int commonMultiple = *max_element(numbers.begin(), numbers.end());
  int greatestNumber = commonMultiple;
  while (true){
    bool isCommon = true;
    for (int i = 0; i < numbers.size(); i++){
      if (commonMultiple%numbers[i] != 0) {
        isCommon = false;
      }
    }
    if (isCommon){
      break;
    }
    commonMultiple += greatestNumber;
  }
  return commonMultiple;
}

int problem5(){
  cout << "This function finds the lowest common multiple of many numbers" << endl;
  vector<int> numberRange;
  int length = 20;
  for (int i = 1; i <= length; i++){
    numberRange.push_back(i);
  }
  int leastCommonMultiple = LCM(numberRange);
  cout << "Lowest common multiple is " << leastCommonMultiple << endl;
}

int main() {
  cout << "From the Evil spaceship to the Holy control tower!" << endl;
  chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
  problem5();
  chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
  auto timeTaken = chrono::duration_cast<chrono::microseconds>(end - start).count();
  cout << "Program took " << timeTaken << " microseconds" << endl;
  return 0;
}
