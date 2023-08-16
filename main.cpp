#include <iostream>
#include <fstream>

#include <sstream>
using namespace std;
 
int main() {

   ifstream image;
   ofstream newImage;
   image.open("monument.ppm");
   newImage.open("newImage.ppm");

   string type = "", width = "", height = "", RGB = "";
   image >> type;
   image >> width;
   image >> height;
   image >> RGB;

   // cout << type << width << height << RGB << endl;
   newImage << type << endl;
   newImage << width << " " << height << endl;
   newImage << RGB << endl;

   string red = "", green = "", blue = "";
   int r = 0, g = 0, b = 0;

   while (!image.eof())
   {
      image >> red;
      image >> green;
      image >> blue;

      stringstream redstream(red);
      stringstream greenstream(green);
      stringstream bluestream(blue);

      redstream >> r;
      greenstream >> g;
      bluestream >> b;

      if (b + 50 > 255) {
         b = 255;
      } else {
         b += 50;
      }

      newImage << r << " " << g << " " << b << endl;
   }

   image.close();
   newImage.close();

   return 0;
}