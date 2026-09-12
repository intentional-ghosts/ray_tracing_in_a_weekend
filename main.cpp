#include <iostream>
#include <cstdio>
#include "main.h"
#include "ray.h"
#include "camera.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>


using glm::vec3;
using glm::normalize;

vec3 color( const ray& r)
{
    vec3 unit_direction = normalize( r.direction() );
    
    float t = 0.5 * ( unit_direction.y + 1.0 );

    vec3 scaled_1 = ( 1.0f - t ) * vec3( 1.0f, 1.0f, 1.0f );  
    vec3 scaled_2 = t * vec3(0.5, 0.7 , 1.0);
    vec3 result = scaled_1 + scaled_2;
    return result;     

}

int main()
{

    ray_tracing_gradent_code();
    //personal_ray_tracing_gradent_code();
    //red_gradent();


}


void ray_tracing_gradent_code()
{

    int nx = 200  , ny = 100;
    
    printf("P3\n%d %d\n255\n", nx, ny);

    vec3 lower_left_cornor( -2.0f, -1.0f, -1.0f );

    vec3 horizontal( 4.0f, 0.0f, 0.0f);

    vec3 vertical ( 0.0f, 2.0f, 0.0f );

    camera scene_cam = camera();  

    vec3 origin = scene_cam.position; 

    
    for ( int j = ny - 1; j >= 0 ; j--) 
    {
        std::clog << "\rscanlines remaining: " << (ny - j) << ' ' << std::flush; 

        for ( int i = 0; i < nx; i++)
        {

            float u = float(i) / float (nx);
            float v = float(j) / float (ny);
            ray r ( scene_cam.position, lower_left_cornor + u * horizontal + v * vertical ); 
            glm::vec3 col = color(r);
           
            /*
                the order in which you use the nx and ny y values is how the color values will show up on the screen right now because
                i / nx which is accumulating with the for loop the value of the color will get more red the futher right you go but with green we have j / 100
                which just starts at 99 / 100 which is 0.99 so it starts at full green on the left and dims out as you go right  and this is because on the 
                way the pixels rows and colums are being munipulated in the for loops like if j start at 0 in stead of 99 then it would be accumulating more green values
                the further right you go down the colums for the rows also the outs loop controls the rows you dont nessecary need to make your color values use the out loop
                because the outer loop is the rows the colums is really where all your colors are going to be produced by. so really you could have three inner loops for the different 
                colors to make them do different things. 
            */

            int ir = int( 255.99 * col[ 0 ] );
            int ig = int( 255.99 * col[ 1 ] );
            int ib = int( 255.99 * col[ 2 ] );

            printf("%d %d %d \n", ir, ig, ib );
        }
        
    }

    std::clog << "\r done.                  \n";

}

void personal_ray_tracing_gradent_code()
{

    int nx = 1280  , ny = 1024;
    
    float upper_line_width = 3.0f;
    float end_of_colum_line_width = 4.0f;

    static float upper_range = upper_line_width;
    static float lower_range = 0.0f; 
    
    static float end_of_colum_upper_range = float(nx) - 1.0f;
    static float end_of_colum_lower_range = float(nx) - end_of_colum_line_width; 
    
    float slop = ( float(nx) / 2.0 ) / ( float(ny) / 2.0 );

    const int half_image_rows = ny / 2;

    printf("P3\n%d %d\n255\n", nx, ny);

    for ( int j = ny - 1; j >= 0 ; j--) 
    {

        for ( int i = 0; i < nx; i++)
        {
            

            if 
            ( 

                (
                ( i >= int(lower_range) && i <= int(upper_range) ) 

                ||  

                ( i >= int(end_of_colum_lower_range) && i <= int(end_of_colum_upper_range)  ) 
                )

                && 

                j >= half_image_rows 
                
            )
            {

                float r = 0.0f; 
                float g = 0.0f;
                float b = 0.0f;

                int ir = int(255.99 * r);
                int ig = int(255.99 * g);
                int ib = int(255.99 * b);

                printf("%d %d %d \n", ir, ig, ib );

            }
            else
            {

                float r = float(i) / float(nx); 
                float g = float(j) / float(ny);
                float b = 0.0f;

                int ir = int(255.99 * r);
                int ig = int(255.99 * g);
                int ib = int(255.99 * b);

                printf("%d %d %d \n", ir, ig, ib );

            }


           
        }
      
        
        upper_range += slop;
        lower_range += slop;
        end_of_colum_upper_range -= slop;
        end_of_colum_lower_range -= slop;


    }


}

void red_gradent()
{

    int nx = 1280  , ny = 1024;

    printf("P3\n%d %d\n255\n", nx, ny);

    for ( int j = ny - 1; j >= 0 ; j--) 
    {
        for ( int i = 0; i < nx; i++)
        {
            float r = 1.0f; 
            float g = 0.0f;
            float b = 0.0f;

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            printf("%d %d %d \n", ir, ig, ib );
        }
        
    }

}

void green_gradent()
{
    int nx = 1280  , ny = 1024;

    printf("P3\n%d %d\n255\n", nx, ny);

    for ( int j = ny - 1; j >= 0 ; j--) 
    {
        for ( int i = 0; i < nx; i++)
        {
            float r = 0.0f; 
            float g = 1.0f;
            float b = 0.0f;

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            printf("%d %d %d \n", ir, ig, ib );
        }
        
    }

}

void blue_gradent()
{

    int nx = 1280  , ny = 1024;

    printf("P3\n%d %d\n255\n", nx, ny);

    for ( int j = ny - 1; j >= 0 ; j--) 
    {
        for ( int i = 0; i < nx; i++)
        {
            float r = 0.0f; 
            float g = 0.0f;
            float b = 1.0f;

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            printf("%d %d %d \n", ir, ig, ib );
        }
        
    }
}