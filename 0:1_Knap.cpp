#include <iostream>
using namespace std;

const int MAXN = 100;   // maximum number of items
const int MAXW = 1000;  // maximum weight of the knapsack

int N;                 // number of items
int W;                 // weight of the knapsack
int w[MAXN+1];         // weight of each item
int v[MAXN+1];         // value of each item
int best_value = 0;    // best value found so far
int curr_value = 0;    // current value being explored
int curr_weight = 0;   // current weight being explored

void backtrack(int i) {
    if (i == N) {
        // reached end of the list, check if we found a better solution
        if (curr_value > best_value) {
            best_value = curr_value;
        }
        return;
    }
    // explore including the ith item
    if (curr_weight + w[i] <= W) {
        curr_weight += w[i];
        curr_value += v[i];
        backtrack(i+1);
        curr_weight -= w[i];
        curr_value -= v[i];
    }
    // explore excluding the ith item
    backtrack(i+1);
}

int main() {
    // read input
    cout << "Enter the number of items: ";
    cin >> N;
    cout << "Enter the weight of the knapsack: ";
    cin >> W;
    cout << "Enter the weight and value of each item: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    // solve the problem using backtracking
    backtrack(0);
    // output the result
    cout << "The maximum value of the knapsack is: " << best_value << endl;
    return 0;
}