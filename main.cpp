#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Ship.h"

using namespace std;

bool outputToFile(int avbShips, fstream& os);

int main(int argc, const char* argv[]) {
    int cases; int numships, distance, t1, t2, t3, avbShips = 0; string line, testLine; bool debugOn = argv[1];
    int correctCount = 0;
    vector<Ship> ships;

    //create environment vars
    putenv("MYINPUT=textfiles/testinput_P1.txt"); //make sure to replace these with input.txt and output.txt before submitting assignment
    putenv("MYOUTPUT=textfiles/output.txt");
    putenv("TESTOUT=textfiles/testoutput_P1.txt");

    fstream inFile(getenv("MYINPUT")), outFile(getenv("MYOUTPUT")), testOutFile(getenv("TESTOUT"));

    getline(inFile, line);
    cases = stoi(line);

    if (inFile.is_open()) {
        for (int i = 0; i < cases; i++) {
            getline(inFile, line);
            // split to numships (first)
            numships = stoi(line.substr(0, line.find(' ')));
            // split to distance (second)
            distance = stoi(line.substr(line.find(' '), line.size() - 1));
            for (int j = 0; j < numships; j++) {
                getline(inFile, line);
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
                getline(testOutFile, testLine); // read first line of comparison file
                if (testOutFile.is_open()) {
                    if (atoi(argv[1]) == 1) { // test giving percentage success
                        if (stoi(testLine) == avbShips) {
                            correctCount++;
                        }
                    }
                    else if (atoi(argv[1]) == 2) {
                        if (stoi(testLine) != avbShips) { // test giving first erroneous calculation
                            cout << "First discrepancy found in case "
                            << ++correctCount << ". " << avbShips << " available ships "
                            << "were calculated, but " << testLine << " ships "
                            << "were available.\n";
                            return 1;
                        }
                        else {
                            correctCount++;
                        }
                    } // test that visualizes successes and errors
                    else {
                        stoi(testLine) == avbShips ? cout << '.' << endl : cout << "failure" << endl;
                    }
                }
            }
            else { // behavior when running normally
                //outputToFile(avbShips, )
                cout << avbShips << endl;
            }
            avbShips = 0;
        }

        if (debugOn) { // output for percent success debug option
            if (atoi(argv[1]) == 1) {
                cout << (float)(correctCount)/cases << "% success rate with "
                << correctCount << '/' << cases << " cases matching output.\n";
            }
            testOutFile.close();
        }

        inFile.close();
        unsetenv("MYINPUT"); //remove environment variables when exiting program
        unsetenv("MYOUTPUT");
        unsetenv("TESTOUT");

        return 0;
    }
    
}


bool outputToFile(int avbShips, fstream& os) { //untested framework for output to file
    if (os.is_open()) {
        os << avbShips << endl;
        return true;
    }
    return false;
}