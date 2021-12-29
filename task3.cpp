#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct UniqueWord
{
string word ;
int numOccurrences ;
};

int main(){
    ifstream inStream;
    
    int n = 100000;
    int p = 0;
    UniqueWord unique[n];
    string text[n];
    int process[n];

    for (int b = 0; b < n; b++){
        process[b] = 0;
    }

    //inStream.open("cleanedTestText.txt");
    inStream.open("cleanedText.txt");

    while (inStream >> text[p]){
        p++;
    }
    inStream.close();

    int i;
    for (i = 0; i < p; i++){
        if (process[i] == 0){
            int count = 1;
            for (int j = i; j < p-1; j++){

                if (text[i] == text[j]){
                    unique[i].word = text[i];
                    unique[i].numOccurrences = count;
                    count++;
                    process[j] = 1;
                }
            }
        }    
    }

    bool swapping;
    do{
        swapping = false;
        for ( int k = 0; k < i-1; k++){
            if (unique[k].numOccurrences < unique[k+1].numOccurrences){
                UniqueWord temp;

                temp = unique[k];
                unique[k] = unique[k+1];
                unique[k+1] = temp;
                swapping = true;
            }  
        }
    }while(swapping);

    int k;
    for (k = 0; k < n; k++){
        if (unique[k].numOccurrences == 0){
            break;
        }
    }

    cout << "Ten Most Common Words: " << endl;
    for (int m = 0; m < 10; m++){
        cout << unique[m].word << endl; 
    }
cout << endl;
    cout << "Ten Least Common Words: " << endl;
    for (int m = k-10; m < k; m++){
        cout << unique[m].word << endl; 
    }

    
    ofstream outStream;
    outStream.open("words.txt");
    for(int i = 0; i < k; i++){
            outStream << unique[i].word << endl;   
    }
    outStream.close();

    ofstream outCount;
    outCount.open("counts.txt");
    for(int j = 0; j < k; j++){
            outCount << unique[j].numOccurrences << endl;
    }
    outCount.close();

    return 0;
}

