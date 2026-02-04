#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<float> speeds = {1.5, 5.5, 0.5, 3.2};

    sort(speeds.begin(), speeds.end(), [](float a, float b) {
        return a > b;
    });

    for (float s : speeds)
        cout << s << " ";
}
