#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;

map<char,int>valueMap;

int main(){

    string leftSub,rightSub,str;
    int sum, it = 0;
    int midpoint;

    ifstream file("../puzzleInput/day3.txt");
    
    while(getline(file, str)){
        map <char,int> occuranceMap;
        midpoint = str.length()/2;
        cout<<str.length()<<endl;
        cout<<floor(midpoint)<<endl;
        
        leftSub = str.substr(0,midpoint);
        
        for(int i=0;i<leftSub.length();i++){
            if(occuranceMap.find(leftSub[i]) == occuranceMap.end()){
                occuranceMap.insert({leftSub[i],0}); //not found then insert
            }
            else{
                continue; //we only want to know if the character exists in the left substring, ignore multiple occurances 
            }
        
        }
        cout<<"made it"<<endl;
        for(int i=0; i<occuranceMap.size();i++){
            if(occuranceMap[i]>1){
                cout<<occuranceMap.at(i)<<endl;
                //sum+=occuranceMap[i];
            }
        }

        rightSub = str.substr(midpoint,str.length()/2);
        cout<<rightSub<<endl;
        for(int i=0;rightSub.length();i++){
            if(occuranceMap.find(rightSub[i]) == occuranceMap.end()){
                continue;
            }
            else{
                occuranceMap[i] = occuranceMap[i]++;
            }
            //cout<<"uhh"<<endl;
        }

        for(int i=0; i<occuranceMap.size();i++){
            if(occuranceMap[i]>1){
                sum+=occuranceMap[i];
            }
        }
        cout<<it<<endl;
        it++;

    }
    cout<<sum<<endl;

    return 0;
}