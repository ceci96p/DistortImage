#include "block.h"

int Block::width() const{
return data[0].size();
}

int Block::height() const{
return data.size();
}


void Block::render(PNG & im, int upLeftX, int upLeftY) const { 
for (int y = 0;y < height(); y++){
	for(int x = 0;x < width(); x++) { //x
      	*(im.getPixel(x + upLeftX,y + upLeftY)) = data[y][x];
      }
  }
   return;
}


void Block::build(PNG & im, int upLeftX, int upLeftY, int cols, int rows) { //grab pixels from image
std::vector<HSLAPixel> v;
for (int y = 0; y < rows; y++){
	for (int x = 0; x < cols; x++) { 
      	   HSLAPixel* p = im.getPixel(x + upLeftX ,y + upLeftY);
      	   v.push_back(*p); //place  x pixels into vector v
      }
      data.push_back(v);
      v.clear();
   }

   return;
}
