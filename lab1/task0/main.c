#include <stdio.h>
#include "point.h"

int main() {
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point points[n];

    for (int i = 0; i < n; i++) {
        printf("Enter mass and coordinates (x, y) of point %d: ", i + 1);
        scanf("%lf %lf %lf", &points[i].mass, &points[i].x, &points[i].y);
        points[i].id = i + 1; // Point identifier
    }

    process_points(points, n);

    printf("Final point: ID=%d, mass=%.2f, coordinates=(%.2f, %.2f)\n",
           points[0].id, points[0].mass, points[0].x, points[0].y);

    return 0;
}
