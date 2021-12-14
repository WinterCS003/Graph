#ifndef ARRAYGRAPH_H_
#define ARRAYGRAPH_H_

const int SIZE = 20; // max size of graph is 20 vertices

class ArrayGraph{
  private:
    std::string* vertices; // array of all vertices
    int** myGraph;         // dynamic 2D array implementation of edges
    int count;             // number of vertices

  /**********************
   ** ACCESSOR HELPERS **
   **********************/
    int vertexIndex(std::string node) const; // finds index of a vertex
    int minDist(int dist[], bool visited[]) const; // Finds node with minimum distance
    void printReport(int path[][2], int size) const; // prints MST for Prim's
    int getConnection(int target, int connections[]) const; // keeps track of how the nodes are connected - for Kruskal's

  public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
    ArrayGraph();  // constructor
    ~ArrayGraph(); // destructor

  /***************
   ** ACCESSORS **
   ***************/
    void Dijkstra(std::string source) const; // finds shortest path from source to all other nodes
    void PrimMST(std::string source) const; // Finds MST using Prim's 
    void KruskalMST() const;                // Finds MST using Kruskal's

  /**************
   ** MUTATORS **
   **************/
    void insertVertex(std::string node); // inserts a new vertex
    void insertEdge(std::string vertex1, std::string vertex2, int weight); // connect both vertices
};

#endif // ARRAYGRAPH_H_

/****************************************************************
 * ArrayGraph Class
 *   This class represents a graph  implemented using an dynamic
 *   adjacency matrix. This class manages a vertices attribute, 
 *   which keeps track of the nodes of the graph, myGraph a 
 *   2 Dimensional adjacency matrix, and a cound of how many nodes
 *   are in the graph.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * ArrayGraph();
 *   Constructor; Initializes all attributes. Graph has -1 to 
 *                represent empty edge
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~ArrayGraph();
 *   Destructor; Deletes the dynamic arrays verties and myGraph
 *   Parameters: none
 *   Return: none
 ***************************************************************/
 
/**********************
 ** ACCESSOR HELPERS **
 **********************/
 
/****************************************************************
* int vertexIndex(std::string node) const; 
*
*   Accessor; This method will find and return the index of 
*             the target node in the graph. -1 is returned if it
*             does not exist.
* --------------------------------------------------------------
*   Parameters: target (std::string) // IN - value to search for
* --------------------------------------------------------------
*   Return: index (int)
***************************************************************/
 
/********************************************************************
* int minDist(int dist[], bool visited[]) const; 
*
*   Accessor; This method will find and return the index of 
*             the node in the graph that has not been visited
*             and has the shortest distance from the source.
*             Used by Dijkjstra's and Prim's
* ------------------------------------------------------------------
*   Parameters: dist][] (int) // IN - array of distances from source 
*               visited[] (bool) // IN - array of visited nodes
* ------------------------------------------------------------------
*   Return: index (int)
********************************************************************/
 
/****************************************************************
* void printReport(int path[][2], int size) const; 
*
*   Accessor; This method will print all nodes and their distance
*             and path from the source node. Used by Dijkstra's 
*             algorithm
* --------------------------------------------------------------
*   Parameters: path[][2] (int) // IN - 2D array of indexes
*               size (int) // IN - number of rows in array
* --------------------------------------------------------------
*   Return: none
***************************************************************/

/****************************************************************
* int getConnection(int target, int connections[]) const; 
*
*   Accessor; This method will return what node's index the 
*             target is connected to given an array of 
*             connections
* --------------------------------------------------------------
*   Parameters: target (int) // IN - value to search for
*               connections[] (int) // IN - array of all connections
* --------------------------------------------------------------
*   Return: index (int) - index target is connected to
***************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void insertVertex(std::string node); 
 *
 *   Mutator; This method will insert the parameter node into the
 *            graph. Vertices array is updated
 *------------------------------------------------------------------
 *   Parameter: node (std::string) // IN - value to insert
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void insertEdge(std::string vertex1, std::string vertex2, int weight);
 *
 *   Mutator; This method will insert an edge with the given weight
 *            that connects the two vertices together.
 *------------------------------------------------------------------
 *   Parameter: vertex1 (std::string) // IN - vertex to connect
 *              vertex2 (std::string) // IN - vertex to connect
 *              weight (int) // IN - weight of edge
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void Dijkstra(std::string source) const; 
 *
 *   Accessor; This method will find the shortest route from
 *             the given source node to all other nodes
 * --------------------------------------------------------------
 *   Parameters: source (std::string) // IN - node to start from
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void PrimMST(std::string source) const; 
 *
 *   Accessor; This method will find the Minimum Spanning Tree
 *             beginning at the given source node using Prim's
 *             algorithm.
 * --------------------------------------------------------------
 *   Parameters: source (std::string) // IN - node to start from
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void KruskalMST() const; 
 *
 *   Accessor; This method will find the Minimum Spanning Tree
 *             using Kruskal's algorithm.
 * --------------------------------------------------------------
 *   Parameters: source (std::string) // IN - node to start from
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
