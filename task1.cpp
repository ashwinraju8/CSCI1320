#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream inStream;
    
    string fullBook[100000];
    int numWords = 0;

    inStream.open("HungerGames.txt");
// number of words in the book
    while (inStream >> fullBook[numWords]){
        numWords++;
    }
    inStream.close();
    
    const int words_tot = numWords;
    cout << "Number of words: " << words_tot << endl;

// save first 30 words of book to testText.txt
    ofstream outStream;
    outStream.open("testText.txt");

    for(int k = 0; k < 30; k++){
        outStream << fullBook[k] << " ";
    }
    outStream.close();

    return 0;
}