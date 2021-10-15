#pragma once
class Array {
private:
    int size;
    int** arr;
public:
    Array(int n)
    {
        size = n;
        arr = new int* [size];
        for (int i = 0; i < n; i++) 
        { 
            arr[i] = new int[size];
        }
    };
    Array()
    {
        size = 0;
        arr = nullptr;
    };
    Array(const Array& matrix) 
    {
        size = matrix.size;
        arr = new int*[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = new int[size];
        }
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                arr[i][j] = matrix.arr[i][j];
            }
        }
    };
    ~Array()
    {
        for (int i = 0; i < size; i++) 
        { 
           delete[]arr[i]; 
        }
        delete[]arr;
    };
    Array operator +(Array buf);
    Array& operator =(const Array buf);
    void addInfoInArr();
    void showArr();
};