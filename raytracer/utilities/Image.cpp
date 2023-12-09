#include "Image.hpp"

// initialize blank image of given size.
Image::Image(int hres, int vres) {
    this->hres = hres;
    this->vres = vres;
    colors = new RGBColor*[vres];
    for (int i=0; i< vres; i++)
        colors[i] = new RGBColor[hres];
}
// initialize blank image with size of vp.
Image::Image(const ViewPlane& vp) {
    hres = vp.hres;
    vres = vp.vres;
    colors = new RGBColor*[vres];
    for (int i=0; i< vres; i++)
        colors[i] = new RGBColor[hres];
}
// Destructor
Image::~Image() {
    for (int i = 0; i < vres; i++)
        delete[] colors[i];
    delete[] colors;
}
// Set pixel color. Convert to integer values.
void Image::set_pixel(int x, int y, const RGBColor& color) {
   
    this->colors[y][x] = color;
}

// Write image to file in PPM format.
void Image::write_ppm(std::string path) const {
  

    float mmax = 0;
    for (int r = 0; r < vres; ++r) {
        for (int c = 0; c < hres; ++c) {
            mmax = std::max(colors[r][c].r,std::max(colors[r][c].g, std::max(colors[r][c].b, mmax)));
        }
    }
    double scale = 255/mmax;
    //double scale = 255;
    std::ofstream file(path);
    file << "P3" << '\n';
    file << hres << " " << vres << '\n';
    file << 255 << '\n';
    
    for (int i = 0; i < vres; i++) {
        for (int j = 0; j < hres; j++) {
            file << static_cast<int>(colors[i][j].r*scale) << " " <<
            static_cast<int>(colors[i][j].g*scale) << " " <<
            static_cast<int>(colors[i][j].b*scale) << " ";
        }
        file << '\n';
    }
    file.close();
}
