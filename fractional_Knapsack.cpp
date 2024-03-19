#include <iostream>
#include <algorithm>
using namespace std;
struct product {
    int value;
    int weight;
};
bool compare_product(product p1, product p2) {
    return (double)p1.value / p1.weight > (double)p2.value / p2.weight;
}
double fractional_Knapsack(int W, product arr[], int number) {
    std::sort(arr, arr + number, compare_product);
    double total = 0.0;
    int current_Weight = 0;
    for (int i = 0; i < number; i++) {
        if (current_Weight + arr[i].weight <= W) {
            current_Weight += arr[i].weight;
            total += arr[i].value;
        } else {
            int remain = W - current_Weight;
            double fraction = (double)remain / arr[i].weight;
            current_Weight += remain;
            total += fraction * arr[i].value;
            break;
        }
    }
    return total;
}
int main() {
    int W = 50;
    product arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int number = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible value = " << fractional_Knapsack(W, arr, number) <<endl;

    return 0;
}
