#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

template <typename T>
class Node
{
    public:
    T alguma_coisa;
    Node<T>* Proximo=NULL;
};

template <typename T>
class Stack
{
    private:
    Node<T>*Top; // aponta pro topo da lista que dentro desse nó terá endereço encadeado para outros nós
    int N;//quantidade de elementos na lista

    public:
    Stack();
    T TOP();
    int Size();
    bool push(T Socara_la_dentro);
    bool IsEmpty();
};

template<typename T>
bool Stack<T>::push(T Socara_la_dentro)
    {
        Node<T>*p = new Node<T>;
        if(!p)
        {
            return false;
        }
        p->Proximo=Top;
        p->alguma_coisa=Socara_la_dentro;
        Top=p;
        N++;
        return true;
    };

template <typename T>
bool Stack<T>::IsEmpty()
{
    if(!N)
    {
        return true;
    }
    return false;
}
template <typename T>
int Stack<T>::Size()
    {
        return N;
    }
template <typename T>

T Stack<T>::TOP()
    {
        return Top->alguma_coisa;
    }
    
int main()
{
    return 0;
}