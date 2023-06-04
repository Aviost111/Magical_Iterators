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

}
