#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <iostream>
#include <vector>

namespace ariel{
    class MagicalContainer{
    private:
        std::vector<int> vector;
    public:
        MagicalContainer();
    };

    class AscendingIterator{
    private:
        MagicalContainer* container;
    public:
        AscendingIterator();
    };

    class SideCrossIterator{
    private:
        MagicalContainer* container;
    public:SideCrossIterator();
    };

    class PrimeIterator{
    private:
        MagicalContainer* container;
    public:
        PrimeIterator();
    };
}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
