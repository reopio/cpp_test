#include <iostream>

void p1(){

    using std::cout;
    using std::endl;
    cout<<"p1 out"<<endl;
}

void p2(){

    std::cout<<"p2 out"<<std::endl;
}

int main(){


    p1();
    p2();
    return 0;
}