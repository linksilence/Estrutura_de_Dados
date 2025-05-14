#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Node_T {
public:
    T jogador;
    T cor;
    T torre;
    Node_T<T>* proximo;
};

template <class T>
class Pilha {
private:
    Node_T<T>* TOP;
    int N;
public:
    Pilha() {
        TOP = nullptr;
        N = 0;
    }
    bool push(T jo, T co, T tor);
    void pop();
    T top();
    int size();
    bool Empty();
    Node_T<T>* top_node() { return TOP; }
};

template <class T>
T Pilha<T>::top() {
    return TOP->cor;
};

template <class T>
int Pilha<T>::size() {
    return N;
};

template <class T>
bool Pilha<T>::Empty() {
    return !N;
};

template <class T>
bool Pilha<T>::push(T jo, T co, T tor) {
    Node_T<T>* p = new Node_T<T>;
    if(!p) return false;
    p->jogador = jo;
    p->cor = co;
    p->torre = tor;
    p->proximo = TOP;
    TOP = p;
    N++;
    return true;
};

template <class T>
void Pilha<T>::pop() {
    if(TOP == nullptr) return;
    Node_T<T>* p = TOP;
    TOP = TOP->proximo;
    delete p;
    N--;
};

template <class T>
class Node {
public:
    T jogador;
    T cor;
    T torre;
    Node<T>* proximo;
};

template <class T>
class Fila {
private:
    Node<T>* front;
    Node<T>* Back;
    int n;
public:
    Fila() {
        front = nullptr;
        Back = nullptr;
        n = 0;
    }
    bool push(T soca_jogador, T soca_cor, T soca_torre);
    T retorna_frente();
    T retorna_costa();
    T retorna_jogador();
    T retorna_Torre();
    void desenfilera();
    int size();
    bool Empty();
};

template <class T>
T Fila<T>::retorna_jogador() {
    return front->jogador;
};

template <class T>
T Fila<T>::retorna_Torre() {
    return front->torre;
};

template <class T>
T Fila<T>::retorna_frente() {
    return front->cor;
};

template <class T>
T Fila<T>::retorna_costa() {
    return Back->cor;
};

template <class T>
void Fila<T>::desenfilera() {
    if(front == nullptr) return;
    Node<T>* p = front;
    front = front->proximo;
    delete p;
    n--;
    if(front == nullptr) Back = nullptr;
};

template <class T>
bool Fila<T>::push(T soca_jogador, T soca_cor, T soca_torre) {
    Node<T>* p = new Node<T>;
    if(!p) return false;
    p->jogador = soca_jogador;
    p->cor = soca_cor;
    p->torre = soca_torre;
    p->proximo = nullptr;
    
    if(!front) {
        front = p;
    } else {
        Back->proximo = p;
    }
    Back = p;
    n++;
    return true;
};

template <class T>
int Fila<T>::size() {
    return n;
};

template <class T>
bool Fila<T>::Empty() {
    return !n;
};

string entrada;
Fila<char> J1, J2, J3, J4;
Pilha<char> T1, T2, T3, T4, T5, T6;
Pilha<char>* pilhas[] = {&T1, &T2, &T3, &T4, &T5, &T6};

char retorna_cor_do_jogador(Fila<char>& Jogador) {
    if(Jogador.retorna_frente() != 'P') {
        return Jogador.retorna_frente();
    } else {
        return Jogador.retorna_costa();
    }
};

Fila<char>* retorna_jogada(char cor) {
    if(retorna_cor_do_jogador(J1) == cor) return &J1;
    else if(retorna_cor_do_jogador(J2) == cor) return &J2;
    else if(retorna_cor_do_jogador(J3) == cor) return &J3;
    else return &J4;
};

void processa_jogada(Fila<char>* Jogada_da_vez, Pilha<char>* pilhas[]) {
    bool colocada = false;
    int posicao_da_torre = Jogada_da_vez->retorna_Torre() - '1';
    int tentativas = 0;

    while(!colocada && tentativas < 6) {
        if(pilhas[posicao_da_torre]->size() < 6) {
            if(Jogada_da_vez->retorna_frente() != 'P') {
                pilhas[posicao_da_torre]->push(
                    Jogada_da_vez->retorna_jogador(),
                    Jogada_da_vez->retorna_frente(),
                    Jogada_da_vez->retorna_Torre()
                );
            } else {
                if(!pilhas[posicao_da_torre]->Empty()) {
                    pilhas[posicao_da_torre]->pop();
                }
            }
            Jogada_da_vez->desenfilera();
            colocada = true;
        } else {
            posicao_da_torre = (posicao_da_torre + 1) % 6;
            tentativas++;
        }
    }
};

void imprimir_resultado() {
    




    cout << "Tabuleiro final:" << endl;
    char matriz_do_krlh[6][6];
    int z=0;
    
    for(int i = 0; i < 6; i++) {
        Pilha<char> copia = *pilhas[i];
        z=0;
        while(!copia.Empty()){
             matriz_do_krlh[i][z]=copia.top() ;
             copia.pop();
             z++;
        }
    }
    
    for(int i = 0; i < 6; i++) 
    {
        for(int j = 0; j < 6; j++) 
        {
            cout << matriz_do_krlh[j][i] << " "; 
        }
        cout << endl;
        
    };
    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    getline(cin, entrada);
    entrada.erase(remove(entrada.begin(), entrada.end(), ' '), entrada.end());

    for(int i = 1; i < entrada.size(); i++) {
        if(isalpha(entrada[i]) && isdigit(entrada[i+1])) {
            if(entrada[i-1] == '1') J1.push(entrada[i-1], entrada[i], entrada[i+1]);
            else if(entrada[i-1] == '2') J2.push(entrada[i-1], entrada[i], entrada[i+1]);
            else if(entrada[i-1] == '3') J3.push(entrada[i-1], entrada[i], entrada[i+1]);
            else if(entrada[i-1] == '4') J4.push(entrada[i-1], entrada[i], entrada[i+1]);
        }
    }

    int max_iteracoes = 1000;
    int iteracao = 0;
    
    while(iteracao < max_iteracoes && !(T1.size()==6 && T2.size()==6 && T3.size()==6 && T4.size()==6 && T5.size()==6 && T6.size()==6)) {
        char cores[] = {'A', 'V', 'R', 'B'};
        for(char cor : cores) {
            Fila<char>* jogador = retorna_jogada(cor);
            if(!jogador->Empty()) {
                processa_jogada(jogador, pilhas);
            }
        }
        iteracao++;
    }

    imprimir_resultado();
    return 0;
}