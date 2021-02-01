// https://stackoverflow.com/a/36433202/189270
#include <Magick++.h>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace Magick;

struct RGB
{
    uint8_t c[3];
};

// https://stackoverflow.com/a/20792531/189270
inline RGB mixer( double minimum, double maximum, double value ) {
  auto ratio = 2 * (value - minimum) / (maximum - minimum);
  uint8_t b = (uint8_t) std::max(0.0, 255 * (1 - ratio));
  uint8_t r = (uint8_t) std::max(0.0, 255 * (ratio - 1));
  uint8_t g = 255 - b - r;

  RGB rc{r, g, b};

  return rc;
}

int main(int argc, char **argv) {
  int width = 40;
  int height = 60;
  RGB pix[width * height];

  for (int j = 0; j < height; j++) {
    double c = cos( 2 * M_PI * j/height );

    for (int i = 0; i < width; i++) {
        double s = sin( 2 * M_PI * i/ width );

        pix[j * width + i] = mixer( -1.0, 1.0, s * c );
    }
  }

  // Initialise ImageMagick library
  InitializeMagick( ""); // https://legacy.imagemagick.org/discourse-server/viewtopic.php?t=9581

  // Create Image object and read in from pixel data above
  Image image;
  image.read(width, height, "RGB", CharPixel, (unsigned char *)pix);

  // Write the image to a file - change extension if you want a GIF or JPEG
  image.write("result.png");

  return 0;
}
