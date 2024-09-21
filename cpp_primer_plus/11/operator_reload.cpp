#include <iostream>

//reload + operator to add Time in the Time class
class Time{
    private:
        int hour;
        int minutes;
    public:
        Time();
        Time(int h,int min);
        void reset(int h = 0, int min = 0);
        Time operator+(const Time & t) const;
        void show() const;
        ~Time(){};
};

Time::Time(){
    hour=0;
    minutes=0;
}

Time::Time(int h,int min){
    hour=h;
    minutes=min;
}

void Time::reset(int h ,int min ){
    hour=h;
    minutes=min;
}

Time Time::operator+(const Time & t) const{
    Time sum;
    sum.minutes = minutes+t.minutes;
    sum.hour = hour + t.hour + sum.minutes / 60;
    sum.minutes = sum.minutes % 60;
    return sum;
}

void Time::show() const{
    using std::cout;
    using std::endl;
    cout<<hour<<" hours, ";
    cout<<minutes<<" minutes\n";
}
// end of Time class


// reload * operator to multiply array seperately
// minding the shallow copy problem
class vec{
    private:
        int len;
        double *arr;

    public:
        vec(){
            std::cerr<<"no vec parameter\n";
            exit(-1);
        }
        vec(int len_arr);
        vec operator*(const vec & t) const;
        vec& operator=(const vec & t);
        void set_value(double offs);
        void set_zero();
        void show() const;
        ~vec(){
            delete[] arr;
        };
};

vec::vec(int len_arr){
    len = len_arr;
    arr = new double[len];
}

// error code
// with shallow copy
// ===============================
// vec vec::operator*(const vec & t) const{
//     vec mul(len);
//     for(unsigned i=0;i<len;i++){
//         mul.arr[i]=arr[i]*t.arr[i];
//     }
//     return mul; // shallow copy result in double free 
// }


// correct code with deep copy
// notice that we must reload = operator first to avoid shallow copy
vec& vec::operator=(const vec& t) {

    if (this == &t) {
        return *this; // Handle self-assignment
    }

    delete[] arr; // Free existing memory

    len = t.len;
    arr = new double[len];
    for (unsigned i = 0; i < len; ++i) {
        arr[i] = t.arr[i];
    }

    return *this;
}

vec vec::operator*(const vec & t) const{
    vec mul(len);
    for(unsigned i=0;i<len;i++){
        mul.arr[i]=this->arr[i]*t.arr[i];
    }
    return mul;
}

void vec::set_value(double offs){
    for(unsigned i=0;i<len;i++){
        arr[i]=i+offs;
    }
}

void vec::set_zero(){
    for(unsigned i=0;i<len;i++){
        arr[i]=0.0;
    }
}

void vec::show() const{
    for(unsigned i=0;i<len;i++){
        std::cout<<arr[i]<<", ";
    }
    std::cout<<"\n";
}
// end of vec class

int main(){

    // test reload + operator to add Time in Time class
    // 1 hour 30 minutes + 2 hours 45 minutes
    std::cout<<"//test reload + operator to add Time in Time class \n"
    <<"//1 hour 30 minutes + 2 hours 45 minutes\n";
    Time    t1(1,30),
            t2(2,45),
            t3;
    
    std::cout<<"t1: \n";
    t1.show();
    std::cout<<"t2: \n";
    t2.show();
    t3=t1+t2;

    std::cout<<"t3 = t1 + t2: \n";
    t3.show();


    std::cout<<"\n";


    // test reload * operator to multiply array seperately in vec class
    std::cout<<"//test reload * operator to multiply array seperately in vec class\n";
    vec v1(5),
        v2(5),
        v3(5);

    v1.set_value(0.0);
    v2.set_value(1.0);
    v3.set_zero();

    std::cout<<"v1: \n";
    v1.show();
    std::cout<<"v2: \n";
    v2.show();
    std::cout<<"v3: \n";
    v3.show();

    v3=v1*v2;

    vec v4=v1*v2;
    std::cout<<"v4 = v1 * v2: \n";
    v4.show();

    std::cout<<"v3 = v1 * v2: \n";
    std::cout<<"v3: \n";
    v3.show();

    return 0;
}