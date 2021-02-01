// http://www.libpng.org/pub/png/libpng-1.2.5-manual.html
#include <png.h>
#include <stdio.h>

#define ERROR 1

static void writepng_error_handler(png_structp png_ptr, png_const_charp msg) {
  //    mainprog_info  *mainprog_ptr;

  fprintf(stderr, "writepng libpng error: %s\n", msg);
  fflush(stderr);

#if 0
    mainprog_ptr = png_get_error_ptr(png_ptr);
    if (mainprog_ptr == NULL) {         /* we are completely hosed now */
        fprintf(stderr,
          "writepng severe error:  jmpbuf not recoverable; terminating.\n");
        fflush(stderr);
        exit(99);
    }

    longjmp(mainprog_ptr->jmpbuf, 1);
#endif
}

struct userdata {};

int main() {
  userdata u;
  const char *file_name = "test.png";

  FILE *fp = fopen(file_name, "wb");
  if (!fp) {
    return (ERROR);
  }

  png_structp png_ptr = png_create_write_struct(
      PNG_LIBPNG_VER_STRING, &u, writepng_error_handler, nullptr);
  if (!png_ptr)
    return (ERROR);

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    png_destroy_write_struct(&png_ptr, nullptr);
    return (ERROR);
  }

  if (setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    return (ERROR);
  }

  png_init_io(png_ptr, fp);

  int sample_depth = 8;
  int width = 100;
  int height = 100;
  png_set_IHDR(png_ptr, info_ptr, width, height, sample_depth,
               PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
               PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

  printf("pngtry: didn't longump\n");

  return 0;
}
