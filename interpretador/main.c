#include "lib.h"

main()
{      
      
      printf("Cubo com triâgulos: \n");
      printf("Faces: \n");
      FaceSet face_set = readX3D_faces("cubo_tri.x3d", 12, 3);
      printf("Points: \n");     
      Point* points = readX3D_points("cubo_tri.x3d", 8);       
      printf("_______________________________________________\n");   
      printf("Cubo com quadrados: \n");
      printf("Faces: \n");
      face_set = readX3D_faces("cubo.x3d", 6, 4);
      printf("Points: \n");     
      points = readX3D_points("cubo.x3d", 8);       
      system("pause");
}  
