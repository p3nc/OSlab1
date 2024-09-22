#ifndef POINT_H
#define POINT_H

typedef struct {
    int id;         // Ідентифікатор точки
    double mass;    // Маса точки
    double x;       // Координата x
    double y;       // Координата y
} Point;

void process_points(Point* points, int n);
double distance(Point a, Point b);
int find_min_mass_point(Point* points, int n);

#endif // POINT_H
