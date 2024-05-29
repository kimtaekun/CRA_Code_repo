#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define interface struct

interface SortMethod
{
	virtual void sort(std::vector<int>& dest) = 0;
};

class bubbleSort : public SortMethod {
	// SortMethod을(를) 통해 상속됨
    void sort(std::vector<int>& dest) override
	{
        std::cout << "Run bubbleSort..." << std::endl;
        int n = dest.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (dest[j] > dest[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    std::swap(dest[j], dest[j + 1]);
                }
            }
        }
	}
};
class selectionSort : public SortMethod {
	// SortMethod을(를) 통해 상속됨
    void sort(std::vector<int>& dest) override
	{
        std::cout << "Run selectionSort..." << std::endl;
        int n = dest.size();
        for (int i = 0; i < n - 1; ++i) {
            // Find the minimum element in the unsorted part of the array
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (dest[j] < dest[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element of the unsorted part
            std::swap(dest[i], dest[minIndex]);
        }
	}
};

class SortPrinter {
private:
    std::vector<int> sort_target;
    SortMethod* sort_method;
public:
    void insert(int item) {
        sort_target.push_back(item);
    }
    void select(std::string method) {
        if (method == "bubble") sort_method = new bubbleSort();
        if (method == "selection") sort_method = new selectionSort();
    }
    void run() {
        sort_method->sort(sort_target);
    }
    void show() {
        std::cout << "current List : ";
        for (int item : sort_target) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SortPrinter sortmachine;
    sortmachine.insert(-5);
    sortmachine.insert(-9);
    sortmachine.insert(-12);
    sortmachine.insert(-3);
    sortmachine.insert(-1);
    sortmachine.insert(0);
    sortmachine.insert(99);
    sortmachine.insert(7);
    sortmachine.insert(3);
    sortmachine.insert(1);
    sortmachine.insert(6);

    sortmachine.show();

    sortmachine.select("bubble");
    sortmachine.run();

    sortmachine.show();
}