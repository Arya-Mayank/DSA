
#include <bits/stdc++.h>

using namespace std;

class Heap
{
    vector<int> v;
    string type = "min";

    void heapify(int i, string type)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int minIdx = i;

        if (type == "min")
        {
            if (left < v.size() and v[left] < v[i])
            {
                minIdx = left;
            }
            if (right < v.size() and v[right] < v[left])
            {
                minIdx = right;
            }
        }
        else
        {
            if (left < v.size() and v[left] > v[i])
            {
                minIdx = left;
            }
            if (right < v.size() and v[right] > v[left])
            {
                minIdx = right;
            }
        }

        if (minIdx != i)
        {
            swap(v[i], v[minIdx]);
            heapify(minIdx, type);
        }
    }

public:
    // min heap
    Heap(string type = "min", int default_size = 10)
    {
        this->type = type;
        // reserve default_size +1 because 0th index is  not gonna be used
        v.reserve(default_size + 1);
        // 0th index blocked
        v.push_back(-1);
    }

    void push(int data)
    {
        v.push_back(data);

        int idx = v.size() - 1;
        int parent = idx / 2;

        if (type == "min")
        {
            while (idx > 1 and v[idx] < v[parent])
            {
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }
        else
        {
            while (idx > 1 and v[idx] > v[parent])
            {
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }
    }

    int min()
    {
        return v[1];
    }

    void pop()
    {
        // remove min/max element

        // swap first and last element, pop last
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        v.pop_back();

        heapify(1, type);
    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

    int maxProduct(){
        int last = v.size() - 1;
        int secondLast = last-1;

        return (v[last]-1) * (v[secondLast]-1);
    }
};