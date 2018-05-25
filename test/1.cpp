#include <iostream>
#include <string>
using namespace std;
class Duck
{
public:
    Duck(string n,string c,double w)
    {
        name=n;
        color=c;
        weight=w;
    }
    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"color:"<<color<<endl;
        cout<<"weight:"<<weight<<endl;
    }
    void walk()
    {
        cout<<"This duck can walk"<<endl;
    }
    void swim()
    {
        cout<<"This duck can swim"<<endl;
    }
    void ability()
    {
        walk();
        swim();
    }
private:
    string name;
    string color;
    double weight;
};
class FlyDuck:public Duck
{
public:
    FlyDuck(string name,string color,double weight):Duck(name,color,weight)
    {}
    void fly()
    {
        cout<<"This duck can fly"<<endl;
    }
    void ability()
    {
        fly();
    }
    void showAbility()
    {
        Duck::ability();
        ability();
    }
};
class FireDuck:public Duck
{
public:
    FireDuck(string name,string color,double weight,string firecolor):Duck(name,color,weight)
    {
        this->firecolor=firecolor;
    }
    void fire()
    {
        cout<<"This duck can spurt out the "<<firecolor<<" fire"<<endl;
    }
    void ability()
    {
        fire();
    }
    void showAbility()
    {
        Duck::ability();
        ability();
    }
private:
    string firecolor;
};
class SuperDuck:virtual public FlyDuck,virtual public FireDuck
{
public:
    SuperDuck(string name,string color,double weight,string firecolor):FlyDuck(name,color,weight),FireDuck(name,color,weight,firecolor)
    {
    }
    void ability()
    {
        FlyDuck::ability();
        FireDuck::ability();
    }
    void showAbility()
    {
        ability();
    }
};
int main()
{
    Duck duck1("小黄鸭","黄色",10);
    duck1.display();
    duck1.ability();
    cout<<endl;
    FlyDuck duck2("小飞鸭","红色",20);
    duck2.display();
    duck2.ability();
    cout<<endl;
    FireDuck duck3("喷火鸭","黑色",30,"red");
    duck3.display();
    duck3.ability();
    cout<<endl;
    SuperDuck duck4("超级鸭","金色",40,"blue");
    //duck4.display();
    duck4.ability();
    system("pause");
    return 0;
}
