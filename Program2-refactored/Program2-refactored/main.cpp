//
//  paintHouse_refactored.cpp
//  Program2
//
//  Created by McKenzie Humann on 9/4/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "PaintType.h"

using namespace std;

// function declarations
int areaCalculation(int numWalls);
void getInput(int *paintOption, int *numWalls);

int main() {
    const double canCoverage = 400.0;
    double numCansDoub;
    int numCansInt;
    int paintOption;
    int numWalls;
    int totalArea;
    int totalCost = 0;

    // Get user input on type of paint job and number of walls to be painted
    getInput(&paintOption, &numWalls);
    
    // Get height/length of walls to calculate area to be painted
    totalArea = areaCalculation(numWalls);
    // if painting exterior and interior of each wall, totalArea is doubled
    if (paintOption == 3) {
        totalArea = 2 * totalArea;
    }
    
    // calculate number of paint cans needed
    numCansDoub = (totalArea / canCoverage);
    numCansInt = ceil(numCansDoub);
    
    // print number of cans
    cout << "As each can covers " << canCoverage << " feet" << endl;
    cout << "With area = " << totalArea << " square feet, you will need to get ";
    cout <<  numCansDoub << endl;
    cout << "So in total we need " << numCansInt << " cans" << endl;

    PaintType UserHouse;

    if (paintOption == 1) {
        UserHouse.SetType("interior");
        UserHouse.SetPaintCost(100);
        totalCost = UserHouse.CalcCost(numCansInt);
    }
    
    else if (paintOption == 2) {
        UserHouse.SetType("exterior");
        UserHouse.SetPaintCost(150);
        totalCost = UserHouse.CalcCost(numCansInt);
    }
    
    else if (paintOption == 3) {
        UserHouse.SetType("interior and exterior");
        UserHouse.SetPaintCost(125);
        totalCost = UserHouse.CalcCost(numCansInt);
    }
    
    cout << "Now lets calculate the cost to paint the " << UserHouse.GetType() << " of the house" << endl;
    cout << "The price of the can is $" << UserHouse.GetPaintCost();
    if (paintOption == 3) {
        cout << " on average for interior and exterior paint";
    }
    cout << endl;
    cout << "The total cost is $" << totalCost << endl;
    
    return 0;
}

void getInput(int *paintOption, int *numWalls) {
    // welcome greeting
    cout << "Welcome to paint shop" << endl;
    cout << "We have a couple of options that you can choose from:" << endl;
    cout << "1- Paint the interior of a house" << endl;
    cout << "2- Paint the exterior of a house" << endl;
    cout << "3- Paint both interior and exterior of a house" << endl;

    cout << "What option fits you best?" << endl;
    cin >> *paintOption;
    
    // validate input
    while (*paintOption != 1 && *paintOption != 2 && *paintOption != 3) {
        cout << "Please input a valid number" << endl;
        cin >> *paintOption;
    }
    
    cout << "Now, how many walls do you want to paint?" << endl;
    cin >> *numWalls;
}


int areaCalculation(int numWalls) {
    int wallLength;
    int wallHeight;
    int area;
    int totalArea = 0;
    
    // get length and height for each wall
    for (int i=0; i < numWalls; i++) {
        cout << "What is the length and height for wall " << i+1 << endl;
        cout << "Length: " << endl;
        cin >> wallLength;
        cout << "Height: " << endl;
        cin >> wallHeight;
        
        // calculate area for each wall and add to total area
        area = wallLength * wallHeight;
        totalArea += area;
    }
    return totalArea;
}
