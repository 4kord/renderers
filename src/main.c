#include <stdio.h>
#include <stdlib.h>

#include "canvas.h"

int main()
{
    Canvas *canvas = create_canvas(100, 100);
    if (canvas == NULL)
    {
        printf("error creating canvas");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 10; i++)
    {
        Color color = {i, i, i};
        put_pixel_canvas(canvas, i, 0, color);
        put_pixel_canvas(canvas, 0, i, color);
    }

    if (export_canvas_to_ppm(canvas, "canvas.ppm") == -1)
    {
        printf("error exporting canvas to ppm");
        return EXIT_FAILURE;
    };

    return EXIT_SUCCESS;
}