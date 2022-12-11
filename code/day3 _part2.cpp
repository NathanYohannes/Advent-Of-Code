#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cmath>
using namespace std;

map<char,int>valueMap;

int main(){

    string leftSub,rightSub,str;
    int sum,it = 0;
    int midpoint;

    for(int i=0; i<26;i++) //Initialize the Value Pairing Map
        valueMap.insert(pair<char,int>('a'+i,i+1));
    for(int i=0;i<26;i++)
        valueMap.insert(pair<char,int>('A'+i,i+27));
    
    ifstream file("../puzzleInput/day3.txt");
    
    while(getline(file, str)){
        map <char,int> occuranceMap; //create a fresh occuranceMap for each line
        if(it%3 == 0){
            occuranceMap.clear();
        }

        midpoint = str.length()/2;

        leftSub = str.substr(0,midpoint);
        for (const char &c: leftSub){
            // check if key `c` exists in the map or not
            std::map<char, int>::iterator it = occuranceMap.find(c);
            if (it != occuranceMap.end()) { //if key already exists on map, ignore
                continue;
            }
            // key not found
            else {
                occuranceMap.insert(std::make_pair(c, 1));
            }
        }

        rightSub = str.substr(midpoint,str.length()/2); 
        for (const char &c: rightSub){
            std::map<char, int>::iterator it = occuranceMap.find(c);

            // key already present on the map
            if (it != occuranceMap.end()) {
                it->second++;    // increment map's value for key `c`
            }
            //if key is not present in map continue
        }
        
        for(map<char ,int>::const_iterator it=occuranceMap.begin();it !=occuranceMap.end();++it){
            if(it->second>1){ //if the value is > 1, it exists on the left and right side
                sum+=valueMap.at(it->first); //add it's corresponding value to the sum
            }
        }
        it++;
    }
    cout<<"sum: "<<sum<<endl;
    
    return 0;
}