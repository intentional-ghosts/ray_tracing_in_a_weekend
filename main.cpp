#include "iostream"
#include "cstdio"

int main()
{

    int nx =200  , ny = 100;

    printf("p3\n%d %d\n255\n", nx, ny);

    for ( int j = ny - 1; j >= 0 ; j--) 
    {
        for ( int i = 0; i < nx; i++)
        {
            float r = float(i) / float(nx); 
            float g = float(j) / float(ny);
            float b = 0.2f;

            /*
                the order in which you use the nx and ny y values is how the color values will show up on the screen right now because
                i / nx which is accumulating with the for loop the value of the color will get more red the futher right you go but with green we have j / 100
                which just starts at 99 / 100 which is 0.99 so it starts at full green on the left and dims out as you go right  and this is because on the 
                way the pixels rows and colums are being munipulated in the for loops like if j start at 0 in stead of 99 then it would be accumulating more green values
                the further right you go down the colums for the rows also the outs loop controls the rows you dont nessecary need to make your color values use the out loop
                because the outer loop is the rows the colums is really where all your colors are going to be produced by. so really you could have three inner loops for the different 
                colors to make them do different things. 
            */

            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);

            printf("%d %d %d \n", ir, ig, ib );
        }
        
    }
    
    


}