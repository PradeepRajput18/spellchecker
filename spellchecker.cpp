#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include<fstream>



using namespace std;

string toLowerCase(const string& str){
    string lowerstr = str;
    transform(lowerstr.begin(),lowerstr.end(),lowerstr.begin(),::tolower);
    return lowerstr;
}


void spellchecker(const string& sentence,const unordered_map<string,int>& dictionary){
    stringstream ss(sentence);
    string word;

    while(ss >> word){
        string lowerWord = toLowerCase(word);
        if(dictionary.find(lowerWord)==dictionary.end()){
            cout<<"Misspelled word: "<<word<<endl;
        }else{
            cout<<"Correct word: "<<word<<endl;
        }
    }
}


int main(){
    string sentence;
    unordered_map<string, int> dict;
    cout<<"Enter a sentence: ";
    getline(cin,sentence);

    ifstream fin;
    string line;
    fin.open("wordsdictionary.txt");
    while(!fin.eof()){
        getline(fin,line);
        dict[line]++;
    }
    fin.close();

    spellchecker(sentence,dict);

    return 0;
}
