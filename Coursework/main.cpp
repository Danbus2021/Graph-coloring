#include "Graph.h"


int main(int argc, char* argv[]) {
   
    Graph g1;
    g1.read_graph("input1.txt");
   // g1.read_graph(argv[1]);
    g1.overkill();
 //  g1.greedy();
    g1.write_dot("g.dot");
   // string command = ("dot g.dot -Tpng -o ");
    //command += argv[2];
    //system(command.c_str());
    system("dot g.dot -Tpng -og.png");
    g1.write_coloring("output.txt");

    
    Graph g2;
    g2.read_graph("input2.txt");
    g2.greedy();
    g2.write_dot("g1.dot");
    system("dot g1.dot -Tpng -og1.png");
    g2.write_coloring("output1.txt");
/*
    Graph g3;
    g3.read_graph("input2.txt");
    g3.greedy();
    g3.write_dot("g2.dot");
    system("dot g2.dot -Tpng -og2.png");
    g3.write_coloring("output2.txt");
    return 0;
    */
    return 0;
}