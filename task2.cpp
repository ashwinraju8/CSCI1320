#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

void deleteWord(string arr1[], string arr2[], int size, int i);

int main(){
    ifstream inputStream;
    inputStream.open("ignoreWords.txt");

    ifstream book;
    book.open("HungerGames.txt");

    ifstream test;
    test.open("testText.txt");

    int i = 0, bookN = 100000, testN = 30;
    string ignore[50];
    string testtxt[testN];
    string fullBook[bookN];

    while (book >> fullBook[i]){ // read txt files to arrays
            i++;
        }
    book.close();

    i = 0;

    while (test >> testtxt[i]){
        i++;
    }
    test.close();

    i = 0;

    while (inputStream >> ignore[i]){
        i++;
    }
    inputStream.close();

    deleteWord(testtxt, ignore, testN, i); // function that deletes words from array
    deleteWord(fullBook, ignore, bookN, i);

    ofstream outTest;                         // write arrays to txt files
    outTest.open("cleanedTestText.txt");
    for(int i = 0; i < testN; i++){
        if (testtxt[i] != ""){
            outTest << testtxt[i] << " ";
        }
    }
    outTest.close();

    
    ofstream outBook;
    outBook.open("cleanedText.txt");
    for(int i = 0; i < bookN; i++){
        if (fullBook[i] != ""){
            outBook << fullBook[i] << " ";
        }
    }
    outBook.close();

    return 0;
}

void deleteWord(string arr1[], string arr2[], int size, int i){
   
    for(int k = 0; k < size; k++){
        
        for(int j = 0; j < i; j++){
            
            if (arr1[k] == arr2[j]){
                arr1[k] = "";
            }
        }
    }
}