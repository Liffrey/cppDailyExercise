#include <iostream>

class Vector
{
private:
    double *elem;
    int size;

public:
    Vector(int sz) : elem{}, size{} {} // constructer
    ~Vector()                          // destructer
    {
    }
    //
    int size() const;
    int is_empty() const;
    void insert(const data);
    void erase();
};

int main()
{

    return 0;
}