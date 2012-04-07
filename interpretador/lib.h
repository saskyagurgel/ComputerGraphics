#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

typedef struct tagFaces
{
    int n_faces;                   // number of faces of form
    int n_points;                  // number of points of face
    int **faces;                   // faces
} FaceSet;

typedef struct tagPoints
{
    double x,y,z;                   // points
} Point;

FaceSet readX3D_faces(char *filename, int n_faces, int n_points);
Point* readX3D_points(char *filename, int n_points);
