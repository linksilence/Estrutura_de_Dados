#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

/*está lista é implementada atraves de um ponteiro It que itera acerca 
da mesma, e possui seu respectivos métodos para interar sobre ela e receber seus elementos*/

template <class T>
class Node
{
    public:
    T elemento;
    Node<T>* next=nullptr;
};

template <class T>
class List
{
    private:
    Node<T>*Head;
    Node<T>**It;
    int N;

    public:
    List()
    {
        It=Head=nullptr;
        N=0;
    }; //não importa onde o mesmo é criado
    bool pushIt(T parametro);//ok
    bool pushFront(T parametro);//ok
    void popIt();//ok
    void popFront();//ok
    int size();//ok
    bool empty();//ok
    T getIt();//ok
    T getFront();//ok
    void ItMM();//ok
    void Itbegin();

};
template <class T>
bool List<T>::pushIt(T parametro)
{
    Node<T>* p = new Node<T>;
    if(!p)return false;
    p->elemento=parametro;
    p->next=*It;
    *It=p;
    N++;
    return true;
};
template <class T>
bool List<T>::pushFront(T parametro)
{
    Node<T>* p = new Node<T>;
    if(!p)return false;
    p->elemento=parametro;
    p->next=Head;
    Head=p;
    N++;
    return true;
};
template <class T>
void List<T>::popIt()
{
    /* o ponteiro de ponteiro **It aponta para outro ponteiro ( *next ), então se colocarmos somente
    a definição *It com um asterisco vamos estar nos referindo a referência *next(o próprio ponteiro em si),
    dessa forma, compreendemos que caso *It seja diferente de Null, *next tem um um node a ser removido
    ou seja, um elemento lá dentro */
    if(*It){
        Node<T>*p=*It;
        *It=p->next;
        N--;
        delete p;
    }
};
template <class T>
void List<T>::popFront()
{
    if(*Head)
    {
        Node<T>*p =Head;
        Head=p->next;
        N--;
        delete p;
    }
};

template <class T>
bool List<T>::empty()
{
   if(!(*Head))
   {
        return true;
   }
   return false;
};

template <class T>
int List<T>::size()
{
    return N;
};

template <class T>
T List<T>::getFront()
{
    return (*Head->elemento);
};

template <class T>
T List<T>::getIt()
{
    return (*It)->elemento;
};

template <class T>
void List<T>::ItMM()
{
    It=&(*It->next);
};

template <class T>
void List<T>::Itbegin()
{
    It=&Head;
};


int main()
{
    return 0;
}