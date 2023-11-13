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

void put_pixel_screen(Canvas *canvas, int x, int y, Color color)
{
    if (x < 0 || y < 0 || x > canvas->width - 1 || y > canvas->height - 1)
    {
        return;
    }

    int place = canvas->width * y + x;
    canvas->pixels[place] = color;
}

void put_pixel_canvas(Canvas *canvas, int x, int y, Color color)
{
    int screen_x = canvas->width / 2 + x;
    int screen_y = canvas->height / 2 - y;
    put_pixel_screen(canvas, screen_x, screen_y, color);
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