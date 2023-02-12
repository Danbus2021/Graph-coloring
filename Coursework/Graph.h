/*����������� ���������� � ������ ��������� ������� ������ � ��������� �����.
��������� ������  ���������� ������������� ����� � ���������� ��������� ����.
���� --- ������� ���������, ����� --- ���� � ������� graphviz.
        ����������:
        a. ���, ������, ��������, ���������� ������ � ���������� */
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

    ������ ��� ������� ������ � ��������� �����
*/
class Graph {
public:
    /**
    ������ ��� ������� ������ � ��������� �����
     */
    bool** graph; ///< ������� ���������
    unordered_map<int, string> paint;   ///< ���������� ��� �������� ������ 
    unordered_map<int, bool> check; ///<  ���������� ��� �������� ��������� ������� ��� ���
    int vertex; ///< ���������� ������
    int chromatic_number = 0; ///< ������������� �����
    vector<int> shaded_vertices; ///< ������ ����������� � ���� ���� ������

public:
    /**
     ������� ��� ���������� �����, ��������������� � ���� ������� ���������, �� �������� �����
     \param fname ������� ����
    */
    void read_graph(const string& fname); 
    int search_degree(int ver); ///< �������, ��� ������ ������� ������� ����� \param ver �������, ��� ������� ����� ����������� ����� ������� \return ������� ������ ������� �����
    string generator_colour(int n); ///< �������, ��� �������� ����� \param n ����������, ������������ ���� \return ����
    bool vertex_shaded_check(unordered_map<int, bool> pr); ///< �������, ����������� ��������� �� ������� �����,  \param pr ���������� ��� �������� ��������� ������� ��� ��� \return ���� ��������� ��� - true, ����� - false
    void greedy(); ///< ������ �������� ��������� ����� 
    void overkill(); ///< ���������� �������� ��������� ����� 
    void write_dot(const char* fname); ///< �������, ������� ������� ���� � ������� graphviz \param fname �������� ���� � ������� .dot
    void write_coloring(const char* fname); ///< �������, ������������ ��������� ����� � �������� ���� \param fname �������� ����
    bool check_vertex_colour(int ver1, int ver2); ///< �������, ���������� ��������� �� ������� � ���������� ���� \param ver1, ver2 ������������ ������� \return ���� ��������� � ���� ���� - 1, ����� - 0
};
