 #include <iostream>

using namespace std;

//estrutura dos vertices
struct Node
{
    int value; //valor associado a cada vertice
    Node * next; //usado para a lista de vertices do grafo
    Node * adj; //ponteiro para os vertices vizinhos

    Node(int value = 0, Node * next = nullptr, Node * adj = nullptr)
    {
        this->value = value;
        this->next = next;
        this->adj = adj;
    }
};

struct Grafo
{
    int n;
    Node * adj;

    //cria o grafo
    Grafo(int n)
    {
        this->n = n;
        this->adj = nullptr;
    }

    //Imprime todos os vertices do grafo
    void show_vertices()
    {
        Node * node = adj;
        while(node != nullptr)
        {
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    //Verifica se um vertice existe no grafo
    bool existe_vertice(int v)
    {
        Node * node = adj;
        if(node == nullptr)
        {
            return false;
        }

        while(node != nullptr)
        {
            if(node->value == v)
            {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    //Adiciona um vertice ao grafo
    void addVertice(int value)
    {
        if(adj == nullptr)
        {
            Node * node = new Node(value, nullptr);
            adj = node;

            return;
        }

        Node * node = adj;
        while(node->next != nullptr)
        {
            node = node->next;
        }

        node->next = new Node(value, nullptr);
        return;
    }

    //Busca um vertice especifico
    Node * busca_vertice(int v)
    {
        if(adj == nullptr)
        {
            return nullptr;
        }
        if(adj->value == v)
        {
            return adj;
        }

        Node * node = adj;

        while(node != nullptr)
        {
            if(node->value == v)
            {
                return node;
            }
            node =node->next;
        }

        return nullptr;
    }

    //Adiciona uma aresta ao grafo
    void addAresta(int v, int u)
    {
        if(!existe_vertice(v) && !existe_vertice(u))
        {
            return;
        }

        Node * aux = busca_vertice(v);
        if(aux->adj == nullptr)
        {
            Node * node  = new Node(u, nullptr);
            aux->adj = node;
            return;
        }

        Node * node = aux->adj;
        while(node->next != nullptr)
        {
            node = node->next;
        }
        node->next = new Node(u, nullptr);
    }

    //Imprime todas as arestas do grafo
    void show_arestas()
    {
        Node * node = this->adj;

        while(node != nullptr)
        {
            Node * aux = node->adj;
            while(aux != nullptr)
            {
                cout << "(" << node->value << ", " << aux->value << ")" << " ";
                aux= aux->next;
            }
            cout << endl;
            node = node->next;
        }
        cout << endl;
    }

    //Verifica se uma aresta especifica existe
    bool existe_aresta(int v, int u)
    {
        Node * node = busca_vertice(v);
        if(node->adj == nullptr)
        {
            return false;
        }

        Node * aux = node->adj;
        while(aux != nullptr)
        {
            if(aux->value == u)
            {
                return true;
            }
            aux = aux->next;
        }

        delete aux;
        return false;
    }
};
