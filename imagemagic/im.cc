// https://stackoverflow.com/a/36433202/189270
#include <Magick++.h>
#include <iostream> 

using namespace std; 
using namespace Magick; 

int main(int argc,char **argv) 
{ 
   unsigned char pix[]={
        200,200,200,    100,100,100,
        0,0,0,          255,0,0,
        0,255,0,        0,0,255};

   // Initialise ImageMagick library
   //InitializeMagick(*argv);
   InitializeMagick(""); // https://legacy.imagemagick.org/discourse-server/viewtopic.php?t=9581

   // Create Image object and read in from pixel data above
   Image image; 
   image.read(2,3,"RGB",CharPixel,pix);

   // Write the image to a file - change extension if you want a GIF or JPEG
   image.write("result.png"); 

   return 0;
}
