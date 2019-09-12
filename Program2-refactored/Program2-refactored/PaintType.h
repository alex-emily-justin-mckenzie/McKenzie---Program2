//
//  paintType.cpp
//  Program2-refactored
//
//  Created by McKenzie Humann on 9/11/19.
//  Copyright © 2019 McKenzie Humann. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class PaintType {
private:
    int totalCost;
    string type;
    int paintCost;
public:
    void SetPaintCost(int cost);
    void SetType(string paintType);
    int GetPaintCost();
    string GetType();
    int CalcCost(int numCans);
};

void PaintType::SetPaintCost(int cost) {
    paintCost = cost;
}

void PaintType::SetType(string paintType){
    type = paintType;
}

int PaintType:: GetPaintCost() {
    return paintCost;
}

string PaintType:: GetType() {
    return type;
}

int PaintType::CalcCost(int numCans) {
    totalCost = numCans * paintCost;
    return totalCost;
}
