#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
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
        //        cout << "Magic Row: " << magicRow << std::endl;
        std::stringstream iss(magicRow);
        int j = 0;
        while (iss >> magicSquare[i][j]){
            //            cout << "Magic Square: " << magicSquare[i][j] << std::endl;
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
            //            cout << i << " " << j << " " << magicSquare[i][j] << std::endl;
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
    for (int i = 0; i < word.length(); i++){
        int length = i;
        if (i > word.length()/2){
            length = word.length() - i;
        }
        for (int j = 0; j < (length); j++){
            std::string palindrome(1, word[i]);
            bool foundPalindrome = true;
            int n = 1;
            while (foundPalindrome){
                if (word[i-n] == word[i+n]){
                    palindrome.insert(0, 1, word[i-n]);
                    palindrome += word[i+n];
                    palindromes.push_back(palindrome);
                    //                    cout << "Palindrome: " << palindrome << " at index: " << i << std::endl;
                }
                else{
                    foundPalindrome = false;
                }
                //                cout << "n: " << n << " i: " << i << std::endl;
                if (n < i/2 + 1){
                    n++;
                }
                else{
                    foundPalindrome = false;
                    j = length;
                }
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
    cout << "Hours: " << time[0] << " Minutes: " << time[1] << std::endl;
    int hours = std::stoi(time[0]);
    int minutes = std::stoi(time[1]);
    int travelTime = 2 * 60;
    int startMinutes = hours * 60 + minutes;
    if (hours < 12){
        int minuteDifference = (7 * 60) - startMinutes;
        if (minuteDifference < 2 * 60){
            travelTime -= (travelTime - minuteDifference);
            travelTime += (2 * 60 - minuteDifference) * 2;
            if (startMinutes + travelTime > (10 * 60)){
                minuteDifference = (startMinutes + travelTime) - (10 * 60);
                travelTime -= minuteDifference;
                travelTime += minuteDifference/2;
            }
        }
    }
    hours = (startMinutes + travelTime)/60;
    minutes = (startMinutes + travelTime)%60;
    std::string finalTime;
    if (hours < 10){
        finalTime = std::to_string(hours) + ":";
        if (minutes < 10){
            finalTime += "0" + std::to_string(minutes);
        }
        else{
            finalTime += std::to_string(minutes);
        }
    }
    else{
        finalTime = std::to_string(hours) += ":" + std::to_string(minutes);
    }
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
        cout << "DMOJISTAN SPEEDS" << std::endl;
        for(int i = 0; i < dmojistanSpeed.size(); i++){
            cout << dmojistanSpeed[i] << " " << std::flush;
        }
        cout << "\n";
        cout << "PEGLAND SPEEDS" << std::endl;
        for(int i = 0; i < peglandSpeed.size(); i++){
            cout << peglandSpeed[i] << " " << std::flush;
        }
        cout << "\n";
        cout << "PAIRS" << std::endl;
        for (int i = 0; i < citizenNumber; i++){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    else if (questionNumber == 2){
        //match the slowest with the fastest
        std::sort(dmojistanSpeed.begin(), dmojistanSpeed.end());
        std::sort(peglandSpeed.begin(), peglandSpeed.end(), std::greater<int>());
        cout << "DMOJISTAN SPEEDS" << std::endl;
        for(int i = dmojistanSpeed.size() - 1; i >= 0; i--){
            cout << dmojistanSpeed[i] << " " << std::flush;
        }
        cout << "\n";
        cout << "PEGLAND SPEEDS" << std::endl;
        for(int i = peglandSpeed.size() - 1; i >= 0; i--){
            cout << peglandSpeed[i] << " " << std::flush;
        }
        cout << "\n";
        cout << "PAIRS" << std::endl;
        for (int i = citizenNumber - 1; i >= 0; i--){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    int totalSpeed = 0;
    for (int i = 0; i < pairs.size(); i++){
        int partnerOne = std::get<0>(pairs[i]);
        int partnerTwo = std::get<1>(pairs[i]);
        cout << partnerOne << std::flush;
        cout << " " << partnerTwo << std::endl;
        if (partnerOne > partnerTwo){
            totalSpeed += partnerOne;
        }
        else{
            totalSpeed += partnerTwo;
        }
    }
    cout << "Total speed: " << totalSpeed << std::endl;
}

int * countLetterOccurrences(std::string str){
    int i;
    int len = str.length();
    static int counts[26] = {0};

    for (i = 0; i < len; i++){
        counts[(int)str[i] - 97]++;
    }
    //for (i = 0; i < 25; i++){
    //	cout << i << " " << counts[i] << std::endl;
    //}
    return counts;
}

bool S1(){
    bool hasAsterisk = false;
    std::map<std::string, int> FFL;
    std::map<std::string, int> SFL;
    std::string word1;
    std::string word2;
    std::cin >> word1;
    std::cin >> word2;

    if (word1.length() != word2.length()){
        cout << "N" << std::endl;
        return false;
    }

    //UNCOMMENT IF USING MAP METHOD

    //for (int i = 0; i < word1.length(); i++){
    //	if (i % 2 == 1){
    //		word1.insert(i, " ");
    //	}
    //}
    //
    //for (int i = 0; i < word2.length(); i++){
    //	if (i % 2 == 1){
    //		word2.insert(i, " ");
    //	}
    //}

    cout << "word1 : " << word1 << std::endl;
    cout << "word2 : " << word2 << std::endl;

    for (int i = 0; i < word2.length(); i++){
        if (word2[i] == '*'){
            hasAsterisk = true;
        }
    }

    int* letters1 = countLetterOccurrences(word1);
    int* letters2 = countLetterOccurrences(word2);

    for (int i = 0; i < 26; i++){
        if (*(letters1 + i) < *(letters2 + i)){
            cout << "word2 has more " << i << "s than word1" << std::endl;
        }
        else if (*(letters1 + i) < *(letters2 + i)){
            cout << "word2 has letters not in word1" << std::endl;
        }
    }
    if (hasAsterisk){
        cout << "A" << std::endl;
    }
    else{
        cout << "N" << std::endl;
    }

    //MAP METHOD
    //More complex, but probably inefficient?

    //std::stringstream firstStream(word1);
    //while (firstStream >> word1){
    //	cout << "Letter: " << word1 << std::endl;
    //	FFL[word1]++;
    //}
    //std::stringstream secondStream(word2);
    //while (secondStream >> word2){
    //	cout << "Letter: " << word2 << std::endl;
    //	SFL[word2]++;
    //}
    //std::map<std::string, int>::iterator m;
    //cout << "WORD 1 LETTER COUNT" << std::endl;
    //for (m = FFL.begin(); m != FFL.end(); m++){
    //	cout << m->first << " -> "
    //		 << m->second << "\n";
    //}
    //cout << "WORD 2 LETTER COUNT" << std::endl;
    //for (m = SFL.begin(); m != SFL.end(); m++){
    //	cout << m->first << " -> "
    //		 << m->second << "\n";
    //}
    //std::map<std::string, int>::iterator j, k;
    //for (j = FFL.begin(), k = SFL.begin(); j != FFL.end(); ++j, ++k){
    //	if (k->first == "*"){
    //		hasAsterisk = true;
    //	}
    //	if (k->first != "*" && SFL.find(k->first) == SFL.end()){
    //		cout << k->first << " is not in first word" << std::endl;
    //	}
    //	m = FFL.find(k->first);
    //	if (m != FFL.end()){
    //		cout << m->first << " occurs " << m->second << " times" << std::endl;
    //	}
    //}
    //if (hasAsterisk){
    //	cout << "Second word is a wildcard anagram of the first" << std::endl;
    //}
    //return true;
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
            cout << restaurants[i][j] << " " << std::flush;
        }
        cout << ",";
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
        cout << "Input exceeds number of rice balls" << std::endl;
        return 0;
    }
    while (operationCount > 0) {
        operationCount = 0;
        for (int i = 0; i < sizes.size(); i++) {
            if (1 < i && i + 1 < sizes.size()) {
                if (sizes[i - 1] == sizes[i + 1]) {
                    if (sizes[i] == sizes[i-1] && sizes[i - 2] == sizes[i] + sizes[i - 1]) {
                        cout << "Skipped trio for duo of " << sizes[i] << " " << sizes[i - 1] << " at " << i << std::endl;
                        sizes[i] += sizes[i + 1];
                        sizes.erase(sizes.begin() + (i + 1));
                        i--;
                        operationCount++;
                    }
                    else {
                        cout << "Trio of " << sizes[i - 1] << " " << sizes[i] << " " << sizes[i + 1] << " at " << i << std::endl;
                        sizes[i] = sizes[i] + sizes[i + 1] + sizes[i - 1];
                        sizes.erase(sizes.begin() + (i - 1));
                        sizes.erase(sizes.begin() + i);
                        i--;
                        operationCount++;
                    }
                }
                if (i + 1 < sizes.size() && sizes[i] == sizes[i + 1] && sizes[i] != sizes[i + 2]) {
                    cout << "Duo of " << sizes[i] << " " << sizes[i + 1] << " at " << i << std::endl;
                    sizes[i] += sizes[i + 1];
                    sizes.erase(sizes.begin() + (i +  1));
                    i--;
                    operationCount++;
                }
                for (int k = 0; k < sizes.size(); k++) {
                    cout << sizes[k] << " " << std::flush;
                }
                cout << "\n";
            }
        }
    }
    cout << "\n";
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
//        cout << input[i] << std::flush;
        cells.push_back(std::stol(std::string(1, input[i])));
    }
//    cout << "\n";
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
//            cout << "Grew cell at " << lifeIndex[k] << std::endl;
        }
        for (int l = 0; l < deathIndex.size(); l++) {
            cells[deathIndex[l]] = 0;
//            cout << "Killed cell at " << deathIndex[l] << std::endl;
        }
//        for (int n = 0; n < cells.size(); n++) {
//            cout << cells[n] << std::flush;
//        }
//        cout << "\n";
    }
//    cout << "After " << generations << " generations" << std::endl;
    for (i = 0; i < cells.size(); i++) {
        cout << cells[i] << std::flush;
    }
//    cout << "\n";
    return cells;
}

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
    int inputNumber;
    vector<int> inputs;
    vector<int> highs;
    vector<int> lows;
    cin >> inputNumber;
    int input;
    for(int i=0; i<inputNumber; i++){
        scanf("%d", &input);
        inputs.push_back(input);
    }
    sort(inputs.begin(), inputs.end());
    for (int i=0; i<inputs.size(); i++){
        if (i < inputs.size()/2) {
            lows.push_back(inputs[i]);
        }
        else{
            highs.push_back(inputs[i]);
        }
    }
    sort(highs.begin(), highs.end());
    sort(lows.begin(), lows.end(), greater<int>());
    int j = 0;
    int k = 0;
    for(int i=0; i<inputs.size(); i++){
        if (i%2 == 0){
            inputs[i] = lows[j];
            j++;
        }
        else{
            inputs[i] = highs[k];
            k++;
        }
    }
    for(int i=0; i<inputs.size(); i++){
        if (i == inputs.size()-1){
            cout << inputs[i] << endl;
        }
        else {
            cout << inputs[i] << " " << flush;
        }
    }
}

int main(int argc, char *argv[])
{
    cout << "Program Start" << std::endl;
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    S5();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    auto runTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << "\nExecution took " << runTime << " miliseconds" << endl;
    return 0;
}
