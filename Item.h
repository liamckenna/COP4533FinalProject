#pragma once
class Item {
    int weight;
    float value;
public:
    Item(int w, float v) {
        weight = w;
        value = v;
    }
    int GetWeight() { return weight;}
    float GetValue() { return value;}
};