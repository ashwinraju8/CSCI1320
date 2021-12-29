#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct wordPairs{
    
    int counter;
    string pair;
};


int main(){
    ifstream inStream;
    
    const int n = 100000;
    string text[n];
    int numWords = 0;
    wordPairs bookPairs[n];
    int numPairs =0;

    inStream.open("HungerGames.txt");
// number of words in the book
    while (inStream >> text[numWords]){
        numWords++;
    }
    inStream.close();
    string word;
    cout << "Enter word: ";
    cin >> word;    

    int i;
    for (i = 0; i < numWords; i++){
        if (word == text[i]){
            bool found = false;
            for (int k = 0; k < numPairs; k++){
                if (bookPairs[k].pair == text[i+1]){
                    bookPairs[k].counter++;
                    found = true;
                }
            }
            if (found == false){
                bookPairs[numPairs].pair = text[i+1];
                bookPairs[numPairs].counter = 1;
                numPairs++;
            }
        }
    }

    bool swapping;
    do{
        swapping = false;
        for ( int j = 0; j < i-1; j++){
            if (bookPairs[j].counter < bookPairs[j+1].counter){
                wordPairs temp;

                temp = bookPairs[j];
                bookPairs[j] = bookPairs[j+1];
                bookPairs[j+1] = temp;
                swapping = true;
            }  
        }
    }while(swapping);

    cout << bookPairs[0].pair << ": " << bookPairs[0].counter << endl;

    return 0;
}