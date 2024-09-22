#include <stdio.h>
#include <limits.h>
#include "point.h"

double distance(Point a, Point b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int find_min_mass_point(Point* points, int n) {
    int min_index = -1;
    double min_mass = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (points[i].mass < min_mass) {
            min_mass = points[i].mass;
            min_index = i;
        }
    }
    return min_index;
}

void process_points(Point* points, int n) {
    while (n > 1) {
        int min_index = find_min_mass_point(points, n);

        // Знайти найближчу точку
        int closest_index = -1;
        double closest_distance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i != min_index) {
                double dist = distance(points[min_index], points[i]);
                if (dist < closest_distance) {
                    closest_distance = dist;
                    closest_index = i;
                }
            }
        }

        // Передача маси
        points[closest_index].mass += points[min_index].mass;

        // Видалення мінімальної точки
        for (int i = min_index; i < n - 1; i++) {
            points[i] = points[i + 1];
        }
        n--;
    }
}
