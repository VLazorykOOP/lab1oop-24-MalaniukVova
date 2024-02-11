#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <unordered_map>
#include <limits>
#include <time.h>

using namespace std;

int findIndex(const vector<int>& arr, int T1, int T2) {
    int minElement = INT_MAX;
    int minIndex = -1;

    bool foundT2 = false;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > T1) {
            if (foundT2 && arr[i] < minElement) {
                minElement = arr[i];
                minIndex = i;
            }
        }
        if (arr[i] == T2) {
            foundT2 = true;
        }
    }

    return minIndex;
}

int findMaxUnique(const vector<int>& A) {
    unordered_map<int, int> frequency;


    for (int num : A) {
        frequency[num]++;
    }

    int maxUnique = numeric_limits<int>::min();


    for (const auto& pair : frequency) {
        if (pair.second == 1 && pair.first > maxUnique) {
            maxUnique = pair.first;
        }
    }

    return maxUnique;
}

auto Task1()
{
    int N;


    cout << "Vvedit rozmir masivu: ";
    cin >> N;


    cout << "Vvedit rozmir masivu A:" << endl;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }


    cout << "Vvedit rozmir masivu B:" << endl;
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] > 0) {

            A[i] = B[i];
        }
    }

    cout << "Zmineniyu masiv A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

}
auto Task2()
{
    vector<int> arr = { 10, 5, 8, 12, 7, 15, 3, 20 };
    int T1 = 7;
    int T2 = 15;

    int result = findIndex(arr, T1, T2);

    if (result != -1) {
        cout << "Nomer pershoho minimalnoho elementa: " << result << endl;
    }
    else {
        cout << "Minimal'nyy element ne znaydeno." << endl;
    }
}
auto Task3()
{
    int n;
    cout << "Vvedit rozmir masivu: ";
    cin >> n;

    if (n <= 0 || n > 400) {
        cout << "Nepravilʹnyy rozmir masyvu. Rozmir masyvu povynen buty v mezah vid 1 do 400." << endl;
        return 1;
    }

    vector<int> A(n);
    cout << "Vvedit elementu masivu:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int maxUnique = findMaxUnique(A);

    if (maxUnique != numeric_limits<int>::min()) {
        cout << "Max unikalnix chisel: " << maxUnique << endl;
    }
    else {
        cout << "Unicalnix chisel nemaye." << endl;
    }
}

int main()
{
    int x;
    cout << "Choose Task!" << endl;
    cout << "1.Task1" << "\n";
    cout << "2.Task2" << "\n";
    cout << "3.Task3" << "\n";
    cout << "4.Exit!" << "\n";

    cin >> x;

    switch (x) {
    case 1:
        Task1();
        break;

    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        cout << "Well goodbye!" << endl;
        break;

    }

}