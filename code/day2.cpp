#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;



map<pair<char,char>,int> scoreMap;
map<pair<char,char>,int> scoreMap2;


int main()
{
    int score, score2, it = 0;
    char col1, col2;
    string str;

    scoreMap[make_pair('A','X')] = 4;
    scoreMap[make_pair('B','X')] = 1;
    scoreMap[make_pair('C','X')] = 7;

    scoreMap[make_pair('A','Y')] = 8;
    scoreMap[make_pair('B','Y')] = 5;
    scoreMap[make_pair('C','Y')] = 2;
    
    scoreMap[make_pair('A','Z')] = 3;
    scoreMap[make_pair('B','Z')] = 9;
    scoreMap[make_pair('C','Z')] = 6;
//-------------------------------------//
    scoreMap2[make_pair('A','X')] = 3;
    scoreMap2[make_pair('A','Y')] = 4;
    scoreMap2[make_pair('A','Z')] = 8;

    scoreMap2[make_pair('B','X')] = 1;
    scoreMap2[make_pair('B','Y')] = 5;
    scoreMap2[make_pair('B','Z')] = 9;

    scoreMap2[make_pair('C','X')] = 2;
    scoreMap2[make_pair('C','Y')] = 6;
    scoreMap2[make_pair('C','Z')] = 7;


    ifstream file("../puzzleInput/day2.txt");
    //ifstream file("../puzzleInput/testinput.txt");

    
    while(getline(file, str)){

        col1 = str[0];
        col2 = str[2];

        score += scoreMap[make_pair(col1,col2)];
        score2 += scoreMap2[make_pair(col1,col2)];

        
        it++;
    }
    cout<<"Score for Part 1: "<<score<<"\n";
    cout<<"Score for Part 2: "<<score2<<"\n";
    return 0;
}
//9+7+7+9+6