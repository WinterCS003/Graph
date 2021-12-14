/******************************************************************
 * AUTHORS  : Jaemok C. Lee
 * LAB #005 : Dijkstra's Algorithm and MST
 * CLASS    : CS 008 Data Structures
 * SECTION  : 6:30p - 8:35
 * DUE DATE : 05/2/2021
 ******************************************************************/

#include <iostream>

#include "ArrayGraph.h"

/************************************************************
*
* Dijkstra's Algorithm and MST 
*___________________________________________________________
* This program implements a graph using an adjacency
* matrix and implements Dijkstra's algorithm as well as
* Prim's and Kruskal's algorithms to find the MST.
*___________________________________________________________
* INPUTS:
*   This graph stores city names as vertices and distances
*   between each city as edges.
*
* OUTPUTS:
*   The user can print the shortest distance from a specified
*   node to all other nodes. The user can also print the 
*   shortest route that connects all nodes in the graph.
*************************************************************/
int main() {
  ArrayGraph test1;

  test1.insertVertex("Seattle");
  test1.insertVertex("San Francisco");
  test1.insertVertex("Denver");
  test1.insertVertex("Chicago");
  test1.insertVertex("Boston");
  test1.insertVertex("Los Angeles");
  test1.insertVertex("Kansas City");
  test1.insertVertex("New York");
  test1.insertVertex("Dallas");
  test1.insertVertex("Atlanta");
  test1.insertVertex("Houston");
  test1.insertVertex("Miami");

  test1.insertEdge("Seattle", "San Francisco", 807);
  test1.insertEdge("Boston", "New York", 214);
  test1.insertEdge("Seattle", "Denver", 1331);
  test1.insertEdge("Seattle", "Chicago", 2097);
  test1.insertEdge("San Francisco", "Denver", 1267);
  test1.insertEdge("Denver", "Chicago", 1003);
  test1.insertEdge("Chicago", "Boston", 983);
  test1.insertEdge("San Francisco", "Los Angeles", 381);
  test1.insertEdge("Los Angeles", "Denver", 1015);
  test1.insertEdge("Denver", "Kansas City", 599);
  test1.insertEdge("Kansas City", "Chicago", 533);
  test1.insertEdge("Chicago", "New York", 787);
  test1.insertEdge("New York", "Atlanta", 888);
  test1.insertEdge("Kansas City", "New York", 1260);
  test1.insertEdge("Los Angeles", "Kansas City", 1663);
  test1.insertEdge("Kansas City", "Atlanta", 864);
  test1.insertEdge("Kansas City", "Dallas", 496);
  test1.insertEdge("Los Angeles", "Dallas", 1435);
  test1.insertEdge("Dallas", "Atlanta", 781);
  test1.insertEdge("Dallas", "Houston", 239);
  test1.insertEdge("Houston", "Atlanta", 810);
  test1.insertEdge("Atlanta", "Miami", 661);
  test1.insertEdge("Houston", "Miami", 1187);

  test1.Dijkstra("Seattle"); // test Dijkstra's algorithm
  test1.PrimMST("Seattle");  // test Prim's algorithm
  test1.KruskalMST();        // test Kruskal's algorithm

  return 0;
}