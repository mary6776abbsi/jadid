#include <iostream>
#include <vector>
#include <algorithm> // For using sorting functions

using namespace std;

// Function to get an array of unspecified size from the user
vector<int> inputArray() {
    vector<int> arr;
    int num;
    cout << "Enter array elements (Enter -1 to stop): ";
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        arr.push_back(num);
    }
    return arr;
}

// Function to print the array
void printArray(const vector<int>& arr) {
    cout << "Array elements: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find the maximum element in the array
int findMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// Function to find the minimum element in the array
int findMin(const vector<int>& arr) {
    return *min_element(arr.begin(), arr.end());
}

// Function to calculate the sum of elements in the array
int calculateSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

// Function to calculate the average of elements in the array
double calculateAverage(const vector<int>& arr) {
    int sum = calculateSum(arr);
    return static_cast<double>(sum) / arr.size();
}

// Function to sort the array and store it in another array
vector<int> sortArray(const vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    return sortedArr;
}

// Function to search for a value in the array and return its index
int searchValue(const vector<int>& arr, int value) {
    auto it = find(arr.begin(), arr.end(), value);
    if (it != arr.end()) {
        return distance(arr.begin(), it); // Calculating the index using iterators
    }
    else {
        return -1; // Value not found
    }
}

int main() {
    // Getting the array from the user
    vector<int> arr = inputArray();

    // Printing the array
    printArray(arr);

    // Finding the maximum and minimum elements in the array
    cout << "Maximum element: " << findMax(arr) << endl;
    cout << "Minimum element: " << findMin(arr) << endl;

    // Calculating the sum and average of elements
    cout << "Sum of elements: " << calculateSum(arr) << endl;
    cout << "Average of elements: " << calculateAverage(arr) << endl;

    // Sorting the array and printing the sorted array
    vector<int> sortedArr = sortArray(arr);
    cout << "Sorted array: ";
    printArray(sortedArr);

    // Searching for a value in the array
    int valueToSearch;
    cout << "Enter a value to search in the array: ";
    cin >> valueToSearch;
    int index = searchValue(arr, valueToSearch);
    if (index != -1) {
        cout << "Value found at index: " << index << endl;
    }
    else {
        cout << "Value not found in the array." << endl;
    }

    return 0;
}
