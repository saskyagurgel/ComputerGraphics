#include "lib.h"

FaceSet readX3D_faces(char *filename, int n_faces, int n_points)
{
    FILE    *f;
    FaceSet face_set;

    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "File not found: %s\n", filename);
        free(face_set.faces);
    }
    
    
    int caractere, pos = 0, encontrei = FALSE;
    char pesquisa[] = "coordIndex=\"";
    
    while((caractere = fgetc(f)) != EOF){
        if((caractere == pesquisa[0]) && (!encontrei)){
           encontrei = TRUE;
           pos = 0;
        }
       
        if(encontrei){
           if(caractere == pesquisa[pos]){
              encontrei = TRUE; 
              pos++;
             
           if(pos == strlen(pesquisa))
              break;            
           }
           else{
                encontrei = FALSE;     
           }              
        }
    }
    
    if(encontrei){
        //alocando memória
        int i, j, k, point;
           
        face_set.n_faces = n_faces;
        face_set.n_points = n_points;
        face_set.faces = (int**) malloc(sizeof(int*) * face_set.n_faces);
            
        for (i = 0; i < face_set.n_faces; ++i) {
            face_set.faces[i] = (int*) malloc(sizeof(int) * face_set.n_points);
        }
        
        if (face_set.faces == NULL) 
            printf("Could not allocate memory\n");
            
        //inserindo valores    
        i = 0;
        for( i = 0 ; i < n_faces ; i++)
        {
            for( j = 0 ; j < n_points ; j++)
            {
                fscanf(f, "%d", &face_set.faces[i][j]);

            }
            for(k = 0; k < 4 ; k++)
                  fgetc(f);
                  
        }
        
        //imprimindo
        for( i = 0 ; i < n_faces ; i++)
        {           
            for( j = 0 ; j < n_points ; j++)
            {
                printf("%d ", face_set.faces[i][j]);
            }
            printf("\n");    
        }    
        
    }
    
    fclose(f);
    return face_set;
    
}    

Point* readX3D_points(char *filename, int n_points)
{
    FILE    *f;
    Point *point_set;
    

    f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "File not found: %s\n", filename);
        return NULL;
    }  
    
    int caractere, pos = 0, encontrei = FALSE;
    char pesquisa[] = "point=\"";
    
    while((caractere = fgetc(f)) != EOF){
        if((caractere == pesquisa[0]) && (!encontrei)){
           encontrei = TRUE;
           pos = 0;
        }
       
        if(encontrei){
           if(caractere == pesquisa[pos]){
              encontrei = TRUE; 
              pos++;
             
           if(pos == strlen(pesquisa))
              break;            
           }
           else{
                encontrei = FALSE;     
           }              
        }
    }
    
    if(encontrei){
        //alocando memória
        int i;
           
        point_set = (Point*) malloc(sizeof(Point) * n_points);
        
        if (point_set == NULL) 
            printf("Could not allocate memory\n");
            
        //inserindo valores    
        i = 0;
        for( i = 0 ; i < n_points ; i++)
        {
            fscanf(f, "%lf %lf %lf", &point_set[i].x, &point_set[i].y, &point_set[i].z);
        }
        
        //imprimindo
        for( i = 0 ; i < n_points ; i++)
        {
            printf("x=%lf y=%lf z=%lf", point_set[i].x, point_set[i].y, point_set[i].z);
            printf("\n");    
        }    
        
        
    }
    
    fclose(f);
    
    return point_set;
}     
    

