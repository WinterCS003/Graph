#include <iostream>

#include "ArrayGraph.h"


/**********************************************************
 *
 * CONSTRUCTOR ArrayGraph
 *_________________________________________________________
 * This constructor receives nothing and declares and 
 * initializes all attributes.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will initialize myGraph to -1 to indicate 
 *   that no edge exists
 ***********************************************************/
ArrayGraph::ArrayGraph()
{
  // initialize an empty graph
  myGraph = new int*[SIZE];
  for(int i = 0; i < SIZE; i++){
    myGraph[i] = new int[SIZE];
  }
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      myGraph[i][j] = -1; // indicates empty
    }
  }

  vertices = new std::string[SIZE];
  count = 0;
}

/**********************************************************
 *
 * DESTRUCTOR ~ArrayGraph
 *_________________________________________________________
 * This function receives nothing and frees memory used
 * by the program.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will free all memory used by the program
 ***********************************************************/
ArrayGraph::~ArrayGraph()
{
  for(int i = 0; i < SIZE; i++){
    delete [] myGraph[i];
  }
  delete [] myGraph;

  delete [] vertices;
}

/**********************************************************
 *
 * FUNCTION vertexIndex
 *_________________________________________________________
 * This function receives a std::string node and returns
 * the index of the node in the array. -1 is returned if
 * the node is not found in the array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     node: vertex to search for
 *          
 * POST-CONDITIONS
 *  This function returns the index of the node in the array
 *  or -1 if it does not exist.
 ***********************************************************/
int ArrayGraph::vertexIndex(std::string node) const // IN - node to search for
{
  for(int i = 0; i < count; i++){
    if(vertices[i] == node){
      return i;
    }
  }

  return -1;
}

/**********************************************************
 *
 * FUNCTION insertVertex
 *_________________________________________________________
 * This function receives an std::string node and inserts it 
 * into the heap. 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     node: unique std::string to insert into tree.
 *          
 * POST-CONDITIONS
 *  This function inserts value into the heap. If value is
 *  already in the array, or if the array is full, then an
 *  error message is printed.
 ***********************************************************/
void ArrayGraph::insertVertex(std::string node) // IN - node to insert
{
  if(count == SIZE){
    std::cout << "Graph is full" << std::endl;;
    return;
  }
  if(vertexIndex(node) != -1){
    std::cout << "Node already exists" << std::endl;
    return;
  }
 
  vertices[count++] = node;
}

/**********************************************************
 *
 * FUNCTION insertEdge
 *_________________________________________________________
 * This function receives 2 vertices and the weight of the
 * edge to conncet the vertices.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     vertex1: vertex to connect
 *     vertex2: vertex to connect
 *     weight: weight of edge
 *          
 * POST-CONDITIONS
 *  This function inserts the edge between the vertices.
 *  The function checks that both vertices exist and the edge
 *  does not already exist.
 ***********************************************************/
void ArrayGraph::insertEdge(std::string vertex1, // IN - vertexto connect
                            std::string vertex2, // IN - vertex to connect
                            int weight) // IN - weight of edge
{
  int i = vertexIndex(vertex1);
  int j = vertexIndex(vertex2);

  if(i == -1 || j == -1){
    std::cout << "Vertex does not exist" << std::endl;
    return;
  }
  if(myGraph[i][j] != -1){
    std::cout << "Edge already exists" << std::endl;
    return;
  }

  // undirected graph
  myGraph[i][j] = weight;
  myGraph[j][i] = weight;
}

/**********************************************************
 *
 * FUNCTION minDist
 *_________________________________________________________
 * This function receives an array of distances, and an 
 * array of visited nodes. The index to the node with
 * the shortest distance is returned.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *   dist: array of integer distances of all nodes
 *   visited: a boolean array of all visited nodes
 *          
 * POST-CONDITIONS
 *  This function finds node with the shortest distance and
 *  has been unvisited according to the arrays. The index to
 *  the node is returned.
 ***********************************************************/
int ArrayGraph::minDist(int dist[],           // IN - distances from source
                        bool visited[]) const // IN - all visited nodes
{
  int min = 2147483647;
  int index = -1;

  for(int i = 0; i < count; i++){
    if(!visited[i] && dist[i] < min){
      min = dist[i];
      index = i;
    }
  }

  return index;
}

/**********************************************************
 *
 * FUNCTION Dijkstra
 *_________________________________________________________
 * This function receives a source node and finds the 
 * shortest path to all other nodes.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     source: node to begin from
 *          
 * POST-CONDITIONS
 *  This function finds and prints the shortest path from
 *  the source node to all other nodes in the graph.
 ***********************************************************/
void ArrayGraph::Dijkstra(std::string source) const // IN - source node to start from
{
  int dist[count]; // shortest distance from source to all other vertices
  bool visited[count]; // keeps track of which vertices were visited
  int path[count]; // min path from source to all other vertices
  int vertex1 = vertexIndex(source);
  if(vertex1 == -1){
    std::cout << "Vertex does not exist" << std::endl;
    return;
  }
  // initialize the distance to inifiniti and all nodes to not visited
  for(int i = 0; i < count; i++){
    dist[i] = 2147483647;
    visited[i] = false;
    path[i] = -1; // value of "-1" means no path exists
  }
  dist[vertex1] = 0; // distance to the source is always 0

  // Dijkstra's Algorithm
  for(int i = 0; i < count; i++){
    int src = minDist(dist, visited); // index to node with minimum distance
    visited[src] = true;
    // Check if any adjacent node is minimum path
    for(int j = 0; j < count; j++)
    {
      if(!visited[j]           && // has not been visited before
         myGraph[src][j] != -1 && // edge exists between src and j
         dist[src] + myGraph[src][j] < dist[j]) // distance is the minimum
      {
        dist[j] = dist[src] + myGraph[src][j]; 
        path[j] = src; // points to the vertex you need to come from
      }
    }
  }

  // Print Report of all data: Source - destination, min distance and path
  std::cout << "---Dijkstra's Algorithm (starting from " << vertices[vertex1] << ")---\n" << std::endl;
  for(int i = 0; i < count; i++){
    std::cout << vertices[i] << ": " << dist[i];
    std::cout << " {" << vertices[vertex1];
    // If the destination is not the source node
    if(i != vertex1){
      std::cout << ", ";
      int j = i;
      std::string temp[count];
      int index = 0;
      while(path[j] != -1){
        temp[index++] = vertices[j];
        j = path[j];
      }
      // print in correct order
      for(int i = index-1; i > 0; i--){
        std::cout << temp[i] << ", ";
      }
      std::cout << temp[0];
    }
    std::cout << "}" << std::endl;
  }
  std::cout << "\n---End Dijkstra's Algorithm---\n\n";
}

/**********************************************************
 *
 * FUNCTION PrimMST
 *_________________________________________________________
 * This function receives a node and prints the MST using
 * Prim's algorithm starting from the given node.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     source: vertex to begin printing from
 *          
 * POST-CONDITIONS
 *  This function finds the minimum spanning tree beginning
 *  at the given node using Prim's algorithm.
 ***********************************************************/
void ArrayGraph::PrimMST(std::string source) const 
{
  int dist[count]; // shortest distance between edges
  bool visited[count]; // keeps track of which vertices were visited
  int path[count*(count-1)][2]; // min path from source to all other vertices
  int vertex1 = vertexIndex(source);
  if(vertex1 == -1){
    std::cout << "Vertex does not exist" << std::endl;
    return;
  }
  // initialize the distance to inifiniti and all nodes to not visited
  for(int i = 0; i < count; i++){
    dist[i] = 2147483647;
    visited[i] = false;
    path[i][0] = -1; // value of "-1" means no path exists
    path[i][1] = -1;
  }
  dist[vertex1] = 0; // distance to the source is always 0

  int index = 0;
  // Dijkstra's Algorithm
  for(int i = 0; i < count; i++){
    int src = minDist(dist, visited); // index to node with minimum distance
    visited[src] = true;
    // Check if any adjacent node is minimum path
    for(int j = 0; j < count; j++)
    {
      if(!visited[j]           && // has not been visited before
         myGraph[src][j] != -1 && // edge exists between src and j
         myGraph[src][j] < dist[j]) // distance is the minimum
      {
        dist[j] = myGraph[src][j];
        path[index][0] = src;
        path[index++][1] = j;
      }
    }
  }

  printReport(path, index);
}


/**********************************************************
 *
 * FUNCTION printReport
 *_________________________________________________________
 * This function receives a 2D array of all paths, and the
 * number of rows of the array. The shortest paths are 
 * printed. Prim's algorithm uses this function.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     path: 2D array of all found paths by Prim's algorithm
 *     size: number of rows in path array
 *          
 * POST-CONDITIONS
 *  This function prints only the shortest paths to create 
 *  the MST using the given parameters.
 ***********************************************************/
void ArrayGraph::printReport(int path[][2],  // IN - all connections found by Prim's
                             int size) const // IN - rows in path
{
  std::cout << "---Prim's Algorithm---" << std::endl;
  int src;
  int dest;
  int index = 1;
  bool minDist;
  int minimum = 0;
  std::cout << std::endl;
  for(int i = 0; i < size; i++){
    src = path[i][0];
    dest = path[i][1];
    minDist = true;
    for(int j = 0; j < size; j++){
      if(i != j && dest == path[j][1]){
        if(myGraph[path[j][0]][path[j][1]] < myGraph[src][dest]){
          minDist = false;
          break;
        }
      }
    }
    if(minDist){
      minimum += myGraph[src][dest];
      std::cout << index++ << ": (" << vertices[src] << ", " << vertices[dest]<< ") " << myGraph[src][dest] << std::endl;
    }
  }
  std::cout << "\nMinimum Distance: " << minimum << std::endl;
  std::cout << "\n---End Report---\n" << std::endl;
}

/**********************************************************
 *
 * FUNCTION getConnection
 *_________________________________________________________
 * This function receives a target and an array of 
 * connections for all vertices. The index to the node the 
 * target is conencted to is returned.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     target: vertice to find
 *     connections: connections of all vertices
 *          
 * POST-CONDITIONS
 *  This function prints the index to the node that the 
 *  node target is connected to.
 ***********************************************************/
int ArrayGraph::getConnection(int target,              // IN - target to search for
                              int connections[]) const // IN -connections of all nodes
{
  while(connections[target] != target){
    target = connections[target];
  }
  return target;
}

/**********************************************************
 *
 * FUNCTION KruskalMST
 *_________________________________________________________
 * This function receives nothing and finds the MST of
 * the graph using Kruskal's algorithm.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *          
 * POST-CONDITIONS
 *  This function uses Kruskal's algorithm to find the 
 *  minimum spanning tree of the graph.
 ***********************************************************/
void ArrayGraph::KruskalMST() const 
{
  std::cout << "---Kruskal's Algorithm---\n" << std::endl;
  int connections[count];

  for(int i = 0; i < count; i++){
    connections[i] = i; // all nodes  are connected only to themselves at first
  }
  
  int num = 1;
  int total = 0;
  while(num < count){
    int min = 2147483647;
    int index1 = -1;
    int index2 = -1;
    for(int src = 0; src < count; src++){
      for(int dest = 0; dest < count; dest++){
        if(getConnection(src, connections) != getConnection(dest, connections) && 
           myGraph[src][dest] != -1)
        {
          if(myGraph[src][dest] < min){
            min = myGraph[src][dest];
            index1 = src;
            index2 = dest;
          }
        }
      }
    }
    std::cout << num++ << ": (" << vertices[index1] << ", " << vertices[index2] << ") " << min << std::endl;
    total += min;
    connections[getConnection(index1, connections)] = connections[getConnection(index2, connections)];
  }
  std::cout << "\nMinimum Distance: " << total << std::endl;
  std::cout << "\n---End Report---\n" << std::endl;
}