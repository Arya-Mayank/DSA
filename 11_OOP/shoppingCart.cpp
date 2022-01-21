#include <iostream>

using namespace std;

class Product
{

private:
    int id;
    string name;
    int mrp;
    int sellingPrice;

public:
    // default constructor
    Product()
    {
        mrp = 0;
        sellingPrice = 0;
        name = "";
        id = -1;
    }

    // parameterized constructor
    Product(int id, int mrp, int sellingPrice, string name)
    {
        this->id = id;
        this->mrp = mrp;
        this->sellingPrice = sellingPrice;
        this->name = name;
    }

    // copy constructor
    Product(Product &X)
    {
        id = X.id;
        name = X.name;
        mrp = X.mrp;
        sellingPrice = X.sellingPrice;
    }

    // setter
    void setMRP(int price)
    {
        mrp = price;
    }

    void setSellingPrice(int price)
    {
        sellingPrice = price;
    }

    void setName(string name){
        this->name = name;
    }

    // getter
    int getMRP()
    {
        return mrp;
    }

    int getSellingPrice()
    {
        return sellingPrice;
    }

    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    void showdetails()
    {
        cout << "MRP : " << getMRP() << endl
             << "Selling Price : " << getSellingPrice() << endl
             << "Name: " << getName() << endl
             << "ID : " << getID() << endl;
    }
};

int main()
{

    Product camera(101, 2000, 1800, "Sony Camera");
    Product camera2(camera);
    camera2.setName("goProHero9");
    camera.showdetails();
    cout << endl;
    camera2.showdetails();

    return 0;
}