#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int value;
    Node * esq;
    Node * dir;
    Node * pai;
    Node(int value = 0, Node * esq = nullptr, Node * dir = nullptr){
        this->value = value;
        this->dir = dir;
        this->esq = esq;
    }
};

Node * make_tree()
{
    Node * root;
    root = nullptr;

    return root;
}

Node * rfind(Node * node, int value)
{
    if(node != nullptr)
    {
        if(node->value == value)
            return node;
        if(value < node->value)
            return rfind(node->esq, value);
        else
            return rfind(node->dir, value);
    }
    return nullptr;
}

//Insere um novo nó recursivamente na BST
Node * rinserct(Node * root, int value)
{
    if(root == nullptr)
        return new Node(value);
    if(value < root->value)
        root->esq = rinserct(root->esq, value);
    if(value > root->value)
        root->dir = rinserct(root->dir, value);
    return root;
}

void swap_l(Node ** a, Node ** b)
{
    Node * aux = *a;
    *a = *b;
    *b = aux;
}

void pais(Node * r)
{
    r->pai = nullptr;
    if(r->esq != nullptr)
    {
        pais(r->esq);
        r->esq->pai = r;
    }
    if(r->dir != nullptr)
    {
        pais(r->dir);
        r->dir->pai = r;
    }
}

void pre_ordem(Node * r)
{
    if(r != nullptr)
    {
        cout << r->value << " ";
        pre_ordem(r->esq);
        pre_ordem(r->dir);
    }
}

void pos_ordem(Node * r)
{
    if(r != nullptr)
    {
        pos_ordem(r->esq);
        pos_ordem(r->dir);
        cout << r->value << " ";
    }
}

void em_ordem(Node * r)
{
    if(r != nullptr)
    {
        em_ordem(r->esq);
        cout << r->value << " ";
        em_ordem(r->dir);
    }
}

Node * sucessor_pre(Node * n)
{
    if(n->esq != nullptr)
        return n->esq;
    if(n->dir != nullptr)
        return n->dir;
    Node * p = n->pai;

    while(p != nullptr && (p->dir == n || p->dir == nullptr) )
    {
        n = p;
        p = p->pai;
    }
    if(p == nullptr)
        return n->dir;
    return p->dir;
}

Node * sucessor_ordem_sim(Node * n)
{
    if(n->dir != nullptr)
    {
        Node * suc = n->dir;
        while(suc->esq != nullptr){
            suc = suc->esq;
        }
        return suc;
    }

    Node * pai = n->pai;
    Node * node = n;

    while(pai != nullptr && pai->dir == node){
        node = pai;
        pai = node->pai;
    }
    return pai;
}

Node * antecessor_pre(Node * n)
{
    if(n->pai == nullptr)
    {
        return nullptr;
    }
    if(n->pai->esq == n || n->pai->esq == nullptr)
    {
        return n->pai;
    }
    Node * ant = n->pai->esq;

    while(ant->dir != nullptr || ant->esq != nullptr){
        if(ant->dir != nullptr)
        {
            ant = ant->dir;
        }
        else
        {
            ant = ant->esq;
        }
    }
    return ant;
}


Node * remove(Node * r, Node * z)
{
    Node * x;
    Node * y;

    if(z->esq == nullptr || z->dir == nullptr)
    {
        y = z;
    }
    else
    {
        y = sucessor_ordem_sim(z);
    }

    if(y->esq != nullptr)
    {
        x = y->esq;
    }
    else
    {
        x = y->dir;
    }

    if(x != nullptr)
    {
        x->pai = y->pai;
    }

    if(y->pai == nullptr)
    {
        r = x;
    }
    else if(y == y->pai->esq)
    {
        y->pai->esq = x;
    }
    else
    {
        y->pai->dir = x;
    }


    z->value = y->value;
    z = y;

    delete z;
    return y;
}







int main()
{
    Node * r = make_tree();

    r = rinserct(r, 5);
    r = rinserct(r, 6);
    r = rinserct(r, 3);
    r = rinserct(r, 4);
    r = rinserct(r, 7);
    r = rinserct(r, 2);
    r = rinserct(r, 8);
    r = rinserct(r, 10);

    pais(r);

    em_ordem(r);
    cout << endl;

    Node * z = rfind(r, 5);

    Node * aux = remove(r, z);

    em_ordem(r);
    cout << endl;
    return 0;
}
