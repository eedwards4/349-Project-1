#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    int cases; int numships, distance, t1, t2, t3; string line;
    vector<int> ships;
    fstream file("test.txt");
    getline(file, line);
    cases = stoi(line);
    //TODO: remember to fix file read
    for (int i = 0; i <= cases; i++){
        getline(file, line);
        // split to numships (first)
        // split to distance (second)
        for (int j = 0; j <= numships; j++){
            getline(file, line);
            // split t1
            // split t2
            // split t3
            // readin for ship obj
        }
    }

}
