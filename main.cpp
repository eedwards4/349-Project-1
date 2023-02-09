#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Ship.h"

using namespace std;

int main(int argc, const char* argv[]) {
    int cases; int numships, distance, t1, t2, t3, avbShips = 0; string line, testLine; bool debugOn = argv[1];
    int correctCount = 0;
    vector<Ship> ships;
    fstream file("testinput_P1.txt");
    fstream testOutFile("testoutput_P1.txt");

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
            
            if (debugOn) {
                getline(testOutFile, testLine);
                if (testOutFile.is_open()) {
                    if (atoi(argv[1]) == 1) {
                        if (stoi(testLine) == avbShips) {
                            correctCount++;
                        }
                    }
                    else if (atoi(argv[1]) == 2) {
                        if (stoi(testLine) != avbShips) {
                            cout << "First discrepancy found in case "
                            << ++correctCount << ". " << avbShips << " available ships "
                            << "were calculated, but " << testLine << " ships "
                            << "were available.\n";
                            return 1;
                        }
                        else {
                            correctCount++;
                        }
                    }
                    else {
                        stoi(testLine) == avbShips ? cout << '.' << endl : cout << "failure" << endl;
                    }
                }
            }
            else {
                cout << avbShips << endl;
            }
            avbShips = 0;
        }

        if (debugOn) {
            if (atoi(argv[1]) == 1) {
                cout << (float)(correctCount)/cases << "% success rate with "
                << correctCount << '/' << cases << " cases matching output.\n";
            }
            testOutFile.close();
        }

        file.close();
        return 0;
    }
    
}
