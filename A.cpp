#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
    double x;
    double y;
    double angle = 0;
    double dist = 0;
};

double angle(double x1, double y1, double x2, double y2, double x0, double y0){// угол между векторами p0p1 и p0p2
    double v1x = x1 - x0;
    double v1y = y1 - y0;
    double v2x = x2 - x0;
    double v2y = y2 - y0;

    double v1v2 = v1x*v2x + v1y*v2y;
    double cosl = v1v2/(sqrt(v1x*v1x+v1y*v1y)*sqrt(v2x*v2x+v2y*v2y));

    if(v1v2 != 0)
        return acos(cosl);
    else
        return 3.14/2;
}

bool f(const Point &a, const Point &b){
    if(a.angle < b.angle) return true;
    if(a.angle == b.angle)
        if(a.dist < b.dist) return true;
    return false;
}

bool check(Point p0, Point p1, Point p2){// поворот чекаем
    double ax = p1.x - p0.x;
    double bx = p2.x - p0.x;
    double ay = p1.y - p0.y;
    double by = p2.y - p0.y;
    if(ax*by - ay*bx >= 0) return true;// вектор направлен влево
    return false;
};

int main() {

    ifstream input("D:/Baranov/A/input.txt");
    ofstream output("D:/Baranov/A/output.txt");


    int N, minI = -1;
    Point startP;
    startP.x = -11;
    startP.y = 11;

    input >> N;
    Point Arr[N];
    for(int i = 0; i < N; i++){// считывание, поиск нижней правой точки
        input >> Arr[i].x;
        input >> Arr[i].y;
        if(Arr[i].y < startP.y){
            startP = Arr[i];
            minI = i;
        }
        else
            if(Arr[i].y == startP.y)
                if(Arr[i].x > startP.x){
                    startP = Arr[i];
                    minI = i;
                }
    }
    for(int i = 0; i < N; i++){// находим полярный угол
        Arr[i].angle = angle(startP.x+10, startP.y, Arr[i].x, Arr[i].y, startP.x, startP.y);
        Arr[i].dist = sqrt((Arr[i].x-startP.x)*(Arr[i].x-startP.x)+(Arr[i].y-startP.y)*(Arr[i].y-startP.y));
    }

    Arr[minI].angle = 3.15;

    sort(Arr, Arr + N, f);


    output << fixed;
    output.precision(5);

    input.close();
    output.close();
    return 0;
}
