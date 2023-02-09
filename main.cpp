#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Ship.h"

using namespace std;

int main(int argc, const char* argv[]){
    int cases; int numships, distance, t1, t2, t3, avbShips = 0; string line, fname, debugf; bool debug = false;
    vector<Ship> ships;
    if (argc == 0) {cout << "This program requires 1 filename or filepath as an argument."; return 0;}
    fname = argv[1];
    if (fname == "debug"){ // Debug code. ONLY CALLED WHEN "debug" used as initial filename
        cout << "Enter name for file to check against:";
        cin >> debugf;
        cout << "Enter filename for file to test with:";
        cin >> fname;
        debug = true;
    }
    fstream file(fname);
    fstream debugFile;
    if (debug){debugFile.open(debugf);} // Debug statement
    if (file.is_open()) {
        getline(file, line);
        cases = stoi(line);
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
            if (debug){getline(debugFile, line); if (stoi(line) != avbShips){cout << "WARN: " << stoi(line) << " != " << avbShips << endl;}}
            avbShips = 0;
            ships.clear();
        }
        file.close();
    }
}
