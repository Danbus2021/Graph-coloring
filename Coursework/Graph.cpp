#include "Graph.h"

void Graph::read_graph(const string& fname) {
    ifstream fin(fname);
    fin >> vertex;

    graph = new bool* [vertex];
    for (int i = 0; i < vertex; i++) {
        graph[i] = new bool[vertex];
        for (int j = 0; j < vertex; j++) {
            graph[i][j] = 0;
        }
    }
    int from;

    for (int i = 0; fin; i++) {
        for (int j = 0; fin; j++) {
            fin >> from;
            if (from == 1)
                graph[i][j] = 1;

            else if (from == 0) graph[i][j] = 0;

            char a = fin.get();
            if (a == '\n')
                break;
        }
    }
    fin.close();
}

int Graph::search_degree(int ver) {
    int count = 0;

    for (int j = 0; j < vertex - 1; j++)
        if (graph[ver][j] == 1)
            count++;

    return count;
}



string Graph::generator_colour(int n) {
    string a = "[style = filled, fillcolor = DeepPink];";
    string b = "[style = filled, fillcolor = Lime];";
    string c = "[style = filled, fillcolor = MediumSlateBlue];";
    string d = "[style = filled, fillcolor = Gainsboro];";
    string e = "[style = filled, fillcolor = DimGrey];";
    string f = "[style = filled, fillcolor = LightSlateGray];";
    string g = "[style = filled, fillcolor = DarkSlateGray];";
    string h = "[style = filled, fillcolor = Black];";
    string jj = "[style = filled, fillcolor = MistyRose];";
    string jjj = "[style = filled, fillcolor = Azure];";
    string kd = "[style = filled, fillcolor = Navy];";
    string l = "[style = filled, fillcolor = Olive];";
    string m = "[style = filled, fillcolor = Teal];";
    string u = "[style = filled, fillcolor = Brown];";
    string o = "[style = filled, fillcolor = Chocolate];";
    string p = "[style = filled, fillcolor = DarkGoldenRod];";
    string q = "[style = filled, fillcolor = RosyBrown];";
    string r = "[style = filled, fillcolor = NavajoWhite];";
    string s = "[style = filled, fillcolor = Fuchsia];";
    string t = "[style = filled, fillcolor = OrangeRed];";
    string tt = "Error";

    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if (n == 6) return g;
    if (n == 7) return h;
    if (n == 8) return jj;
    if (n == 9) return jjj;
    if (n == 10) return kd;
    if (n == 11) return l;
    if (n == 12) return m;
    if (n == 13) return u;
    if (n == 14) return o;
    if (n == 15) return p;
    if (n == 16) return q;
    if (n == 17) return q;
    if (n == 18) return r;
    if (n == 19) return s;
    if (n == 20) return t;
    else return tt;

}

bool Graph::vertex_shaded_check(unordered_map<int, bool> pr) {   // проверка карты на покраску вершин 
    int count = 0;
    unordered_map<int, bool>::iterator it = pr.begin();
    for (it = pr.begin(); it != pr.end(); ++it) {
        if (pr[it->first] == true) count++;
    }
    if (count == vertex - 1) return true;
    else return false;
}

void Graph::greedy() {

    vector<pair<int, int>> storage;

    for (int i = 0; i < vertex - 1; i++) {
        int a = search_degree(i);
        storage.push_back(make_pair(a, i));   //     сначала степень потом вершина 3 [0]         
    }

    sort(storage.rbegin(), storage.rend());       // сортируем по убыванию степеней 

    vector<pair<int, int>>::iterator iter = storage.begin();

    for (iter = storage.begin(); iter != storage.end(); ++iter)
        check.insert(make_pair(iter->second, false));

    iter = storage.begin();
    vector<int> ::iterator it = shaded_vertices.begin();
    unordered_map<int, bool>::iterator at = check.begin();

    for (chromatic_number = 0; vertex_shaded_check(check) != 1; chromatic_number++) {
        paint.insert(make_pair(iter->second, generator_colour(chromatic_number)));
        int j = iter->second;
        check[j] = true;
        shaded_vertices.push_back(j);

        int size = 0;
        for (int i = 0; i < vertex - 1; i++) {
            if (graph[j][i] == 0 && j != i) {

                for (it = shaded_vertices.begin(); it != shaded_vertices.end(); ++it) {
                    if (graph[*it][i] == 0 && check[i] == 0)    // проверяет не связны ли покрашенные вершины с текущей, если не связаны count++
                        size++;
                }

                if (size == shaded_vertices.size()) {
                    paint.insert(make_pair(i, generator_colour(chromatic_number)));
                    check[i] = true;
                    shaded_vertices.push_back(i);
                    iter->second = i;
                }
                size = 0;
            }

        }

        shaded_vertices.clear();
        for (iter = storage.begin(); iter != storage.end(); ++iter) {
            if (check[iter->second] == false) {
                break;
            }
        }
    }
}

bool Graph::check_vertex_colour(int ver1, int ver2) {

    if (paint[ver1] == paint[ver2]) return 1;
    else return 0;

}


void Graph::overkill() {

    vector<string> different_colors;
    int begin = vertex - 2;

    for (int i = 0; i < vertex - 1; i++) {
        paint.insert(make_pair(i, generator_colour(i)));
    }
    
    for (begin = vertex - 2; begin >= 0; begin--) {

        paint.erase(begin);
        for (int n = 0; n < vertex - 1; n++) {

            paint.insert(make_pair(begin, generator_colour(n)));
            for (int i = 0; i < vertex - 1; i++) {

                if (graph[begin][i] == 1 && check_vertex_colour(begin, i) == 1) {
                    paint.erase(begin);
                    paint.insert(make_pair(begin, generator_colour(n + 1)));
                }
            }
        }
    }

    different_colors.push_back(generator_colour(begin));
    unordered_map<int, string>::iterator iterator = paint.begin();
   
    for (iterator = paint.begin(); iterator != paint.end(); ++iterator) {

        if (check_vertex_colour(iterator->first, begin + 1) == 0)
            different_colors.push_back(iterator->second);

    }

    sort(different_colors.begin(), different_colors.end());
    different_colors.resize(unique(different_colors.begin(), different_colors.end()) - different_colors.begin());

    vector<string>::iterator it1 = different_colors.begin();
    for (it1 = different_colors.begin(); it1 != different_colors.end(); ++it1) {
        chromatic_number++;
    }
}

void Graph::write_coloring(const char* fname) {
    ofstream out(fname);
    out << "Chromatic_number = " << chromatic_number << endl;
    unordered_map<int, string>::iterator it2 = paint.begin();
    for (it2 = paint.begin(); it2 != paint.end(); ++it2)
        out << it2->first << " " << it2->second << endl;

    out.close();
}


void Graph::write_dot(const char* fname) {
    ofstream out(fname);
    out << "graph {\n";

    unordered_map<int, string>::iterator it2 = paint.begin();
    for (it2 = paint.begin(); it2 != paint.end(); ++it2) {
        out << it2->first << it2->second << endl;
    }

    for (size_t k = 0; k < vertex - 1; k++) {
        for (size_t j = 0 + k; j < vertex - 1; ++j) {
            if (graph[k][j] == 1) {
                out << "  " << k << "--" << j << "; \n";
            }
        }
    }
    out << "}\n";
    out.close();
}