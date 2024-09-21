#include <iostream>

class t1{
    private:
        int a;
        int b;
        double *f = new double[3];
    public:
        void set_arr();
        int add(int a1);
        t1();
        t1(int a1, int b1);
        void show();
        void set2(int a1,int b1);
        void show_arr();
        ~t1();
};

void t1::set2(int a1, int b1){
    a=a1;
    b=b1;
}

int t1::add(int a1){
    return a1*(a+b);
}

void t1::show(){
    using std::cout;
    using std::endl;
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
}

void t1::show_arr(){
    using std::cout;
    using std::endl; // minding life scope
    cout<<"f0:"<<f[0]<<endl;
    cout<<"f1:"<<f[1]<<endl;
    cout<<"f2:"<<f[2]<<endl;
}

void t1::set_arr(){
    f[0]=1.0;
    f[1]=2.0;
    f[2]=3.0;
}

t1::t1(int a1, int b1){
    a=a1;
    b=b1;
}

t1::t1(){
    a=5;
    b=5;
}

t1::~t1(){
    delete f;
    std::cout<<"freed memory"<<std::endl;
}

int main(){

    using std::cout;
    using std::endl;
    {
        t1 class1(1,2);
        class1.show();
        class1.set2(8,8);
        class1.show();
        class1.set_arr();
        class1.show_arr();
        cout<<class1.add(3)<<endl;
        cout<<"mark"<<endl;
    } // class1 life time

    {
        t1 class2;
        class2.show();
        class2.set_arr();
        class2.show_arr();
        cout<<class2.add(3)<<endl;
        cout<<"mark"<<endl;
    }// class2 life time

    return 0;
}