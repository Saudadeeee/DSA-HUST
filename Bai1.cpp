#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortColors(vector<string>& colors) {
    vector<string> red, white, blue;

    // Separate the colors into three different vectors
    for (const string& color : colors) {
        if (color == "red") {
            red.push_back(color);
        } else if (color == "white") {
            white.push_back(color);
        } else if (color == "blue") {
            blue.push_back(color);
        }
    }

    // Combine back into the original array in the order: red -> white -> blue
    colors.clear();
    colors.insert(colors.end(), red.begin(), red.end());
    colors.insert(colors.end(), white.begin(), white.end());
    colors.insert(colors.end(), blue.begin(), blue.end());
}

int main() {
    vector<string> colors = {"blue", "red", "blue", "red", "red", "white", "red", "blue", "white"};

    sortColors(colors);

    cout << "Sorted colors: ";
    for (const string& color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}
