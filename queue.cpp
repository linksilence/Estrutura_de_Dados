#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;
template <typename T>
class Node
{
    public:
    Node<T>* proximo;
    T thing;
};
template <typename T>
class Queue
{
    private:
    Node<T>* Head;
    Node<T>* Tail;
    int N;

    public:
    Queue()
    {
        Head=Tail=N=0;
    };

    bool Push(T algo_a_ser_socado);
    int Size();
    bool Empaty();

};

template <typename T>
bool Queue<T>::Push(T algo_a_ser_socado)
    {
        Node<T>* p = new Node<T>;
        if(!p)
        {
            return false;
        }
        p->thing=algo_a_ser_socado;
        p->proximo=0;

        if(!Head)
        {
            Head=p;
        }
        else
        {
            Tail->proximo=p
        }

        Tail=p;
        N++
        return true;

    };

int main()
{
    return 0;
}