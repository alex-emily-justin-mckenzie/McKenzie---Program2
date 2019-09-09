//
//  main.cpp
//  Program2
//
//  Created by McKenzie Humann on 9/4/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int paintOption;
    int numWalls;
    int totalArea = 0;
    int area;
    const double canCoverage = 400.0;
    int numCans;
    int totalCost;
    
    // welcome greeting
    cout << "Welcome to paint shop" << endl;
    cout << "We have a couple of options that you can choose from:" << endl;
    cout << "1- Paint the interior of a house" << endl;
    cout << "2- Paint the exterior of a house" << endl;
    cout << "3- Paint both interior and exterior of a house" << endl;
    cout << "What option fits you best?" << endl;
    
    cin >> paintOption;
    // validate input
    while (paintOption != 1 && paintOption != 2 && paintOption != 3) {
        cout << "Please input a valid number" << endl;
        cin >> paintOption;
    }
    
    cout << "Now, how many walls do you want to paint?" << endl;
    cin >> numWalls;
    
    // create vectors with number of elements equal to number of walls
    vector<int> wallLength(numWalls);
    vector<int> wallHeight(numWalls);
    
    // get length and height for each wall
    for (int i=0; i < wallLength.size(); i++) {
        cout << "What is the length and height for wall " << i+1 << endl;
        cout << "Length: " << endl;
        cin >> wallLength.at(i);
        cout << "Height: " << endl;
        cin >> wallHeight.at(i);
        
        // calculate area for each wall and add to total area
        area = wallLength.at(i) * wallHeight.at(i);
        totalArea += area;
    }
    
    if (paintOption == 1 || paintOption == 2) {
        numCans = ceil(totalArea / canCoverage);
    }
    else {
        numCans = 2 * ceil(totalArea / canCoverage);
    }
    
    cout << "As each can covers 400 feet" << endl;
    cout << "With area = " << totalArea << " square feet, you will need to get ";
    cout << (totalArea / canCoverage) << endl;
    cout << "So in total we need " << numCans << " cans" << endl;
    
    if (paintOption == 1) {
        totalCost = numCans * 100;
        cout << "Now lets calculate the cost to paint the interior of the house" << endl;
        cout << "The price of the can is $100" << endl;
        cout << "The total cost is $" << totalCost << endl;
    }
    else if (paintOption == 2) {
        totalCost = numCans * 150;
        cout << "Now lets calculate the cost to paint the exterior of the house" << endl;
        cout << "The price of the can is $150" << endl;
        cout << "The total cost is $" << totalCost << endl;
    }
    else if (paintOption == 3) {
        totalCost = ((numCans / 2) * 100);
        cout << "Now lets calculate the cost to paint the interior of the house" << endl;
        cout << "The price of the can is $100" << endl;
        cout << "The total cost is $" << totalCost << endl;
        totalCost =  ((numCans / 2) * 150);
        cout << "Now lets calculate the cost to paint the exterior of the house" << endl;
        cout << "The price of the can is $150" << endl;
        cout << "The total cost is $" << totalCost << endl;
    }

    return 0;
}
