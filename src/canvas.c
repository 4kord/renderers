#include "canvas.h"

#include <stdio.h>
#include <stdlib.h>

Canvas *create_canvas(int width, int height)
{
    Canvas *canvas = malloc(sizeof(Canvas));
    if (canvas == NULL)
    {
        return NULL;
    }

    Color *pixels = malloc(sizeof(Color) * width * height);
    if (pixels == NULL)
    {
        return NULL;
    }

    canvas->width = width;
    canvas->height = height;
    canvas->pixels = pixels;

    Color default_color = {
        .r = 255,
        .g = 255,
        .b = 255,
    };

    for (int i = 0; i < canvas->width * canvas->height; i++)
    {
        canvas->pixels[i] = default_color;
    }

    return canvas;
}

void put_pixel(Canvas *canvas, int x, int y, Color color)
{
    int place = canvas->width * x + y;
    canvas->pixels[place] = color;
}

int export_canvas_to_ppm(Canvas *canvas, char *file_name)
{
    FILE *file = fopen(file_name, "w");
    if (file == NULL)
    {
        return -1;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", canvas->width, canvas->height);
    fprintf(file, "255\n");

    for (int i = 0; i < canvas->width * canvas->height; i++)
    {
        fprintf(file, "%d %d %d\n", canvas->pixels[i].r, canvas->pixels[i].g, canvas->pixels[i].b);
    }

    return 0;
}