#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

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
        std::istringstream iss(magicRow);
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
//                    std::cout << "Palindrome: " << palindrome << " at index: " << i << std::endl;
                }
                else{
                    foundPalindrome = false;
                }
//                std::cout << "n: " << n << " i: " << i << std::endl;
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
    std::stringstream inputStream(input);
    std::string segment;
    std::vector<std::string> time;

    while (std::getline(inputStream, segment, ':')){
        time.push_back(segment);
    }
    std::cout << "Hours: " << time[0] << " Minutes: " << time[1] << std::endl;
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
        finalTime = std::to_string(hours) += ":";
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
    std::istringstream speedD(dmojistanSpeedInput);
    std::istringstream speedP(peglandSpeedInput);

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
        std::cout << "DMOJISTAN SPEEDS" << std::endl;
        for(int i = 0; i < dmojistanSpeed.size(); i++){
            std::cout << dmojistanSpeed[i] << " " << std::flush;
        }
        std::cout << "\n";
        std::cout << "PEGLAND SPEEDS" << std::endl;
        for(int i = 0; i < peglandSpeed.size(); i++){
            std::cout << peglandSpeed[i] << " " << std::flush;
        }
        std::cout << "\n";
        std::cout << "PAIRS" << std::endl;
        for (int i = 0; i < citizenNumber; i++){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    else if (questionNumber == 2){
        //match the slowest with the fastest
        std::sort(dmojistanSpeed.begin(), dmojistanSpeed.end());
        std::sort(peglandSpeed.begin(), peglandSpeed.end(), std::greater<int>());
        std::cout << "DMOJISTAN SPEEDS" << std::endl;
        for(int i = dmojistanSpeed.size() - 1; i >= 0; i--){
            std::cout << dmojistanSpeed[i] << " " << std::flush;
        }
        std::cout << "\n";
        std::cout << "PEGLAND SPEEDS" << std::endl;
        for(int i = peglandSpeed.size() - 1; i >= 0; i--){
            std::cout << peglandSpeed[i] << " " << std::flush;
        }
        std::cout << "\n";
        std::cout << "PAIRS" << std::endl;
        for (int i = citizenNumber - 1; i >= 0; i--){
            pairs.push_back(std::make_tuple(dmojistanSpeed[i], peglandSpeed[i]));
        }
    }
    int totalSpeed = 0;
    for (int i = 0; i < pairs.size(); i++){
        int partnerOne = std::get<0>(pairs[i]);
        int partnerTwo = std::get<1>(pairs[i]);
        std::cout << partnerOne << std::flush;
        std::cout << " " << partnerTwo << std::endl;
        if (partnerOne > partnerTwo){
            totalSpeed += partnerOne;
        }
        else{
            totalSpeed += partnerTwo;
        }
    }
    std::cout << "Total speed: " << totalSpeed << std::endl;
}

int main(int argc, char *argv[])
{
    return 0;
}
