/*Реализовать переборный и жадный алгоритмы решения задачи о раскраске графа.
Программа должна  определять хроматическое число и записывать раскраску файл.
Вход --- матрица смежности, выход --- граф в формате graphviz.
        Литература:
        a. Ахо, Ульман, Хопкрофт, “Структуры данных и алгоритмы” */
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <ctime>

using namespace std;
/*!
    \brief class Graph

    Создан для решения задачи о раскраске графа
*/
class Graph {
public:
    /**
    Создан для решения задачи о раскраске графа
     */
    bool** graph; ///< матрица смежности
    unordered_map<int, string> paint;   ///< переменная для покраски вершин 
    unordered_map<int, bool> check; ///<  переменная для проверки покрашены вершины или нет
    int vertex; ///< количество вершин
    int chromatic_number = 0; ///< хроматическое число
    vector<int> shaded_vertices; ///< вектор покрашенных в один цвет вершин

public:
    /**
     функция для считывания графа, представленного в виде матрицы смежности, из входного файла
     \param fname Входной файл
    */
    void read_graph(const string& fname); 
    int search_degree(int ver); ///< функция, для поиска степени вершины графа \param ver Вершина, для которой будет происходить поиск степени \return Степень данной вершины графа
    string generator_colour(int n); ///< функция, для покраски графа \param n Переменная, определяющая цвет \return Цвет
    bool vertex_shaded_check(unordered_map<int, bool> pr); ///< функция, проверяющая покрашены ли вершины графа,  \param pr Переменная для проверки покрашена вершина или нет \return если покрашены все - true, иначе - false
    void greedy(); ///< жадный алгоритм раскраски графа 
    void overkill(); ///< переборный алгоритм раскраски графа 
    void write_dot(const char* fname); ///< функция, которая выводит граф в формате graphviz \param fname Выходной файл в формате .dot
    void write_coloring(const char* fname); ///< функция, записывающаю раскраску графа в выходной файл \param fname Выходной файл
    bool check_vertex_colour(int ver1, int ver2); ///< функция, проверящая поркашены ли вершины в одинаковый цвет \param ver1, ver2 Сравниваемые вершины \return если покрашены в один цвет - 1, иначе - 0
};
