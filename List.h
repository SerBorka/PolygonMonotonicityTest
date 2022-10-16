#ifndef MONPOLYGONPROOF_LIST_H
#define MONPOLYGONPROOF_LIST_H


#include <vector>
#include <iostream>

class Node {  //узел списка(в данной задаче-вершина многоугольника)
public:
    double x, y;//координаты текущей точки
    int indN;  // индекс точки в многоугольнике
    Node *prev, *next; //указатели на предыдущую и следующую вершины
    //конструктор по умолчанию
    explicit Node (double a = 0.0, double b = 0.0, int ind_=0): x(a), y(b),indN(ind_), prev(nullptr), next(nullptr) {}
};

class List {
public:
    int size = 0; //количество вершин
    Node* root = nullptr;// первая вершина с нулевым индексом
    std::pair<double,double> direction;
    std::vector <Node*> nodeinds = {};
    double dirstat = 0;
    double endstat = 0;

    ~List() {
        if (nodeinds.size()!=size) {
            createnodeinds();
        }
        for (auto nd:nodeinds) {
            delete nd;
        }
        //pastd::cout<<"Deleted List "<<size<<'\n';
    }

    bool is_empty () const {
        return size == 0;
    }

    void insert (double a, double b);//вставка одной вершины после текущей
    void insert (std::vector<double> coords);// вставка вектора координат
    void createnodeinds();
    void insertdirection (std::pair<double,double> direction);

    static double cross_prod (Node *first, Node *second, Node *third);//векторное произведение 12 крест 13
    double scalarbydir (Node *first, Node *second) const;

    bool MCheck();
};


#endif //MONPOLYGONPROOF_LIST_H
