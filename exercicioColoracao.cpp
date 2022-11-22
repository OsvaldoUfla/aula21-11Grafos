#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define NAO_VISITADO 0

// Raiz da DFS
    int raiz;

/*
 * Parametros:
 *  u -> vertice a ser explorado
 *  lista_adj -> lista de adjacencia, que modela o grafo
 *  d -> vetor dos tempos de descoberta pre-ordem de todos os vertices
 *  pai -> vetor com os pais de todos os vertices
 *  cont_dfs -> contador do tempo de descoberta em profundidade dos vertices
 *  filhos_raiz -> conta quantos filhos a raiz possui na DFS
 */
void tarjan(int u, vector<int>* lista_adj, int* d, int* pai, int& cont_dfs, int& filhos_raiz)
{
    d[u] = cont_dfs++;
    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
    {
        int v = *it;
        if(d[v] == NAO_VISITADO)
        {
            pai[v] = u;
     
            if(u == raiz)
            {
                filhos_raiz++;
            }
        
            tarjan(v, lista_adj, d, pai, cont_dfs, filhos_raiz);
        
        }
     
    }
}

int main()
{  
    

  int n, m;
  cin >> n >> m;

  while(n != 0)
  {
    // alocando as estruturas auxiliares
    int* d = new int[n];
    int* pai = new int[n];
    int cont_dfs = 0;
    int filhos_raiz = 0;
   
   
    // iniciando as estruturas auxiliares
    for(int i = 0; i < n; i++)
    {
        d[i] = NAO_VISITADO;
        pai[i] = -1;
    }
   
    vector<int>* lista_adj = new vector<int>[n];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
      {
        continue;
      }

      // grafo nao-orientado
      lista_adj[u].push_back(v); //u -> v
      lista_adj[v].push_back(u); //v -> u
    }

    for(int i = 0; i < n; i++)
    {
        if(d[i] == NAO_VISITADO)
        {
            raiz = i;
            filhos_raiz = 0;
            tarjan(i, lista_adj, d, pai, cont_dfs, filhos_raiz);
        }
    }
   
   
    delete[] pai;
    delete[] d;
   
    cin >> n >> m;
  }

  cout << "*****" << endl;

  return 0;
}