#include "MagicalContainer.hpp"

namespace ariel {


    int MagicalContainer::size() const {
        return 0;
    }

    void MagicalContainer::addElement(int element) {
        for (int index:elements) {
            if(index==element){
                return;
            }
        }
        elements.push_back(element);
    }

    void MagicalContainer::removeElement(int element) {

    }

    MagicalContainer::MagicalContainer() {

    }

    MagicalContainer::~MagicalContainer() {

    }

    std::vector<int> MagicalContainer::getElements() {
        return std::vector<int>();
    }
    // Ascending Iterator

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont, size_t idx)
            : container(cont), index(idx) {}

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return index < other.index;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        ++index;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {
        AscendingIterator temp = *this;
        ++(*this);
        return temp;
    }

    int* MagicalContainer::AscendingIterator::begin() const {
        return &(container.elements[0]);
    }

    int* MagicalContainer::AscendingIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }


    // SideCross Iterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont, size_t idx)
            : container(cont), index(idx) {}

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return index < other.index;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        index += 2;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {
        SideCrossIterator temp = *this;
        ++(*this);
        return temp;
    }

    int* MagicalContainer::SideCrossIterator::begin() const {
        return &(container.elements[0]);
    }

    int* MagicalContainer::SideCrossIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }


    // Prime Iterator

    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont, size_t idx)
            : container(cont), index(idx) {
        while (index < container.elements.size() && !isPrime(container.elements[index])) {
            ++index;
        }
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return index < other.index;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        do {
            ++index;
        } while (index < container.elements.size() && !isPrime(container.elements[index]));
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) {
        PrimeIterator temp = *this;
        ++(*this);
        return temp;
    }

    int* MagicalContainer::PrimeIterator::begin() const {
        return &(container.elements[0]);
    }

    int* MagicalContainer::PrimeIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }
}
