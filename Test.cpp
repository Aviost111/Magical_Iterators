#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Test addElement and size") {
    MagicalContainer container;
    CHECK((container.size() == 0));

    container.addElement(5);
    CHECK((container.size() == 1));

    container.addElement(10);
    CHECK((container.size() == 2));

    container.addElement(10);
    CHECK((container.size() == 2));
}

TEST_CASE("Test removeElement") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    container.removeElement(10);
    CHECK((container.size() == 2));
}

TEST_CASE("Test AscendingIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);

    MagicalContainer::AscendingIterator ascIter(container);
    auto it = ascIter.begin();

    auto ip = it;

    CHECK((*it == 5));

    ++it;
    //comparing checks
    CHECK((it >ip));

    CHECK((ip<it));

    CHECK((ip!=it));

    ++ip;

    CHECK((ip==it));

    ++it;
    CHECK((*it == 10));
    ++it;
    CHECK((*it == 15));

    ip = it;
    ip++;
    CHECK((ip == ascIter.end()));

    //if you add an element after the iterator it will get to it
    container.addElement(30);
    it++;

    CHECK((*it == 30));
    ip++;
    CHECK((ip == ascIter.end()));
    //if you add an element before the iterator it will not get to it
    container.addElement(29);

    ip = it;
    ip++;

    CHECK((ip == ascIter.end()));

    //will throw error if past end
    CHECK_THROWS((ip++));
}

TEST_CASE("Test SideCrossIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    container.addElement(13);

    MagicalContainer::SideCrossIterator crossIter(container);
    auto it = crossIter.begin();

    auto ip = it;

    CHECK((*it == 5));
    ++it;
    //comparing checks
    CHECK((it >ip));

    CHECK((ip<it));

    CHECK((ip!=it));

    ++ip;

    CHECK((ip==it));
    CHECK((*it == 15));
    ++it;
    CHECK((*it == 10));
    ++it;
    CHECK((*it == 13));

    ip=it;
    ip++;

    CHECK((ip == crossIter.end()));

    //if you add an element after the iterator it will get to it
    container.addElement(11);
    it++;
    CHECK((*it == 11));

    ip=it;
    ip++;

    CHECK((ip == crossIter.end()));

    //if you add an element before the iterator it will not get to it
    container.addElement(29);
    ip = it;
    ip++;

    CHECK((ip == crossIter.end()));

    //will throw error if past end
    CHECK_THROWS((ip++));
}

TEST_CASE("Test PrimeIterator") {

    MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);

    MagicalContainer::PrimeIterator primeIter(container);
    auto it = primeIter.begin();
    CHECK((*it == 2));
    ++it;
    CHECK((*it == 3));

    auto ip = it;

    ++it;

    //comparing checks
    CHECK((*it == 5));

    CHECK((it >ip));

    CHECK((ip<it));

    CHECK((ip!=it));

    ++ip;

    CHECK((ip==it));

    ++it;
    CHECK((*it == 7));
    ip=it;
    ip++;

    CHECK((ip == primeIter.end()));

    //if you add an element after the iterator it will get to it
    container.addElement(13);
    it++;
    CHECK((*it == 13));
    ip=it;
    ip++;

    CHECK((ip == primeIter.end()));

    //if you add an element before the iterator it will not get to it
    container.addElement(11);
    ip = it;
    ip++;
    CHECK((ip == primeIter.end()));

    //if you add an element after the iterator but not a prime it will not get to it
    container.addElement(15);
    ip = it;
    ip++;
    CHECK((ip == primeIter.end()));

    //will throw error if past end
    CHECK_THROWS((ip++));
}

TEST_CASE("Test comparing ") {
    MagicalContainer container,container2;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container2.addElement(2);
    container2.addElement(3);
    container2.addElement(4);

    MagicalContainer::PrimeIterator primeIter(container);
    auto pi = primeIter.end();
    auto pi2 = primeIter.begin();
    MagicalContainer::SideCrossIterator crossIter(container);
    auto ci = crossIter.begin();
    MagicalContainer::SideCrossIterator crossIter2(container2);
    auto ci2 = crossIter2.begin();
    bool a;
    CHECK_THROWS(a = (ci==ci2));
    CHECK_THROWS(a = (ci!=ci2));
    CHECK_THROWS(a = (ci<ci2));
    CHECK_THROWS(a = (ci>ci2));
    CHECK_THROWS(a = (pi==ci2));
    CHECK_THROWS(a = (pi!=ci2));
    CHECK_THROWS(a = (pi<ci2));
    CHECK_THROWS(a = (pi>ci2));
    CHECK_NOTHROW(a = (pi==pi2));
    CHECK_NOTHROW(a = (pi!=pi2));
    CHECK_NOTHROW(a = (pi<pi2));
    CHECK_NOTHROW(a = (pi>pi2));



}
