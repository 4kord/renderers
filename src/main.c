#include <stdio.h>
#include <stdlib.h>

#include "canvas.h"

int main()
{
    Canvas *canvas = create_canvas(250, 1000);
    if (canvas == NULL)
    {
        printf("error creating canvas");
        return EXIT_FAILURE;
    }

    for (int y = 0; y < 250; y++)
    {
        for (int x = 0; x < 1000; x++)
        {
            Color color = {x % 255, x % 255, x % 255};
            put_pixel(canvas, x, y, color);
        }
    }

    if (export_canvas_to_ppm(canvas, "canvas.ppm") == -1)
    {
        printf("error exporting canvas to ppm");
        return EXIT_FAILURE;
    };

    return EXIT_SUCCESS;
}