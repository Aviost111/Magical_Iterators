#include "MagicalContainer.hpp"

namespace ariel {
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

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont, size_t idx)
            : container(cont), index(idx) {
        while (index < container.elements.size() && !isPrime(container.elements[index])) {
            ++index;
        }
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return index == other.index;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        return index > other.index;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return index < other.index;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
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

    int *MagicalContainer::PrimeIterator::begin() const {
        return &(container.elements[0]);
    }

    int *MagicalContainer::PrimeIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }
}