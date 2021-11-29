#ifndef QUEUES_H
#define QUEUES_H
#include<iostream>
#include<queue>
using namespace std;


class queues
{

public:
    queues();

    void assign(string names[], int size);
    queue<string> getQLeft() const;

    queue<string> getQRight() const;

    void setQRight(const queue<string> &value);

    void setQLeft(const queue<string> &value);

private:
    queue<string>qRight;
    queue<string>qLeft;
};

#endif // QUEUES_H
