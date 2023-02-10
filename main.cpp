/*
Joe Coon, Ethan Edwards
Ship Deployer Program
Project completion: 2/9/2023
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Ship.h"

using namespace std;

int main(int argc, const char* argv[]){
    // Define variables
    int cases, numships, distance, t1, t2, t3, avbShips = 0;
    string line, fname, debugf, outf;
    bool outToFile = false, debug = false, write = false;
    vector<Ship> ships;
    // Sanity check
    if (argc == 0) {cout << "This program requires 1 filename or filepath as an argument."; return 0;}
    // Begin file readin
    fname = argv[1];
    fstream file(fname);
    fstream debugFile;
    fstream outFile;

    if (argc == 3){outf = argv[2]; outFile.open(outf); outToFile = true;}

    if (fname == "debug"){ // Debug code. ONLY CALLED WHEN "debug" used as initial filename
        cout << "Enter name for file to check against:";
        cin >> debugf;
        cout << "Enter filename for file to test with:";
        cin >> fname;
        cout << "Enter filename for file to output to (use *** to skip):";
        cin >> outf;
        if (outf != "***"){outFile.open(outf); outToFile = true;}
        debugFile.open(debugf);
        file.open(fname);
        debug = true;
    }
    // End file info readin
    // File checks
    if (debug && !debugFile.is_open()){cout << "Debug file " << debugf << " not found. Please confirm that the file exists and is a .txt file." << endl; return 0;}
    if (outToFile &&  !outFile.is_open()){cout << "Output file " << outf << " not found. Please confirm that the file exists AND that you are sure you want to overwrite it's contents." << endl; return 0;}
    if (file.is_open()) {
        getline(file, line);
        cases = stoi(line);
        for (int i = 0; i < cases; i++) { // Loops per number of cases/scenarios
            getline(file, line);
            // split to numships (first)
            numships = stoi(line.substr(0, line.find(' ')));
            // split to distance (second)
            distance = stoi(line.substr(line.find(' '), line.size() - 1));
            for (int j = 0; j < numships; j++) { // Create our ship objects and place them into a vector
                getline(file, line);
                t1 = stoi(line.substr(0, line.find(' '))); // split t1
                line.erase(0, line.find(' ') + 1);
                t2 = stoi(line.substr(0, line.find(' '))); // split t2
                line.erase(0, line.find(' ') + 1);
                t3 = stoi(line.substr(0, line.find(' '))); // split t3
                // readin for ship obj
                ships.emplace_back(t1, t2, t3);
            }
            for (Ship x : ships){ // How many ships can actually make it?
                avbShips += x.canTravel(distance);
            }
            cout << avbShips << endl;
            // Send to file (if needed)
            if (outToFile && !write){
                cout << "Please confirm that you would like to write to " << outf << endl;
                cin >> line;
                if (line == "y" || line == "Y" || line == "yes" || line == "Yes"){write = true;}
            }
            if (write){outFile << avbShips << endl;}
            if (debug){getline(debugFile, line); if (stoi(line) != avbShips){cout << "WARN: " << stoi(line) << " != " << avbShips << endl;}} // Super mega debug line
            avbShips = 0; // Reset
            ships.clear();
        }
        file.close(); // Close stuff I guess
        if (outFile.is_open()){outFile.close();}
        if (debugFile.is_open()){debugFile.close();}
    }
}
