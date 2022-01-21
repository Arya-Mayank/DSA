#include <bits/stdc++.h>

using namespace std;

class Car
{
public:
    // data members
    string id;
    int x, y;

    // parameterized constructor
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int distance() const
    {
        return x * x + y*y;
    }
};

class CarCompare
{
public:
    bool operator()(const Car A, const Car B)const
    {
        return A.distance() < B.distance();
    }
};

void printNearbyCars(vector<Car> cars, int k)
{
    // initialise priority_queue with k cars
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

    // insert rest cars by comparing top of priority queue
    for(int i=k;i<cars.size();i++){ 
        auto car = cars[i];

        if(car.distance() < max_heap.top().distance()){
            max_heap.pop();
            max_heap.push(car);
        }
    }

    // now we have PQ of k elements with the least distances
    // arranged in max heap format

    vector<Car> output;
    while(!max_heap.empty()){
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    // reverse to get increasing order
    reverse(output.begin(), output.end());

    for(auto car: output){
        cout << car.id << endl;
    }
}

int main()
{
    int N, k;
    cin >> N >> k;

    string id;
    int x, y;

    vector<Car> cars;

    for (int i = 0; i < N; i++)
    {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }

    printNearbyCars(cars, 3);

    // input
// 5 3
// C1 1 1
// C2 2 1
// C3 3 2
// C4 0 1
// C5 2 3

    return 0;
}