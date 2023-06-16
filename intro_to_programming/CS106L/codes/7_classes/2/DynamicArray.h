#include <iostream>
using std::cout;
using std::endl;
class DynamicArray {
    public:
        // TODO: Define your methods
        DynamicArray(int s):size(s), data(new int[size]) {
            
        }
        
        void setSquaredIndices() {
            for (int i = 0; i < size; i++) {
                data[i] = i*i;
            }
        }
        
        void displayElements() {
            cout << "Array elements:";
            for (int i = 0; i < size; i++) {
                cout << " " << data[i];
            }
            cout << endl;
        }
        
        ~DynamicArray() {
            delete[] data;
        }
        
    private:
        // TODO: Define your private member variables
        int* data;
        int size;
};

