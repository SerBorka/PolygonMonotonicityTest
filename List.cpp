//
// Created by simbo on 09.10.2022.
//

#include "List.h"
#include <limits>

double nill = std::numeric_limits<double>::epsilon();

template <typename T> int sgn(T val) {
    return (nill < val) - (val < -nill);
}


void List::insert(double a, double b) {
    Node *tmp = new Node; //создание новой вершины
    tmp->x = a; tmp->y = b;
    if ( is_empty() ) {
        tmp->next = tmp;
        tmp->prev = tmp;
        tmp->indN = 0;
        root = tmp;

    }
    else {
        Node *cur = root->prev;
        tmp->next = root; // замыкаем новую вершину на первую
        cur->next = tmp;
        tmp->prev = cur;
        root->prev = tmp;
        tmp->indN = cur->indN + 1;
    }
    size++;
}

void List::insert(std::vector<double> coords) {
    for ( int i = 0; i < coords.size(); i += 2 ) {
        insert (coords[i], coords[i + 1]);
    }
    createnodeinds();
}

void List::createnodeinds() {
    Node* tmp = root;
    nodeinds.clear();
    do {
        nodeinds.push_back(tmp);
        tmp = tmp->next;
    } while (tmp!=root);
}

void List::insertdirection(std::pair<double, double> dir) {
    direction = dir;
}

double List::cross_prod(Node *first, Node *second, Node *third) {
    double x1 = second->x - first->x, x2 = third->x - first->x,
            y1 = second->y - first->y, y2 = third->y - first->y;
    return (x1 * y2 - x2 * y1);
}

double List::scalarbydir(Node *first, Node *second) const {
    double x = second->x - first->x;
    double y = second->y - first->y;
    return x*direction.first+y*direction.second;
}

bool List::MCheck() {
    Node* cur = root;
    do {
        dirstat = sgn(scalarbydir(cur,cur->next));
        cur = cur->next;
    } while (dirstat==0);
    do {
        if (dirstat*sgn(scalarbydir(cur,cur->next)) < 0) {
            int end = sgn(cross_prod(cur,cur->prev,cur->next));
            if (endstat!=0) {
                if (endstat*end<0) {
                    std::cout<<"Polygone is not monotonic"<<std::endl;
                    return false;
                }
            } else {
                endstat = end;
            }
            dirstat = -dirstat;
        }
        cur = cur->next;
    } while (cur!=root);
    std::cout<<"Polygone is monotonic"<<std::endl;
    return true;
}
