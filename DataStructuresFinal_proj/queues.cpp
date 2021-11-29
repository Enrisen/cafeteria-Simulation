#include "queues.h"
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<sstream>
using namespace std;

queues::queues()
{

}

void queues::assign(string names[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(qRight.size() < qLeft.size())
        {
            qRight.push(names[i]);
        }
        else if(qRight.size() > qLeft.size())
        {
            qLeft.push(names[i]);
        }
        else
        {
            int randomQ = rand()%2;
            if(randomQ == 1)
                qRight.push(names[i]);
            else
                qLeft.push(names[i]);
        }


    }

}

queue<string> queues::getQLeft() const
{
    return qLeft;
}

queue<string> queues::getQRight() const
{
    return qRight;
}

void queues::setQRight(const queue<string> &value)
{
    qRight = value;
}

void queues::setQLeft(const queue<string> &value)
{
    qLeft = value;
}
