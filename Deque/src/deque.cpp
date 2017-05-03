#include <stdexcept>
#include <iostream>
#include <deque>

class TrainComposition
{
public:
    void attachWagonFromLeft(int wagonId)
    {
        mytrain.push_front(wagonId);
        //throw std::logic_error("Waiting to be implemented");
    }

    void attachWagonFromRight(int wagonId)
    {
        mytrain.push_back(wagonId);
        //throw std::logic_error("Waiting to be implemented");
    }

    int detachWagonFromLeft()
    {
        int value = mytrain.front();
        mytrain.pop_front();
        return value;
        //throw std::logic_error("Waiting to be implemented");
    }

    int detachWagonFromRight()
    {
        int value = mytrain.back();
        mytrain.pop_back();
        return value;
        //throw std::logic_error("Waiting to be implemented");
    }
private:
    std::deque<int> mytrain;
};

#ifndef RunTests
int main()
{
    TrainComposition tree;
    tree.attachWagonFromLeft(7);
    tree.attachWagonFromLeft(13);
    std::cout << tree.detachWagonFromRight() << "\n"; // 7 
    std::cout << tree.detachWagonFromLeft(); // 13
}
#endif