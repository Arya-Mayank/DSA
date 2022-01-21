template <typename T>
class Vector
{
private:
    T *arr; // pointer to point at new dynamic array
    int cs; // current size
    int ms; // maximum size

public:
    Vector(int max = 1)
    {
        cs = 0;
        ms = max;
        arr = new T[ms];
    }

    void push_back(T number)
    {
        if (cs == ms)
        {
            // create a new array, double the size of previous one
            T *oldArray = arr;
            ms *= 2;
            arr = new T[ms];

            //  copy all elements
            for (int i = 0; i < cs; i++)
            {
                arr[i] = oldArray[i];
            }
            //  delete previous array
            delete[] oldArray;
        }

        arr[cs] = number;
        cs++;
    }

    void pop_back()
    {
        if (cs >= 0)
        {
            cs--;
        }
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    T front()
    {
        return arr[0];
    }

    T back()
    {
        return arr[cs - 1];
    }

    T at(int i)
    {
        return arr[i];
    }

    int size()
    {
        return cs;
    }

    int capacity()
    {
        return ms;
    }

    T operator[](int i)
    {
        return arr[i];
    }
};
