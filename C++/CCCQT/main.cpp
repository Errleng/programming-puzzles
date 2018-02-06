#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
//Waterloo CCC 2016 Junior Questions
int J1(){
    //J1: Tournament Selection
    int playerGroup = 0;
    int winCount = 0;

    for (int i = 0; i < 6; i++){
        char input;
        std::cin >> input;
        if (input == 'W'){
            winCount += 1;
        }
    }

    if (winCount >= 5){
        playerGroup = 1;
    }
    else if (winCount >= 3){
        playerGroup = 2;
    }
    else if (winCount >= 1){
        playerGroup = 3;
    }
    else{
        playerGroup = -1;
    }
    return playerGroup;
}

bool J2(){
    //J2: Magic Squares
    int total = 0;
    int previousTotal = 0;
    int magicSquare[4][4];
    for (int i = 0; i < 4; i++){
        std::string magicRow;
        std::getline(std::cin, magicRow);
//        std::cout << "Magic Row: " << magicRow << std::endl;
        std::stringstream iss(magicRow);
        int j = 0;
        while (iss >> magicSquare[i][j]){
//            std::cout << "Magic Square: " << magicSquare[i][j] << std::endl;
            j++;
        }
    }

    for (int i = 0; i < 4; i++){
        if (previousTotal != total and i > 1){
            return false;
        }
        previousTotal = total;
        total = 0;
        for (int j = 0; j < 4; j++){
//            std::cout << i << " " << j << " " << magicSquare[i][j] << std::endl;
            total += magicSquare[i][j];
        }
    }
    return true;
}

std::string J3(){
    //J3: Hidden Palindrome
    std::string word;
    std::vector<std::string> palindromes;
    std::cin >> word;
    int length = word.length();
    for (int i = 0; i < length; i++){
        for (int n = 0; n < length; n++){
           string substring = word.substr(n,i+1);
           int j = 0;
           int k = substring.length()-1;
           bool isPalindrome = true;
           while (j < k){
               if (substring[j] != substring[k]){
                   isPalindrome = false;
               }
               j++;
               k--;
           }
           if (isPalindrome){
               palindromes.push_back(substring);
           }
        }
    }
    std::string longestString;
    for (int i = 0; i < palindromes.size(); i++){
        if (palindromes[i].length() > longestString.length()){
            longestString = palindromes[i];
        }
    }
    return longestString;
}

bool isPalindrome(std::string string){ //For fast check
    int i = 0;
    int j = string.length() - 1;
    while (i < j){
        if (string[i] != string[j])
            return false;
        i++;
        j--;
    }
    return true;
}

std::string J4(){
    std::string input;
    std::cin >> input;
    std::stringstream stream(input);
    std::string segment;
    std::vector<std::string> time;

    while (std::getline(stream, segment, ':')){
        time.push_back(segment);
    }
    int hours = std::stoi(time[0]);
    int minutes = std::stoi(time[1]);
    int travelTime = 2 * 60;
    int startMinutes = minutes + hours * 60;
    int travelMinutes = 0;
    int rushStart1 = 7 * 60;
    int rushEnd1 = 10 * 60;
    int rushStart2 = 15 * 60;
    int rushEnd2 = 19 * 60;
    for (int i=0; i < travelTime; i++){
        if (startMinutes + travelMinutes >= rushStart1 && startMinutes + travelMinutes < rushEnd1 || startMinutes + travelMinutes >= rushStart2 && startMinutes + travelMinutes < rushEnd2) {
            travelMinutes += 2;
        }
        else {
            travelMinutes += 1;
        }
    }
    startMinutes += travelMinutes;
    int endHours = startMinutes/60;
    int endMinutes = startMinutes%60;
    string hourZero = "";
    string minuteZero = "";
    if (endHours >= 24) {
        endHours -= 24;
    }
    if (endHours < 10) {
        hourZero = "0";
    }
    if (endMinutes < 10) {
        minuteZero = "0";
    }
    string finalTime = hourZero + to_string(endHours) + ":" + minuteZero + to_string(endMinutes);
    return finalTime;
}

int J5(){
    int questionNumber = 0;
    int citizenNumber = 0;
    std::string dmojistanSpeedInput;
    std::string peglandSpeedInput;
    std::vector<int> dmojistanSpeed;
    std::vector<int> peglandSpeed;
    std::vector<std::tuple<int, int>> pairs;
    std::cin >> questionNumber;
    std::cin >> citizenNumber;
    std::cin.ignore();
    std::getline(std::cin, dmojistanSpeedInput);
    std::getline(std::cin, peglandSpeedInput);
    std::stringstream speedD(dmojistanSpeedInput);
    std::stringstream speedP(peglandSpeedInput);

    for (int speed; speedD >> speed;){
        dmojistanSpeed.push_back(speed);
    }
    for (int speed; speedP >> speed;){
        peglandSpeed.push_back(speed);
    }

    if (questionNumber == 1){
        //match the fastest with each other
        std::sort(dmojistanSpeed.begin(), dmojistanSpeed.end());
        std::sort(peglandSpeed.begin(), peglandSpeed.end());
        for (int i = 0; i < citizenNumber; i++){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    else if (questionNumber == 2){
        //match the slowest with the fastest
        std::sort(dmojistanSpeed.begin(), dmojistanSpeed.end());
        std::sort(peglandSpeed.begin(), peglandSpeed.end(), std::greater<int>());
        for (int i = citizenNumber - 1; i >= 0; i--){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    int totalSpeed = 0;
    for (int i = 0; i < pairs.size(); i++){
        int partnerOne = std::get<0>(pairs[i]);
        int partnerTwo = std::get<1>(pairs[i]);
        if (partnerOne > partnerTwo){
            totalSpeed += partnerOne;
        }
        else{
            totalSpeed += partnerTwo;
        }
    }
    return totalSpeed;
}

int * countLetterOccurrences(std::string str){
    int i;
    int len = str.length();
    int *counts = new int[26];

    for (i = 0; i < len; i++){
        counts[(int)str[i] - 97]++;
    }
//    for (i = 0; i < 25; i++){
//        std::cout << i << " " << counts[i] << std::endl;
//    }
    return counts;
}

bool S1(){
    bool hasAsterisk = false;
    std::string word1;
    std::string word2;
    std::cin >> word1;
    std::cin >> word2;

    if (word1.length() != word2.length()){
        std::cout << "N" << std::endl;
        return false;
    }
    for (int i = 0; i < word2.length(); i++){
        if (word2[i] == '*'){
            hasAsterisk = true;
        }
    }

    int* letters1 = countLetterOccurrences(word1);
    int* letters2 = countLetterOccurrences(word2);

    for (int i = 0; i < 26; i++){
        if (*(letters1 + i) < *(letters2 + i)){
            std::cout << "N" << std::endl;
            return false;
        }
    }
    delete[] letters1;
    delete[] letters2;
    cout << "A" << endl;
    return true;
}

//S2 == J5

int S3() {
  std::string input;
  std::cin >> input;
  std::stringstream stream(input);
  std::vector<int> NM;
  std::vector<int> phoRestaurants;
  std::vector<std::vector<int>> restaurants;
  int i = 0;
  for (int first; stream >> first;) {
    NM.push_back(first);
  }
  std::cin >> input;
  stream.str(std::string());
  stream << input;
  for (int restaurantNum; stream >> restaurantNum;) {
    phoRestaurants.push_back(restaurantNum);
  }
  std::cin.ignore();
  for (i = 0; i < NM[0]; i++) {
    std::vector<int> restaurant;
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::stringstream iss(inputLine);
    for (int thirds; iss >> thirds;) {
      restaurant.push_back(thirds);
    }
    restaurants.push_back(restaurant);
  }
  for (i = 0; i < restaurants.size(); i++) {
    for (int j = 0; j < restaurants[i].size(); j++) {
      std::cout << restaurants[i][j] << " " << std::flush;
    }
    std::cout << ",";
  }

  for (i = 0; i < phoRestaurants.size(); i++) {
    for (int j = 0; j < restaurants.size(); j++) {
      return 0;
    }
  }
}

int S4() {
    int riceballNumber;
    int operationCount = 1;
    std::string input;
    std::cin >> riceballNumber;
    std::vector<int>sizes;
    std::cin.ignore();
    getline(std::cin, input);
    std::stringstream stream(input);
    for (int size; stream >> size;){
        sizes.push_back(size);
    }
    if (sizes.size() > riceballNumber) {
        std::cout << "Input exceeds number of rice balls" << std::endl;
        return 0;
    }
    while (operationCount > 0) {
        operationCount = 0;
        for (int i=0; i<sizes.size(); i++){
            if (i < sizes.size()-1){
                if (i+2 < sizes.size() - 1 && sizes[i] == sizes[i+2] && (sizes[i-2] + sizes[i-1]) != (sizes[i] + sizes[i+1])) {
                    std::cout << "Trio of " << sizes[i] << " " << sizes[i+1] << " " << sizes[i+2] << " at " << i << std::endl;
                    sizes[i] += sizes[i+1] + sizes[i+2];
                    sizes.erase(sizes.begin() + i+2);
                    sizes.erase(sizes.begin() + i+1);
                    i--;
                    operationCount++;
                }
                else if (i < sizes.size()-1 && sizes[i] == sizes[i+1]){
                    std::cout << "Duo of " << sizes[i] << " " << sizes[i+1] << " at " << i << std::endl;
                    sizes[i] += sizes[i+1];
                    sizes.erase(sizes.begin() + i+1);
                    i--;
                    operationCount++;
                }
                for (int k = 0; k < sizes.size(); k++) {
                    std::cout << sizes[k] << " " << std::flush;
                }
                cout << "\n";
            }
        }
    }
//    while (operationCount > 0) {
//        operationCount = 0;
//        for (int i = 0; i < sizes.size(); i++) {
//            if (i + 1 < sizes.size()) {
//                if (sizes[i - 1] == sizes[i + 1]) {
//                    if (sizes[i] == sizes[i-1] && sizes[i-2] == sizes[i] + sizes[i-1]) {
//                        std::cout << "Skipped trio for duo of " << sizes[i] << " " << sizes[i - 1] << " at " << i << std::endl;
//                        sizes[i] += sizes[i + 1];
//                        sizes.erase(sizes.begin() + (i + 1));
//                        i--;
//                        operationCount++;
//                    }
//                    else {
//                        std::cout << "Trio of " << sizes[i - 1] << " " << sizes[i] << " " << sizes[i + 1] << " at " << i << std::endl;
//                        sizes[i] = sizes[i] + sizes[i + 1] + sizes[i - 1];
//                        sizes.erase(sizes.begin() + (i - 1));
//                        sizes.erase(sizes.begin() + i);
//                        i--;
//                        operationCount++;
//                    }
//                }
//                if (i + 1 < sizes.size() && sizes[i] == sizes[i + 1] && sizes[i] != sizes[i + 2]) {
//                    std::cout << "Duo of " << sizes[i] << " " << sizes[i + 1] << " at " << i << std::endl;
//                    sizes[i] += sizes[i + 1];
//                    sizes.erase(sizes.begin() + (i +  1));
//                    i--;
//                    operationCount++;
//                }
//                for (int k = 0; k < sizes.size(); k++) {
//                    std::cout << sizes[k] << " " << std::flush;
//                }
//                std::cout << "\n";
//            }
//        }
//        if (operationCount == 0){
//            cout << "NOP" << endl;
//        }
//    }
    std::cout << "\n";
    int maximumSize = *max_element(sizes.begin(), sizes.end()); //Get value from iterator by dereferencing it
    return maximumSize;
}

std::vector<long> S5() {
    int generations;
    int cellCount;
    std::string input;
    std::vector<long> NT;
    std::vector<long> cells;
    std::vector<int> deathIndex;
    std::vector<int> lifeIndex;
    int i = 0;
    getline(std::cin, input);
    std::stringstream stream(input);
    for (long inputLong; stream >> inputLong;){
    NT.push_back(inputLong);
    }
    cellCount = NT[0];
    generations = NT[1];

    std::cin >> input;

    for (i = 0; i < input.length(); i++) {
        std::cout << input[i] << std::flush;
        cells.push_back(std::stol(std::string(1, input[i])));
    }

    std::cout << "\n";
    int adjacent = 0;
    for (i = 0; i < generations; i++) {
        lifeIndex.clear();
        deathIndex.clear();
        for (int j = 0; j < cells.size(); j++) {
            if (j == 0) {
                adjacent = cells[j + 1] + cells[cells.size() - 1];
                if (adjacent == 1) {
                    lifeIndex.push_back(j);
                }
                else {
                    deathIndex.push_back(j);
                }
            }
            else if (j == cells.size() - 1) {
                adjacent = cells[0] + cells[j - 1];
                if (adjacent == 1) {
                    lifeIndex.push_back(j);
                }
                else {
                    deathIndex.push_back(j);
                }
            }
            else {
                adjacent = cells[j + 1] + cells[j - 1];
                if (adjacent == 1) {
                    lifeIndex.push_back(j);
                }
                else {
                    deathIndex.push_back(j);
                }
            }
        }
        for (int k = 0; k < lifeIndex.size(); k++) {
            cells[lifeIndex[k]] = 1;
            std::cout << "Grew cell at " << lifeIndex[k] << std::endl;
        }
        for (int l = 0; l < deathIndex.size(); l++) {
            cells[deathIndex[l]] = 0;
            std::cout << "Killed cell at " << deathIndex[l] << std::endl;
        }
        for (int n = 0; n < cells.size(); n++) {
            std::cout << cells[n] << std::flush;
        }
        std::cout << "\n";
    }
    std::cout << "After " << generations << " generations" << std::endl;
    for (i = 0; i < cells.size(); i++) {
        std::cout << cells[i] << std::flush;
    }
    std::cout << "\n";
    return cells;
}


int main(int argc, char *argv[])
{
    std::cout << "Program Start" << std::endl;
    std::cout << S4() << std::endl;
    return 0;
}
