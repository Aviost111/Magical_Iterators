#include "MagicalContainer.hpp"

namespace ariel {
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont, size_t idx)
            : container(cont), index(idx) {}

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return index == other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return index < other.index;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        index += 2;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {
        SideCrossIterator temp = *this;
        ++(*this);
        return temp;
    }

    int *MagicalContainer::SideCrossIterator::begin() const {
        return &(container.elements[0]);
    }

    int *MagicalContainer::SideCrossIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }

    std::list<int>::iterator MagicalContainer::SideCrossIterator::getIteratorBegin() const {
        return this->iteratorBegin;
    }

    std::list<int>::iterator MagicalContainer::SideCrossIterator::getIteratorEnd() const {
        return this->iteratorEnd;
    }
}
