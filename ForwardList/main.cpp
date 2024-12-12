#include <iostream>
#include "forwardList.h"
#include <cassert>

int main() {
    ForwardList<int> list{1, 2, 3};
    list.print();
    return 0;
}
