/*
Joe Coon, Ethan Edwards
Ship Deployer Program
Project completion: 2/9/2023
 */

#include "Ship.h"

Ship::Ship() {
    speed = 0;
    fuel = 0;
    conRate = 0;
}

Ship::Ship(int newSpeed, int newFuel, int newRate) {
    speed = newSpeed;
    fuel = newFuel;
    conRate = newRate;
}

bool Ship::canTravel(int distance) {
    return ((float)(fuel * speed) / conRate) >= distance; //can we reach the distance with our speed and fuel left?
}