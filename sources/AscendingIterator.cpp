#include "MagicalContainer.hpp"


namespace ariel {
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont)
            : container(cont), iterator(cont.ascending.begin()) {
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return this->iterator == other.;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return index > other.index;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return index < other.index;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        return container.elements[index];
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        ++index;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {
        AscendingIterator temp = *this;
        ++(*this);
        return temp;
    }

    int *MagicalContainer::AscendingIterator::begin() const {
        return &(container.elements[0]);
    }

    int *MagicalContainer::AscendingIterator::end() const {
        return &(container.elements[container.elements.size()]);
    }
}