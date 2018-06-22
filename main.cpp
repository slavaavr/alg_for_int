#include <iostream>
#include "double-cyclic-linked-list/DoubleCyclicLinkedList.cpp"

int main() {
    auto *l = new DoubleCyclicLinkedList<int>();
    l->add(1)->add(2);
    l->add(3);
    l->print();
    std::cout<<l->getHead()<< " "<< l->getTail()<<std::endl;
    l->remove(1);
    l->print();
    l->remove(2);
    std::cout<< l->getByIndex(0)<< std::endl;
    l->print();
    return 0;
}