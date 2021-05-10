#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief    Breadth-First Search Algorithm - Recursive Implementation
 *          
 *           BFS is an algorithm for traversing or searching
 *          tree or graph data structures. It starst at tht tree
 *          root (or some arbitrary node of a graph, sometimes 
 *          referred to as "search key") and explores the neighbor
 *          nodes first before moving to the next-level neigbours.
 * 
 *           BFS is a graph traversak algorithm that explores vertices
 *          in the order of their distance from the source vertex, where
 *          distance is the minimum length of a path from the source vertex
 *          to the node.
 * 
 *           Applications:
 *              - Copying garbage collection, Chenney's Algo
 *              - Finding the shortest path between two nodes u and v,
 *              with path length measured by the total number of edges
 *              (an advantage over depth-first search)
 *              - Testing a graph for bipartiteness
 *              - Minimum spanning tree for an unweighted graph
 *              - Web crawler
 *              - Finding nodes in any connected component of a graph
 *              - For-Fulkerson method for computing flow in a flor
 *              network
 *              - Serialization/Deserialization of a binary tree vs 
 *              serialization in sorted order allows the tree to be 
 *              reconstructed efficiently
 *              
 *          https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *          https://www.techiedelight.com/breadth-first-search/
 */
    
/**
 * \typedef  Edge   
 * 
 * \brief  Data structure to store a graph edge  
 */
struct Edge {
    int src, dest;
};
 
/**
 * \class  Graph   
 * 
 * \brief  A class to represent a graph object  
 */
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    std::vector<std::vector<int>> adjList;
 
    // Graph Constructor
    Graph(std::vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
/**
 * \fn   
 * 
 * \brief  Perform BFS recursively on the graph      
 */
void recursiveBFS(Graph const &graph, std::queue<int> &q, std::vector<bool> &discovered){
    if (q.empty()) {
        return;
    }
 
    // dequeue front node and print it
    int v = q.front();
    q.pop();
    std::cout << v << " ";
 
    // do for every edge `v —> u`
    for (int u: graph.adjList[v]){
        if (!discovered[u]){
            // mark it as discovered and enqueue it
            discovered[u] = true;
            q.push(u);
        }
    }
 
    recursiveBFS(graph, q, discovered);
}







/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Breadth-First Search Algorithm - Recursive Implementation: " << std::endl;
    /*Declare, init and run*/
    std::vector<Edge> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
        // vertex 0, 13, and 14 are single nodes
    };
 
    // total number of nodes in the graph
    int N = 15;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    std::vector<bool> discovered(N, false);
 
    // create a queue for doing BFS
    std::queue<int> q;
 
    // Perform BFS traversal from all undiscovered nodes to
    // cover all unconnected components of a graph
    for (int i = 0; i < N; i++){
        if (discovered[i] == false){
            // mark the source vertex as discovered
            discovered[i] = true;
 
            // enqueue source vertex
            q.push(i);
 
            // start BFS traversal from vertex `i`
            recursiveBFS(graph, q, discovered);
        }
    }


    return 0;
}