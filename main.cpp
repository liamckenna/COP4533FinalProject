#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include "Item.h"

using namespace std;

int InputCount();
Item* InputItem(int id);
int InputWeight();
int InputValue();
void InputOpt(vector<Item*> set);
int InputI(vector<Item*> itemSet);
int InputW();
int InputK();
pair<int, int***> OPT(int i, int w, int k, vector<Item*> itemSet, int*** &matrix);
set<Item*> Traceback(int i, int w, int k, vector<Item*> itemSet, int*** &matrix);

int main() {
    //Get size of input.
    int count = InputCount();

    //Get each individual item.
    vector<Item*> itemSet;
    for (int i = 0; i < count; i++) {
        cout << "Item " << (i + 1) << endl;
        Item* item = InputItem(i + 1);
        itemSet.push_back(item);
    }
    //Pass item set to OPT method.
    InputOpt(itemSet);
    return 0;
}

int InputCount() {
    //This method gets the total number of items the user will be inputting.
    cout << "How many items would you like to add to the set?" << endl;
    string input;
    cin >> input;
    //Input validation.
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

Item* InputItem(int id) {
    //This method gets an item and its respective weight/value.
    int weight = InputWeight();
    int value = InputValue();
    Item* item = new Item(weight, value, id);
    cout << "Inserting item "<< id <<  " of weight " << weight << " and value " << value << "." << endl;
    return item;
}

int InputWeight() {
    //This method gets the weight of an item.
    string inputWeight;
    cout << "Weight:";
    cin >> inputWeight;
    //Input validation.
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
    //This method gets the value of an item.
    string inputValue;
    cout << "Value:";
    cin >> inputValue;
    //Input validation.
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
    //This method gets input parameters for OPT, it also initializes the 3D matrix with that input.
    cout << "Enter 1 to perform Opt(i,w,k) function, and any other input to exit program." << endl;
    string option;
    cin >> option;
    if (option != "1")  {
        cout << "Goodbye!" << endl;
        return;
    }
    //Get parameters.
    cout << "Define first i items of size exactly k whose total weight is exactly w for OPT(i,w,k)." << endl;
    int i = InputI(itemSet);
    int w = InputW();
    int k = InputK();

    //Initialize 3D matrix.
    //cout << "initializing matrix now..." << endl;
    int*** matrix = new int**[i + 1];
    for (int a = 0; a <= i; a++) {
        matrix[a] = new int*[w + 1];
        for (int b = 0; b <= w; b++) {
            matrix[a][b] = new int[k + 1];
        }
    }
    //cout << "matrix is initialized." << endl;

    //Call OPT method.
    pair<int, int***> optimalValue = OPT(i, w, k, itemSet, matrix);

    if (optimalValue.first != -1) { //If there exists a result (-1 represents negative infinity)
        cout << "The maximum value of any subset contained within those parameters is..." << endl;
        cout << optimalValue.first << endl;
        cout << "Would you like to perform the traceback function? Enter 1 for yes, anything else for no." << endl;
        string tbInput;
        cin >> tbInput;
        if (tbInput == "1") { //Call traceback method.
            set <Item*> subset = Traceback(i, w, k, itemSet, optimalValue.second);
            if(subset.size() != 0) //Print result based on traceback's set size.
            {
                cout << "Optimal subset as ID (weight, value):" << endl;
                for (auto item: subset)
                {
                    cout << item->GetID() << " (" << item->GetWeight() << ", " << item->GetValue() << ") " << endl;
                }
            }else{
                cout << "Optimal subset is an empty set.";
            }
            cout << endl;
        } else {
            cout << "You have selected to not perform the traceback function for this solution." << endl;
        }
    } else {
        cout << "A solution does not exist." << endl;
    }
    InputOpt(itemSet); //Option to run again with different input for i, w, k.
}

int InputI(vector<Item*> itemSet) {
    //This method gets the number of items from itemSet that the OPT is allowed to use.
    cout << "Let i=";
    string i;
    cin >> i;
    //Input validation. i has to be 0 or a positive integer, as well as up to size of itemSet.
    try {
        if (stoi(i) < 0) throw i;
    } catch (string input) {
        cout << "That is an invalid i value. Please try again." << endl;
        return InputI(itemSet);
    } catch (exception invalid_argument) {
        cout << "That is an invalid i value. Please try again." << endl;
        return InputI(itemSet);
    }
    if(stoi(i) > itemSet.size()){
        cout << "i must be equal or less than set count. Please try again." << endl;
        return InputI(itemSet);
    }
    return stoi(i);
}

int InputW() {
    //This method gets the exact weight that OPT will be looking for.
    cout << "Let w=";
    string w;
    cin >> w;
    //Input validation.
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
    //This method gets the exact size of the result set that OPT must find.
    cout << "Let k=";
    string k;
    cin >> k;
    //Input validation.
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

pair<int, int***> OPT(int i, int w, int k, vector<Item*> itemSet, int*** &matrix) {
    // the OPT method follows the recursive function given in the pdf
    for (int a = 0; a <= i; a++) { // iterate through all values of first i items
        for (int b = 0; b <= w; b++) { // iterate through every exact total weight w
            for (int c = 0; c <= k; c++) { // iterate through all sets of size exactly k
                if (b == 0 && c == 0) { // w = 0 and k = 0
                    matrix[a][b][c] = 0; // 0
                } else if (a < c || (b > 0 && c == 0) || (b == 0 && c > 0)) { // (i < k) or (w > 0 and k = 0) or (w = 0 and k > 0)
                    matrix[a][b][c] = -1; // -1 (which represents negative infinity)
                } else if (itemSet[a-1]->GetWeight() > b) { // w(sub i) > w
                    matrix[a][b][c] = matrix[a-1][b][c]; // OPT(i-1,w,k)
                } else { // otherwise
                    int addedVal = -1; // initializing OPT(i-1,w-w(sub i),k-1) to -1 unless proven otherwise.
                    if (matrix[a-1][b-itemSet[a-1]->GetWeight()][c-1] != -1) { // so long as the OPT of adding the value doesn't lead to -1 (negative infinity)
                        addedVal = itemSet[a-1]->GetValue() + matrix[a-1][b-itemSet[a-1]->GetWeight()][c-1]; // then we can add the value
                    } // this if statement above ensures we are not adding value to -1 since even if -1 represents negative infinity, it does not function the same in operations, of course.
                    matrix[a][b][c] = max(matrix[a-1][b][c], addedVal); // max{OPT(i-1,w,k),v(sub i) + OPT(i-1,w-w(sub i),k-1)}
                }
            }
        }
    }
    pair<int, int***> optimalValue; // pair of optimal value and its corresponding 3D matrix
    optimalValue.first = matrix[i][w][k]; // result of OPT function
    optimalValue.second = matrix; // corresponding matrix
    return optimalValue; // return pair
}

set<Item*> Traceback(int i, int w, int k, vector<Item*> itemSet, int*** &matrix) {
    //This method performs the traceback and returns which items were used.
    int a = i, b = w, c = k;
    set<Item*> items;

    //Loop while still in bounds of matrix.
    while (a > 0 || b > 0 || c > 0) {
        if (matrix[a][b][c] == matrix[a-1][b][c]) { //If current value is the same as value above, item was not picked.
            a -= 1;
        } else { //Values are not the same, item was picked.
            items.insert(itemSet[a-1]);
            b -= itemSet[a-1]->GetWeight();
            a -= 1;
            c -= 1;
        }
    }
    return items;
}
