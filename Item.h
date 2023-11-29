#pragma once
class Item {
    int id;
    int weight;
    int value;
public:
    Item(int w, int v, int id) {
        weight = w;
        value = v;
        this->id = id;
    }
    int GetWeight() { return weight;}
    int GetValue() { return value;}
    int GetID() { return id;}
};