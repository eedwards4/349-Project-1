#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Ship.h"

using namespace std;

int main(){
    int cases; int numships, distance, t1, t2, t3, avbShips = 0; string line;
    vector<Ship> ships;
    fstream file("test.txt");
    getline(file, line);
    cases = stoi(line);
    if (file.is_open()) {
        for (int i = 0; i < cases; i++) {
            getline(file, line);
            // split to numships (first)
            numships = stoi(line.substr(0, line.find(' ')));
            // split to distance (second)
            distance = stoi(line.substr(line.find(' '), line.size() - 1));
            for (int j = 0; j < numships; j++) {
                getline(file, line);
                t1 = stoi(line.substr(0, line.find(' '))); // split t1
                line.erase(0, line.find(' ') + 1);
                t2 = stoi(line.substr(0, line.find(' '))); // split t2
                line.erase(0, line.find(' ') + 1);
                t3 = stoi(line.substr(0, line.find(' '))); // split t3
                // readin for ship obj
                ships.emplace_back(t1, t2, t3);
            }
            for (Ship x : ships){
                avbShips += x.canTravel(distance);
            }
            cout << avbShips << endl;
            avbShips = 0;
        }
        file.close();
    }

}
