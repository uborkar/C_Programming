
#include <stdio.h>
#include <stdlib.h>
// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100
// Define the structure for a node in the adjacency list
typedef struct Node {
 int vertex;
 struct Node* next;
} Node;
// Define the structure for the graph
typedef struct Graph {
 Node* adjLists[MAX_VERTICES];
 int numVertices;
} Graph;
// Function prototypes
void initializeGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void bfs(Graph* graph, int startVertex);
void dfs(Graph* graph, int startVertex);
void dfsRecursive(Graph* graph, int vertex, int visited[]);
int main() {
 Graph graph;
 int i,vertices, edges, src, dest, startVertex;
 // Input number of vertices and edges
 printf("Enter the number of vertices: ");
 scanf("%d", &vertices);
 initializeGraph(&graph, vertices);
 printf("Enter the number of edges: ");
 scanf("%d", &edges);
 // Input edges
 for (i = 0; i < edges; i++) {
 printf("Enter edge (src dest): ");
 scanf("%d %d", &src, &dest);
 addEdge(&graph, src, dest);
 }
 // Print the graph
 printGraph(&graph);
 // BFS
 printf("Enter the starting vertex for BFS: ");
 scanf("%d", &startVertex);
 printf("BFS starting from vertex %d: ", startVertex);
 bfs(&graph, startVertex);
 printf("\n");
 // DFS
 printf("Enter the starting vertex for DFS: ");
 scanf("%d", &startVertex);
 printf("DFS starting from vertex %d: ", startVertex);
 dfs(&graph, startVertex);
 printf("\n");
 return 0;
}
// Function to initialize the graph
int i;
void initializeGraph(Graph* graph, int vertices) {
 graph->numVertices = vertices;
 for (i = 0; i < vertices; i++) {
 graph->adjLists[i] = NULL;
 }
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->vertex = dest;
 newNode->next = graph->adjLists[src];
 graph->adjLists[src] = newNode;

 // For undirected graph, add edge in both directions
 newNode = (Node*)malloc(sizeof(Node));
 newNode->vertex = src;
 newNode->next = graph->adjLists[dest];
 graph->adjLists[dest] = newNode;
}
// Function to print the graph
int i;
void printGraph(Graph* graph) {
 for (i = 0; i < graph->numVertices; i++) {
 Node* temp = graph->adjLists[i];
 printf("Vertex %d: ", i);
 while (temp) {
 printf("%d -> ", temp->vertex);
 temp = temp->next;
 }
 printf("NULL\n");
 }
}
// Function to perform BFS
void bfs(Graph* graph, int startVertex) {
 int visited[MAX_VERTICES] = {0};
 int queue[MAX_VERTICES];
 int front = 0, rear = 0;
 visited[startVertex] = 1;
 queue[rear++] = startVertex;
 while (front < rear) {
 int currentVertex = queue[front++];
 printf("%d ", currentVertex);
 Node* adjList = graph->adjLists[currentVertex];
 while (adjList) {
 int adjVertex = adjList->vertex;
 if (!visited[adjVertex]) {
 visited[adjVertex] = 1;
 queue[rear++] = adjVertex;
 }
 adjList = adjList->next;
 }
 }
}
// Function to perform DFS
void dfs(Graph* graph, int startVertex) {
 int visited[MAX_VERTICES] = {0};
 dfsRecursive(graph, startVertex, visited);
}
// Recursive function to perform DFS
void dfsRecursive(Graph* graph, int vertex, int visited[]) {
 visited[vertex] = 1;
 printf("%d ", vertex);
 Node* adjList = graph->adjLists[vertex];
 while (adjList) {
 int adjVertex = adjList->vertex;
 if (!visited[adjVertex]) {
 dfsRecursive(graph, adjVertex, visited);
 }
 adjList = adjList->next;

}
}



