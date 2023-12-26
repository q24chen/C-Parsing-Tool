#include <iostream>
#include <vector>
#include <map>
#include <string>


struct Person {
    std::string name;
    int age;
};

class Rectangle {
    public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const { return width * height; }

    private:
    double width, height;
};

// Function declarations
void printNumber(int number);
bool isEven(int number);
void displayVector(const std::vector<int>& vec);
int findMaxInMap(const std::map<std::string, int>& myMap);
void printPersonInfo(const Person& person);
double calculateArea(const Rectangle& rect);
int Default();

int main() {

    printNumber(5);
    std::cout << "Is 4 even? " << (isEven(4) ? "Yes" : "No") << std::endl;

    std::vector<int> vec = {1, 2, 3};
    displayVector(vec);

    std::map<std::string, int> myMap = {{"Alice", 5}, {"Bob", 10}};
    std::cout << "Max in map: " << findMaxInMap(myMap) << std::endl;

    Person person = {"John", 30};
    printPersonInfo(person);

    Rectangle rect(3.0, 4.0);
    std::cout << "Area of rectangle: " << calculateArea(rect) << std::endl;

    return 0;
}

// Function implementations
void printNumber(int number) {
    std::cout << "Number: " << number << std::endl;
}

bool isEven(int number) {
    return number % 2 == 0;
}

void displayVector(const std::vector<int>& vec) {
    std::cout << "Vector elements: ";
    for (int num : vec) {
    std::cout << num << " ";
    }
    std::cout << std::endl;
}

int findMaxInMap(const std::map<std::string, int>& myMap) {
    int maxVal = INT_MIN;
    for (const auto& pair : myMap) {
        if (pair.second > maxVal) {
            maxVal = pair.second;
        }
    }
    return maxVal;
}

void printPersonInfo(const Person& person) {
    std::cout << "Person Name: " << person.name << ", Age: " << person.age << std::endl;
}

double calculateArea(const Rectangle& rect) {
    return rect.area();
}