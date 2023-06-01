#ifndef MAGICITERATOR_MAGICALCONTAINER_HPP
#define MAGICITERATOR_MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;

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
            size_t index;

        public:
            explicit AscendingIterator(MagicalContainer& cont, size_t idx = 0);

            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            AscendingIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // SideCross Iterator class
        class SideCrossIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            explicit SideCrossIterator(MagicalContainer& cont, size_t idx = 0);

            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator operator++(int);
            int* begin() const;
            int* end() const;
        };

        // Prime Iterator class
        class PrimeIterator {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            explicit PrimeIterator(MagicalContainer& cont, size_t idx = 0);

            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            PrimeIterator operator++(int);
            int* begin() const;
            int* end() const;
        };
    };
}

#endif //MAGICITERATOR_MAGICALCONTAINER_HPP
