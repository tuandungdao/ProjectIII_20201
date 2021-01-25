/*
 * Graph.h
 *
 *  Created on: Nov 27, 2020
 *      Author: USER
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

using namespace std;

class Graph{
    public:
        int V;
        int E;

        vector<int> *adj;

        int degree(int u);
        virtual vector<int> hosts();
        virtual vector<int> switches();
        virtual void addEdge(int v, int w);

    private:
        void validateVertex(int v);
};

#endif /* GRAPH_H_ */
