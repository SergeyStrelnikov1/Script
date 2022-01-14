#include <iostream>

using namespace std;

struct human {
    string surname;
    string name;
    int age = 0;
};

bool modeQuicksortСomparison(human& a, human& b, string mode = "") {
    if (mode == "surname") {
        return a.surname < b.surname;
    }
    else if (mode == "name") {
        return a.name < b.name;
    }
    else if (mode == "arr") {
        return a.age < b.age;
    }
    return false;
}

template <typename T>
bool modeQuicksortСomparison(T a, T b, string mode = "") {
    if (mode != "") {
        return false;
    }
    return a < b;
}

template <typename T>
void swapPlaces(T& a, T& b) {
    T tt = a;
    a = b;
    b = tt;
}

template <typename T>
void quicksort(T* arr, int maxi, string mode = "") {
    T mid;

    int first = 0;
    int last = maxi - 1;
    mid = arr[maxi / 2];

    while (last >= first) {
        while (modeQuicksortСomparison(arr[first], mid, mode)) {
            first++;
        }

        while (modeQuicksortСomparison(arr[last], mid, mode)) {
            last--;
        }

        if (last >= first) {
            swapPlaces(arr[last], arr[first]);

            first++;
            last--;
        }
    }

    if (last > 0) {
        quicksort(arr, last + 1, mode);
    }

    if (first < maxi) {
        quicksort(&arr[first], maxi - first, mode);
    }
}

template <typename T>
void print(T* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

ostream& operator<<(ostream& o, const human& humans) {
    return o << humans.surname << " " << humans.name << " " << humans.age << endl;
}

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

double getRandomNumberDouble(double fMin, double fMax) {
    return fMin + (double)rand() / RAND_MAX * (fMax - fMin);
}

int main() {
    string sortMode;
    int humanSize;

    cout << "Human Size: " << endl;
    cin >> humanSize;

    human* humanArr = new human[humanSize];

    cout << "Item (surname name age): " << endl;
    for (int i = 0; i < humanSize; i++) {
        cin >> humanArr[i].surname >> humanArr[i].name >> humanArr[i].age;
    }
    cout << endl;

    while (true) {
        cout << "sort surname, name or age" << endl;
        cout << "Break: break" << endl;

        cin >> sortMode;

        if (sortMode == "break") {
            break;
        }

        cout << "No sort: " << endl;
        print(humanArr, humanSize);
        cout << endl;

        quicksort(humanArr, humanSize, sortMode);

        cout << "Sort: " << endl;
        print(humanArr, humanSize);
        cout << endl;
    }

    delete[] humanArr;

    int arrSize;

    cout << "Arr size: " << endl;
    cin >> arrSize;

    int* intArr = new int[arrSize];
    char* chrArr = new char[arrSize];
    double* doubleArr = new double[arrSize];

    for (int i = 0; i < arrSize; i++) {
        intArr[i] = getRandomNumber(0, 255);
        chrArr[i] = char(getRandomNumber(33, 126));
        doubleArr[i] = getRandomNumberDouble(0, 255.0);
    }

    cout << "No sort: " << endl;
    cout << "Int: ";
    print(intArr, arrSize);

    cout << "Char: ";
    print(chrArr, arrSize);

    cout << "Double: ";
    print(doubleArr, arrSize);

    quicksort(intArr, arrSize - 1);
    quicksort(chrArr, arrSize - 1);
    quicksort(doubleArr, arrSize - 1);
    cout << endl;

    cout << "Sort: " << endl;
    cout << "Int: ";
    print(intArr, arrSize);

    cout << "Char: ";
    print(chrArr, arrSize);

    cout << "Double: ";
    print(doubleArr, arrSize);

    delete[] intArr;
    delete[] chrArr;
    delete[] doubleArr;
}