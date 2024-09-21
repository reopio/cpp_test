#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

// base class
class c1{
    private:
        string firstname;
        string lastname;
        bool hasTable;
    public:
        c1(const string & fn = "none",const string & ln = "none",
            bool ht = false);
        void name() const;
        bool HasTable() const{ return hasTable;};
        void resetTable(bool v){hasTable = v;};
};

// derived class
class c_inher: public c1{
    private:
        unsigned int rating;
    public:
        c_inher(unsigned int r=0, const string &fn = "none",
            const string &ln = "none", bool ht = false);
        c_inher(unsigned int r ,const c1 &father_class);
        unsigned Rating() const{return rating;};
        void reset(unsigned r){rating =r;};
};

// class code
c1::c1(const string & fn,const string & ln,bool ht){
        firstname = fn;
        lastname   = ln;
        hasTable = ht;
    }

void c1::name() const{
    cout<<lastname<<", "<<firstname<<endl;
}

c_inher::c_inher(unsigned int r, const string &fn,
    const string &ln, bool ht):c1(fn,ln,ht){
        rating =r;
    }

c_inher::c_inher(unsigned r,const c1 &father_class):c1(father_class){
    rating=r;
}

// using inherited class and base class
int main(void){

    c1 pl2("mike","ase",0);
    c_inher rpl1(1111,"joe","bideng",1);

    c_inher rpl2(2222,pl2);

    pl2.name();
    rpl1.name();

    cout<<"pl1 rating: "<<rpl1.Rating()<<endl;
    cout<<"pl2 rating: "<<rpl2.Rating()<<endl;

    return 0;
}