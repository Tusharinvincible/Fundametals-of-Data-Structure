#include <iostream>
using namespace std;
class grant_par{
    public:
    grant_par(){
        cout<<"Grand Parent default constructor : "<<endl;
    }
    grant_par(int x){
        cout<<"Grand Parent  parameterized constructor :  "<<x<<endl;
    }
};
class parent:public grant_par{
    public:
    
    parent(){
        cout<<"Parent Class defrault Constructor :  "<<endl;
    }
    parent(int zz,int yy):grant_par(yy){
        cout<<"Parent class  parameterized constructor : "<<zz<<endl;
    }
};

class Child:public parent{
    public:
    Child(){
        cout<<"Child Class default Constructor :  "<<endl;
    }
    Child(int aa,int bb,int cc):parent(bb,cc){
        cout<<"Child class  parameterized constructor: "<<aa<<endl;
    }
};




int main(){
    cout<<"\n\n";
    Child d(10,20,30);
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    Child d1;

    cout<<"\n\n";
    return 0;
}