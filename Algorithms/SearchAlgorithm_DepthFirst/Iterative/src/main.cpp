#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

/**
 * \brief    Depth-First Search Algorithm - Iterative Implementation
 *          
 *           DFS is an algorithm for traversing or searching tree or graph data structures.
 *          One starts at the root (selecting some arbitrary node as the root for
 *          a graph) and explore as far as possible along each branch before backtracking.-
 * 
 *           Applications:
 *              - Finding connected components in a graph
 *              - Topological sorting in a DAG
 *              - Finding 2/3 connected components
 *              - Finding the bridge of a graph
 *              - Finding strongly connected components
 *              - Finding biconnectivity in graphs
 *              
 *          https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *          https://www.techiedelight.com/depth-first-search/
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
 * \brief  Perform DFS on the graph 'g' starting from vertex `v`      
 */
void iterativeDFS(Graph const &graph, int v, std::vector<bool> &discovered){
    // create a stack used to do iterative DFS
    std::stack<int> stack;
 
    // push the source node into the stack
    stack.push(v);
 
    // loop till stack is empty
    while (!stack.empty()){
        // Pop a vertex from the stack
        v = stack.top();
        stack.pop();
 
        // if the vertex is already discovered yet,
        // ignore it
        if (discovered[v]) {
            continue;
        }
 
        // we will reach here if the popped vertex `v`
        // is not discovered yet; print it and process
        // its undiscovered adjacent nodes into the stack
        discovered[v] = true;
        std::cout << v << " ";
 
        // do for every edge `v —> u`
        // we are using reverse iterator (Why?)
        for (auto it = graph.adjList[v].rbegin(); it != graph.adjList[v].rend(); it++){
            int u = *it;
            if (!discovered[u]) {
                stack.push(u);
            }
        }
    }
}








/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Depth-First Search Algorithm - Iterative Implementation: " << std::endl;
    /*Declare, init and run*/
    // vector of graph edges as per the above diagram
    std::vector<Edge> edges = {
        // Notice that node 0 is unconnected
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
        // , {6, 9} // introduce a cycle
    };
 
    // total number of nodes in the graph (0–12)
    int N = 13;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    std::vector<bool> discovered(N);
 
    // Do iterative DFS traversal from all undiscovered nodes to
    // cover all unconnected components of a graph
    for (int i = 0; i < N; i++)
    {
        if (discovered[i] == false) {
            iterativeDFS(graph, i, discovered);
        }
    }


    return 0;
}