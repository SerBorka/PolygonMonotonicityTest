#include <iostream>
#include <utility>
#include <vector>
#include "List.h"
#include <algorithm>

bool handmade = true;

bool MonotonicityCheck(std::vector<double> &coords, std::pair<double,double> &direction) {
    List *polygon = new List;
    polygon->insert(coords);
    polygon->insertdirection(direction);
    return polygon->MCheck();
}

int main() {

    std::vector<double> coords;
    std::pair<double,double> direction;

    if (handmade) {
        double a;
        double b;
        std::cout << "Enter the direction of monotonicity: " << std::endl;
        std::cin >> a;
        direction.first = a;
        std::cin >> b;
        direction.second = b;
        std::cout<<a<<" "<<b<<'\n';

        coords.clear();
        int size;
        std::cout << "Enter the number of polygon vertexes: " << '\n';
        std::cin >> size;
        std::cout<<size<<'\n';
        for (int i = 0; i < size; ++i) {
            double _x;
            double _y;
            //std::cout << "Enter the x coordinate of vertex " << i << " :" << '\n';
            std::cin >> _x;
            coords.push_back(_x);
            //std::cout << "Enter the y coordinate of vertex " << i << " :" << std::endl;
            std::cin >> _y;
            coords.push_back(_y);
            std::cin.clear();
        }
    }

    return MonotonicityCheck(coords,direction);
}
