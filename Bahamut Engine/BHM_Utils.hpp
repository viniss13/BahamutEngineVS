#pragma once
namespace bhm_utils {

    template <class List, class UnaryFunction> 
void for_each(List& values, UnaryFunction f){
    
    auto first = values->begin();
    for(; first != values->end(); first++){
        if(first->lock() != NULL){
            f(first);
        } else {
            auto deleteElement = first;
            first--;
            values->erase(deleteElement);
        }
    }
}

template <class List, class UnaryFunction>
void for_each_shared(List& values, UnaryFunction f) {

    auto first = values->begin();
    for (; first != values->end(); first++) {
        if (*first != NULL) {
            f(first);
        }
        else {
            auto deleteElement = first;
            first--;
            values->erase(deleteElement);
        }
    }
}

template <class List, class UnaryFunction>
void while_each(List& values, UnaryFunction f) {

    auto first = values->begin();
    while (first != values->end()) {
        if (*first != NULL) {
            f(first);
            first++;
        }
        else {
            first = values->erase(first);
        }
    }
}

}