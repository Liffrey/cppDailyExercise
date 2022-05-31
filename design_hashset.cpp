#include <iostream>
#include <array>
using namespace std;

#define HASH_MAP_SIZE 1'000'000
class MyHashSet
{
private:
    int rows[HASH_MAP_SIZE];
    int hash(int key)
    {
        return key % HASH_MAP_SIZE;
    }

public:
    MyHashSet()
    {
        for (int i = 0; i < HASH_MAP_SIZE; i++)
        {
            rows[i] = -1;
        }
    }

    void add(int key)
    {
        int index = hash(key);
        // eğer row boş ise hashlenen keyi o row'a ekle
        if (rows[index] == -1)
        {
            rows[index] = key;
        }
        // eğer satır boş değilse o satıra diğer elemanı ekle
        // else
    }

    void remove(int key)
    {
        int index = hash(key);

        if (rows[index] != -1)
        {
            rows[index] = -1;
        }
    }

    bool contains(int key)
    {
        //for (int i = 0; i < HASH_MAP_SIZE; i++)
        //{
        int index = hash(key);
        if (rows[index] == key)
            return true;
        // }
        return false;
    }
};
int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(5);
    bool result = obj->contains(5);
    cout << result << endl;
    obj->remove (5);
    result = obj->contains(5);
    cout << result << endl;
    delete obj;
    return 0;
}





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define HASH_MAP_SIZE 1'500
class MyHashSet
{
private:
    vector<int> rows[HASH_MAP_SIZE];
    int hash(int key)
    {
        return key % HASH_MAP_SIZE;
    }

public:
    MyHashSet()
    {
        for (int i = 0; i < HASH_MAP_SIZE; i++)
        {
            //rows[i] = -1;
            rows[i].clear();
        }
    }

    void add(int key)
    {
        int index = hash(key);

        vector<int>::iterator it = find(rows[index].begin(), rows[index].end(), key);
        if (it == rows[index].end())
            // eğer row boş ise hashlenen keyi o row'a ekle
        {
            rows[index].push_back(key);
        }

    }

    void remove(int key)
    {
        int index = hash(key);

        if (!rows[index].empty())
        {
            vector<int>::iterator it = find(rows[index].begin(), rows[index].end(), key);
            if (it != rows[index].end())
            {
                rows[index].erase(it);
            }
        }
    }

    bool contains(int key)
    {
        int index = hash(key);
        vector<int>::iterator it = find(rows[index].begin(), rows[index].end(), key);
        if (it !=rows[index].end())
            return true;
        return false;
    }
};
int main()
{
    MyHashSet myHashSet =  MyHashSet();
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // return True
    myHashSet.contains(3); // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // return True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2); // return False, (already removed)
    return 0;
}