#include <iostream>
#include <vector>

using namespace std;

namespace Tarun {

    // Node class template used by multiple data structures
    template<typename T>
    class Node {
    private:
        T data;
        Node<T>* next;

        // Added left and right pointers for Tree structure
        Node<T>* left;
        Node<T>* right;

    public:
        Node(T data) : data(data), next(nullptr), left(nullptr), right(nullptr) {}

        // Allow these classes to access private members of Node
        template<typename U>
        friend class Linklist;
        template<typename U>
        friend class Queue;
        template<typename U>
        friend class Stack;
        template<typename U>
        friend class Tree;
    };

    // Linked list class template
    template<typename T>
    class Linklist {
    private:
        Node<T>* head;

    public:
        Linklist() : head(nullptr) {}

        void insert(T num) {
            Node<T>* newNode = new Node<T>(num);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node<T>* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void remove() {
            if (head == nullptr) {
                cout << "LIST IS EMPTY" << endl;
                return;
            } else if (head->next == nullptr) {
                head = nullptr;
                return;
            } else {
                Node<T>* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
        }

        void display() {
            Node<T>* temp = head;
            while (temp) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
    };

    // Queue class template
    template<typename T>
    class Queue {
    private:
        Node<T>* rear;
        Node<T>* front;

    public:
        Queue() : rear(nullptr), front(nullptr) {}

        void enqueue(T num) {
            Node<T>* newNode = new Node<T>(num);
            if (rear == nullptr) {
                rear = newNode;
                front = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        T dequeue() {
            if (front == nullptr) {
                cout << "Queue is empty!" << endl;
                return -1; // This is a sentinel value, replace as necessary
            } else {
                T ans = front->data;
                Node<T>* temp = front;
                front = front->next;
                if (front == nullptr) {
                    rear = nullptr;
                }
                delete temp;
                return ans;
            }
        }
    };

    // Stack class template
    template<typename T>
    class Stack {
    private:
        Node<T>* top;

    public:
        Stack() : top(nullptr) {}

        void push(T num) {
            Node<T>* newNode = new Node<T>(num);
            newNode->next = top;
            top = newNode;
        }

        T pop() {
            if (top == nullptr) {
                cout << "Stack is empty!" << endl;
                return -1; // This is a sentinel value, replace as necessary
            } else {
                Node<T>* temp = top;
                T data = temp->data;
                top = top->next;
                delete temp;
                return data;
            }
        }
    };

    // Tree class template for Binary Search Tree (BST)
    template<typename T>
    class Tree {
    private:
        Node<T>* root;

        // Helper function to insert a new node into the BST
        Node<T>* insertNode(Node<T>* node, T value) {
            if (node == nullptr) {
                return new Node<T>(value);
            }
            if (value < node->data) {
                node->left = insertNode(node->left, value);
            } else {
                node->right = insertNode(node->right, value);
            }
            return node;
        }

        // Helper function to perform in-order traversal
        void inOrderTraversal(Node<T>* node) {
            if (node != nullptr) {
                inOrderTraversal(node->left);
                cout << node->data << " ";
                inOrderTraversal(node->right);
            }
        }

        // Helper function to search for a value in the BST
        bool searchNode(Node<T>* node, T value) {
            if (node == nullptr) {
                return false;
            }
            if (node->data == value) {
                return true;
            }
            if (value < node->data) {
                return searchNode(node->left, value);
            } else {
                return searchNode(node->right, value);
            }
        }

    public:
        Tree() : root(nullptr) {}

        void insert(T value) {
            root = insertNode(root, value);
        }

        void display() {
            cout << "Tree elements in sorted order: ";
            inOrderTraversal(root);
            cout << endl;
        }

        bool search(T value) {
            return searchNode(root, value);
        }
    };



    //// Searching namespace with different searching algorithms


    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSortUtil(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSortUtil(arr, left, mid);
            mergeSortUtil(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void mergeSort(vector<int>& arr) {
        mergeSortUtil(arr, 0, arr.size() - 1);
    }



    // Searching namespace with different searching algorithms


    int linearSearch(const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int binarySearchUtil(const vector<int>& arr, int left, int right, int target) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
                return mid;
            if (arr[mid] > target)
                return binarySearchUtil(arr, left, mid - 1, target);
            return binarySearchUtil(arr, mid + 1, right, target);
        }
        return -1;
    }

    int binarySearch(const vector<int>& arr, int target) {
        return binarySearchUtil(arr, 0, arr.size() - 1, target);
    }

}




