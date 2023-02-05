//
// Created by student on 2/3/23.
//

#ifndef INC_349_PROJECT_1_SHIP_H
#define INC_349_PROJECT_1_SHIP_H


class Ship {
public:
    Ship();
    Ship(int, int, int);
    bool canTravel(int);
private:
    int speed, fuel, conRate; // T(top speed) Q(fuel) R(rate of consumption / hour)
};


#endif //INC_349_PROJECT_1_SHIP_H
