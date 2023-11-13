#ifndef __CANVAS_H_
#define __CANVAS_H_

typedef struct Color
{
    int r;
    int g;
    int b;
} Color;

typedef struct Canvas
{
    int width;
    int height;

    Color *pixels;
} Canvas;

/*  @brief Creates a canvas with the specified width and height.
 *
 *  This function returns NULL if an error occured during the canvas creation.
 *
 *  @param width Width of the canvas.
 *  @param height Height of the canvas.
 *  @return The canvas filled with white pixels (255, 255, 255).
 */
Canvas *create_canvas(int width, int height);

/*  @brief Puts a pixel on the canvas calculating origin from the top left corner of the canvas.
 *
 *  Pixel will not be placed if invalid X or Y is passed.
 *
 *  @param canvas Canvas to put pixel on,
 *  @param x X value (X increases toward the right).
 *  @param y Y value (Y increases toward the bottom).
 *  @return Void.
 */
void put_pixel_screen(Canvas *canvas, int x, int y, Color color);

/*  @brief Puts a pixel on the canvas calculating origin from the center of the canvas.
 *
 *  Pixel will not be placed if invalid X or Y is passed.
 *
 *  @param canvas Canvas to put pixel on,
 *  @param x X value (X increases toward the right).
 *  @param y Y value (Y increases toward the top).
 *  @return Void.
 */
void put_pixel_canvas(Canvas *canvas, int x, int y, Color color);

/*  @brief Exports canvas in ppm format with the specified file name.
 *
 *  This function returns -1 if an error occured during the canvas export.
 *
 *  @param canvas Canvas to export,
 *  @param file_name File name with an extension (ppm should be used in most cases),
 *  @return Export result.
 */
int export_canvas_to_ppm(Canvas *canvas, char *file_name);

#endif /* __CANVAS_H_ */