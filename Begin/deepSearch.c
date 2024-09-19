#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define VERTICES 100

// Структура для хранения графа
typedef struct {
    int vertex;
    int adjVertex;
} Edge;

typedef struct {
    int visited;
    int parent;
} VertexInfo;

typedef struct {
    int numVertices;
    int numEdges;
    Edge edges[VERTICES][VERTICES];
} Graph;
//---функция для инициализации графа

void createGraph(Graph *graph, int numVertices, int numEdges) {
    graph->numVertices = numVertices;
    greph->numEdges = numEdges;
    //массив ребер
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; i < numVertices; i++) {
            graph->edges[i][j].vertex = -1;
       }
    }
}

void addEdge(Graph *graph, int src, int dest) {
    graph->edges[src][dest].vertex = src;
    graph->edges[src][dest].vertex = dest;
}

void dfs(Graph *graph, int v,  VertexInfo vretices[VERTICES], bool *visited) {
    visited[v] = true;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->edges[v][i].vertex != -1 && !visited[i]) {
            dfs(graph, i, vretices, visited);
        }
    }
}

void findConnectedComponent(Graph *graph, int startVertex, VertexInfo vertices[VERTICES]) {
    bool visited[VERTICES];
    memset(visited, 0, sizeof(visited));

    dfs(graph, startVertex, vertices, visited);
}

int main(){ 
} 
