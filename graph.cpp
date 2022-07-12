// Programa em C++
// Componente = vértices
#include <bits/stdc++.h>

using namespace std;

// Função do Algoritmo Floyd Warshall
void floydWarshall(vector<vector<int>> &graph, int N)
{

    // Para cada vértice do grafo encontre
    // a menor distância com  outros vértices
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {

                    // Atualiza a distância entre vértice i e j
                    // k como um vértice intermediário
                    // faz uma distância menor
                    if (graph[i][k] + graph[k][j] < graph[i][j])

                        graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

// Abaixo a função dfs(busca em profundidade) será usada para
// obter os componentes conectados de um
// grafo e armazenar todos os nós no componente
void dfs(int src, vector<bool> &visited, vector<vector<int>> &graph,
         vector<int> &component, int N)
{

    // Marca este vértice como visitado
    visited[src] = true;

    // Coloca este nó no vetor componente
    component.push_back(src);

    // Para todos os outros vértices no grafo
    for (int dest = 0; dest < N; dest++)
    {

        // Se houver uma aresta entre
        // src e dest, ou seja, o valor
        // do grafo[u][v]!=INT_MAX
        if (graph[src][dest] != INT_MAX)
        {

            // Se não visitamos dest
            // então aplica recursivamente
            // dfs no destino
            if (!visited[dest])
                dfs(dest, visited, graph, component, N);
        }
    }
}

// Função para encontrar o máximo mais curto
// distância do caminho em um componente verificando
// as distâncias mais curtas entre todos
// possíveis pares de nós
int maxComponente(vector<int> &component, vector<vector<int>> &graph)
{
    int maxDistance = INT_MIN;
    int n = component.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            maxDistance = max(maxDistance,
                              graph[component[i]][component[j]]);
        }
    }

    // Se a maxDistance ainda for INT_MIN
    // então retorna 0 porque este componente
    // tem um único elemento
    return (maxDistance == INT_MIN ? 0 : maxDistance);
}

// A função abaixo usa os dois métodos dfs e floydWarshall
// para obter as distâncias máximas mais curtas
// em cada componente do grafo a
// função retorna um vetor, onde cada
// elemento denota o caminho mais curto máxima
// distância de um componente
vector<int> distanciaMaxCurta(vector<vector<int>> &graph, int N)
{

    // Localiza os componentes conectados
    vector<bool> visited(N, false);
    vector<vector<int>> components;

    // Para armazenar os nós em um
    // componente específico
    vector<int> temp;

    // Agora, para cada nó não visitado, execute
    // o dfs para obter o conectado
    // componente com este nó não visitado
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {

            //Limpe o temp
            temp.clear();
            dfs(i, visited, graph, temp, N);
            components.push_back(temp);
        }
    }

    // Agora, para todos os pares, encontre o menor
    // distâncias de caminho usando Floyd Warshall
    floydWarshall(graph, N);

    // Agora para cada componente encontre o
    // distância máxima mais curta e
    // armazena no resultado
    vector<int> result;
    int numOfComp = components.size();
    int maxDistance;
    for (int i = 0; i < numOfComp; i++)
    {
        maxDistance = maxComponente(components[i], graph);
        result.push_back(maxDistance);
    }
    return result;
}

int main()
{
    int N = 8;
    const int inf = INT_MAX;

    // Matriz de Adjacência para o primeiro
    // grafo direcionado
    vector<vector<int>> graph1 = {
        {0, inf, 9, inf, inf, inf, 3, inf},
        {inf, 0, inf, 10, 1, 8, inf, inf},
        {9, inf, 0, inf, inf, inf, 11, inf},
        {inf, 10, inf, 0, 5, 13, inf, inf},
        {inf, 1, inf, 5, 0, 3, inf, inf},
        {8, inf, inf, 13, 3, 0, inf, inf},
        {3, inf, 11, inf, inf, inf, 0, inf},
        {inf, inf, inf, inf, inf, inf, inf, 0},
    };
    // grafo não direcionado
    vector<vector<int>> graph2 = {
        {0, inf, 0, inf, inf, inf, 3, inf},
        {inf, 0, inf, 0, 1, 8, inf, inf},
        {9, inf, 0, inf, inf, inf, 11, inf},
        {inf, 10, inf, 0, 5, 13, inf, inf},
        {inf, 1, inf, 0, 0, 3, inf, inf},
        {0, inf, inf, 0, 0, 0, inf, inf},
        {0, inf, 0, inf, inf, inf, 0, inf},
        {inf, inf, inf, inf, inf, inf, inf, 0},
    };

    // Encontra as distâncias máximas mais curtas
    vector<int> result1 = distanciaMaxCurta(graph1, N);
    vector<int> result2 = distanciaMaxCurta(graph2, N);

    // Imprimindo o caminho máximo mais curto
    // distâncias para cada componente
    for (int mx1 : result1)
        cout << mx1 << ' ';

    return 0;
    for (int mx2 : result2)
        cout << mx2 << ' ';

    return 0;
}
