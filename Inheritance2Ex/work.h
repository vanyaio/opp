#ifndef WORK_H
#define WORK_H

#include <iostream>
using namespace std;
#define max_wrks 100;

//example of abstract type
class worker//'cause is abstract creating worker obj is not allowed
{
protected:
    string name;
    int salary;
public:
    virtual int calc_salary() = 0; //Pure virtual function, that's set worker as an abstract class
    virtual worker(const string& _name, int _salary)
    {
        name = _name;
    }
};

class data_base
{
private:
    worker* workers[max_wrks];//YES, WORKERS*
    int num;
public:
    hire(worker* w);
    fire(worker* w);
    int calc_all_salary()
    {
        int sum = 0;
        for (int i = 0; i < num; i++)
            sum += workers[i]->calc_salary();
        return sum;
    }
};

class developer : worker
{
protected:
    int level;
    string project;
public:
    developer(string _name, string _project, int _level, int _salary) : worker(_name, _salary)
    {
        level = _level;
        project = _project;
    }

//    a bit invalid example, suggest we use C-string
//    ~develop() override
//    {
//        delete[] project;
//    }
//     problems: worker* w = new developer(...), delete w  - if ~worker was not be virtual, ~developer would not be called
//     but ~worker is virtual, so there's no problem
//      note: developer* w = new developer(...), delete w - does not cause problem - first ~worker works, after ~developer works


};
#endif // WORK_H
