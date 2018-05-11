#include <iostream>
#include "simples_grafo.h"
using namespace std;

int main()
{
   Grafo g(5);

   for(int i = 0; i <= 5; i++)
   {
       g.addVertice(i + 1);
   }
   g.addAresta(1, 2);
   g.addAresta(1, 3);
   g.addAresta(1, 5);
   g.addAresta(2, 1);
   g.addAresta(2, 3);
   g.addAresta(2, 6);
   g.addAresta(3, 1);
   g.addAresta(3, 2);
   g.addAresta(4, 6);
   g.addAresta(5, 1);
   g.addAresta(5, 6);
   g.addAresta(6, 5);
   g.addAresta(6, 2);
   g.addAresta(6, 4);

   g.show_arestas();

   g.show_vertices();

   if(g.existe_aresta(4, 3))
       cout << "existe aresta" << endl;
   else
       cout << "não existe aresta" << endl;

   cout << endl;
   return 0;
}
