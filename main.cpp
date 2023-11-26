#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include "Item.h"
using namespace std;
int InputCount();
Item* InputItem();
int InputWeight();
int InputValue();
void InputOpt(vector<Item*> set);
int InputI();
int InputW();
int InputK();
set<Item*> Traceback(int i, int w, int k, pair<int, vector<vector<vector<int>>>> matrix);
pair<int, vector<vector<vector<int>>>> OPT(int i, int w, int k, vector<Item*> itemSet);
int main() {
    int count = InputCount();

    vector<Item*> itemSet;
    for (int i = 0; i < count; i++) {
        cout << "Item " << (i + 1) << endl;
        Item* item = InputItem();
        itemSet.push_back(item);
    }
    InputOpt(itemSet);
    return 0;
}

int InputCount() {
    cout << "How many items would you like to add to the set?" << endl;
    string input;
    cin >> input;
    try {
        if (stoi(input) <= 0) throw input;
    } catch (string input) {
        cout << "That is an invalid size. Please try again." << endl;
        return InputCount();
    } catch (exception invalid_argument) {
        cout << "That is an invalid size. Please try again." << endl;
        return InputCount();
    }
    return stoi(input);
}

Item* InputItem() {
    int weight = InputWeight();
    int value = InputValue();
    Item* item = new Item(weight, value);
    cout << "Inserting item of weight " << weight << " and value " << value << "." << endl;
    return item;
}

int InputWeight() {
    string inputWeight;
    cout << "Weight:";
    cin >> inputWeight;
    try {
        if (stoi(inputWeight) <= 0) throw inputWeight;
    } catch (string input) {
        cout << "That is an invalid weight. Please try again." << endl;
        return InputWeight();
    } catch (exception invalid_argument) {
        cout << "That is an invalid weight. Please try again." << endl;
        return InputWeight();
    }
    return stoi(inputWeight);
}

int InputValue() {
    string inputValue;
    cout << "Value:";
    cin >> inputValue;
    try {
        if (stoi(inputValue) <= 0) throw inputValue;
    } catch (string input) {
        cout << "That is an invalid value. Please try again." << endl;
        return InputValue();
    } catch (exception invalid_argument) {
        cout << "That is an invalid value. Please try again." << endl;
        return InputValue();
    }
    return stoi(inputValue);
}

void InputOpt(vector<Item*> itemSet) {
    cout << "Enter 1 to perform Opt(i,w,k) function, and any other input to exit program." << endl;
    string option;
    cin >> option;
    if (option != "1")  {
        cout << "Goodbye!" << endl;
        return;
    }
    cout << "Define first i items of size exactly k whose total weight is exactly w for OPT(i,w,k)." << endl;
    int i = InputI();
    int w = InputW();
    int k = InputK();
    pair<int, vector<vector<vector<int>>>> optimalValue = OPT(i, w, k, itemSet);
    if (optimalValue.first != NULL) {
        cout << "The maximum value of any subset contained within those parameters is..." << endl;
        cout << optimalValue.first << endl;
        cout << "Would you like to perform the traceback function? Enter 1 for yes, anything else for no." << endl;
        string tbInput;
        cin >> tbInput;
        if (tbInput == "1") {
            set <Item*> subset = Traceback(i, w, k, optimalValue);
            if (!subset.empty()) {//precaution?
                cout << "Optimal subset as (weight, value):" << endl;
                for (auto item:subset) {
                    cout << "(" << item->GetWeight() << ", " << item->GetValue() << ") ";
                }
                cout << endl;
            } else {
                cout << "A solution does not exist?" << endl;
            }
        } else {
            cout << "You have selected to not perform the traceback function for this solution." << endl;
        }
    } else {
        cout << "A solution does not exist." << endl;
    }
    InputOpt(itemSet);
}


int InputI() {
    cout << "Let i=";
    string i;
    cin >> i;
    try {
        if (stoi(i) < 0) throw i;
    } catch (string input) {
        cout << "That is an invalid i value. Please try again." << endl;
        return InputI();
    } catch (exception invalid_argument) {
        cout << "That is an invalid i value. Please try again." << endl;
        return InputI();
    }
    return stoi(i);
}
int InputW() {
    cout << "Let w=";
    string w;
    cin >> w;
    try {
        if (stoi(w) < 0) throw w;
    } catch (string input) {
        cout << "That is an invalid weight. Please try again." << endl;
        return InputW();
    } catch (exception invalid_argument) {
        cout << "That is an invalid weight. Please try again." << endl;
        return InputW();
    }
    return stoi(w);
}
int InputK() {
    cout << "Let k=";
    string k;
    cin >> k;
    try {
        if (stoi(k) < 0) throw k;
    } catch (string input) {
        cout << "That is an invalid size. Please try again." << endl;
        return InputK();
    } catch (exception invalid_argument) {
        cout << "That is an invalid size. Please try again." << endl;
        return InputK();
    }
    return stoi(k);
}

pair<int, vector<vector<vector<int>>>> OPT(int i, int w, int k, vector<Item*> itemSet) {
    //temp code, needs functionality
    
}

set<Item*> Traceback(int i, int w, int k, pair<int, vector<vector<vector<int>>>> matrix) {
    
}