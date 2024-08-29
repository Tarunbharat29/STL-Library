
#include "template.cpp"
using namespace Tarun;
using namespace std;

int main() {


    // Linked List demonstration
    Linklist<float> l;
    cout << "Using linked list....." << endl;
    l.insert(10.2);
    l.insert(25.4);
    l.insert(38.6);
    cout << "Elements in list:" << endl;
    l.display();
    l.remove();
    cout << "Elements in list after removal:" << endl;
    l.display();

    // Queue demonstration
    Queue<int> q;
    cout << "Using Queue....." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Element dequeued: " << q.dequeue() << endl;

    // Stack demonstration
    Stack<char> s;
    cout << "Using Stack...." << endl;
    s.push('A');
    s.push('B');
    s.push('C');
    cout << "Element popped: " << s.pop() << endl;

    // Tree demonstration
    Tree<int> t;
    cout << "Using Tree....." << endl;
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    cout << "Elements in tree (in sorted order):" << endl;
    t.display();

    int searchElement = 40;
    cout << "Searching for element " << searchElement << " in tree: ";
    if (t.search(searchElement)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    vector<int> data2 = data; // Copies for different sorts

    cout << "Original array:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Testing Bubble Sort
    bubbleSort(data);
    cout << "Sorted array using Bubble Sort:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Resetting data for Insertion Sort
    data = data2;
    insertionSort(data);
    cout << "Sorted array using Insertion Sort:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Resetting data for Selection Sort
    data = data2;
    selectionSort(data);
    cout << "Sorted array using Selection Sort:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Resetting data for Quick Sort
    data = data2;
    quickSort(data, 0, data.size() - 1);
    cout << "Sorted array using Quick Sort:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Resetting data for Merge Sort
    data = data2;
    mergeSort(data);
    cout << "Sorted array using Merge Sort:" << endl;
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;

    // Searching tests
    int target = 22;
    int result = linearSearch(data, target);
    cout << "Linear Search: Element " << target << (result != -1 ? " found at index " : " not found") << result << endl;

    result = binarySearch(data, target);
    cout << "Binary Search: Element " << target << (result != -1 ? " found at index " : " not found") << result << endl;


    return 0;
}
