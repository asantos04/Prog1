#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

template<typename t1,typename t2>
class Pair{
    public:
        Pair(t1 first,t2 second){
           first_=first;
           second_=second; 
        }
        t1 get_first() const{
            return first_;
        }
        t2 get_second() const{
            return second_;
        }
        void show() const{
            cout<<"{"<<first_<<","<<second_<<"}";
        }

    private:
        t1 first_;
        t2 second_;
};

template<typename t1,typename t2>
bool compare1(Pair<t1,t2> P1,Pair<t1,t2> P2){
   return P1.get_first()<=P2.get_first();
}

template<typename t1,typename t2>
bool compare2(Pair<t1,t2> P1,Pair<t1,t2> P2){
    return P1.get_second()<=P2.get_second();
}

template<typename t1,typename t2>
void sort_by_first( vector<Pair<t1,t2>>& a ){
    sort(a.begin(),a.end(),compare1<t1,t2>);
}

template<typename t1,typename t2>
void sort_by_second( vector<Pair<t1,t2>>& a ){
    sort(a.begin(),a.end(),compare2<t1,t2>);
}

template<typename t1, typename t2>
void show(vector<Pair<t1, t2>> a){
    cout<<"{";
    for(Pair<t1,t2>& b:a){
        b.show();
    }
    cout<<"}";
}