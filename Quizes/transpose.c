//////////////////////////
// Frendy Lio
// EE 362
// Midterm 2 -- Problem 8
/////////////////////////

#include <stdlib.h>
#include <stdio.h>

#define NUMNODES 4

/* Struct for a vertex in the adjacency list of a graph */
struct vertex {
   int value;
   struct vertex * next;
};

/* struct for a graph */
struct graph {
   int numnodes;  /* Number of nodes */
   struct vertex ** adj;  /* adj[k] is the adjacency list for node k */
};

/* Create a graph with n nodes but no edges */
struct graph * create_empty_graph(int n) 
{
struct graph * g = (struct graph *) malloc(sizeof(struct graph));
g->adj = (struct vertex **) malloc(n*sizeof(struct vertex *));
for (int k=0; k<n; k++) { /* Initialize adjacency list */
   g->adj[k] = NULL;
}
g->numnodes = n;
return g;
}

/* Insert an edge (u,v) into graph g */
void insert_edge(struct graph *g, int u, int v)
{
struct vertex * new_node;
     /* Check if nodes are valid */
if (u < 0 || u >= g->numnodes) return;
if (v < 0 || v >= g->numnodes) return;

     /* Insert v at the head of node u's linked list */
new_node = (struct vertex *) malloc(sizeof(struct vertex));
new_node->value = v;
new_node->next = g->adj[u];
g->adj[u] = new_node;
}

/* Display  the adjacency list of a graph g */ 
void display_adjlist(struct graph *g)
{
printf("Adjacency list of graph with %d nodes\n",g->numnodes);
for  (int k=0; k<g->numnodes; k++) {
   printf("   Node %d: ",k);
   for (struct vertex * u=g->adj[k]; u!=NULL; u=u->next) {
      printf("->(%d)",u->value);
   }
   printf("\n");
}
}

/* Create a graph G */
struct graph * create_graph() 
{
struct graph * g = create_empty_graph(NUMNODES);
insert_edge(g, 0, 2);
insert_edge(g, 0, 3);
insert_edge(g, 1, 0);
insert_edge(g, 1, 2);
insert_edge(g, 2, 3);
insert_edge(g, 3, 0);
return g;
}

/* Create the transpose of graph G */
struct graph * create_transpose(struct graph * g)
{
struct graph * t;
t = create_empty_graph(g->numnodes);

// Declare variables for values
int CurrentVertex;
int CurrentAdjacent;

//  Go through all nodes
for  (int k=0; k<g->numnodes; k++) {
   // Get Current value of node
   CurrentVertex = k;

   // Go through each adjacent node
   for (struct vertex * u=g->adj[k]; u!=NULL; u=u->next) {
      // Get Current value of adjacent node
      CurrentAdjacent = u->value;

      // Create edges (Connections)
      insert_edge(t, CurrentAdjacent, CurrentVertex);
   }   
}

return t;
}


int main()
{
struct graph * g = create_graph();
printf("\nGraph:\n"); 
display_adjlist(g);

struct graph * t = create_transpose(g);
printf("\nTranspose graph:\n"); 
display_adjlist(t);
}

