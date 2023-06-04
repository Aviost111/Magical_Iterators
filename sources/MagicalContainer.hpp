#ifndef MAGICITERATOR_MAGICALCONTAINER_HPP
#define MAGICITERATOR_MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;
        std::list<int*> prime;

    public:
        MagicalContainer();
        ~MagicalContainer();
        std::vector<int> getElements();
        void addElement(int element);
        int size() const;
        void removeElement(int element);

        // Ascending Iterator class
        class AscendingIterator {
        private:
            MagicalContainer& container;
            std::list<int*>::iterator iterator;

        public:
            explicit AscendingIterator(MagicalContainer& cont);
            std::vector<int>::iterator getIterator() const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            const AscendingIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // SideCross Iterator class
        class SideCrossIterator {
        private:
            MagicalContainer& container;
            std::list<int>::iterator iteratorBegin;
            std::list<int>::iterator iteratorEnd;


        public:
            explicit SideCrossIterator(MagicalContainer& cont);

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            std::list<int>::iterator getIteratorBegin() const;
            std::list<int>::iterator getIteratorEnd() const;
            SideCrossIterator& operator++();
            const SideCrossIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // Prime Iterator class
        class PrimeIterator {
        private:
            MagicalContainer& container;
            std::list<int>::iterator iterator;

        public:
            explicit PrimeIterator(MagicalContainer& cont, size_t idx = 0);
            std::list<int>::iterator getIterator() const;
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            const PrimeIterator operator++(int);
            int* begin() const;
            int* end() const;
        };
    };
}

#endif //MAGICITERATOR_MAGICALCONTAINER_HPP
