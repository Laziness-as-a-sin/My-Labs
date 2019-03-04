#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>
#include <math.h>

using namespace std;

struct Point{
    double x;
    double y;
    double angle = 0;
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

void quickSort(Point arr[], int left, int right) {

      int i = left, j = right;
      Point tmp;
      Point pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i].angle < pivot.angle)
                  i++;
            while (arr[j].angle > pivot.angle)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);

      if (i < right)
            quickSort(arr, i, right);

}

int main() {

    ifstream input("E:/Baranov/A/input.txt");
    ofstream output("E:/Baranov/A/output.txt");

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
    for(int i = 0; i < N; i++)// находим полярный угол
        Arr[i].angle = angle(startP.x+10, startP.y, Arr[i].x, Arr[i].y, startP.x, startP.y);

    Arr[minI].angle = 3.15;


    for(int i = 0; i < N; i++){
        cout << i << ' ';
        cout << Arr[i].x << ' ';
        cout << Arr[i].y << ' ';
        cout << Arr[i].angle << endl;
    }
    quickSort(Arr, 0, N-1);
    output << fixed;
    output.precision(5);

    cout << angle(1, 1, 2, 2, 0, 0) << endl;
    for(int i = 0; i < N; i++){
        cout << i << ' ';
        cout << Arr[i].x << ' ';
        cout << Arr[i].y << ' ';
        cout << Arr[i].angle << endl;
    }



    input.close();
    output.close();
    return 0;
}
