/*
Joe Coon, Ethan Edwards
Ship Deployer Program
Project completion: 2/9/2023
 */

#include "Ship.h"

Ship::Ship() { // Default constructor
    speed = 0;
    fuel = 0;
    conRate = 0;
}

Ship::Ship(int newSpeed, int newFuel, int newRate) { // THIS SHOULD ALWAYS BE USED
    speed = newSpeed;
    fuel = newFuel;
    conRate = newRate;
}

bool Ship::canTravel(int distance) {
    return ((float)(fuel * speed) / conRate) >= distance; //can we reach the distance with our speed and fuel left?
}