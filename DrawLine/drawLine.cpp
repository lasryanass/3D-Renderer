#include <cmath>
#include <iostream>
#include "../Image/image.hpp" // path to image.hpp
#include "../Image/image.cpp" // path to image.cpp

using namespace std;

const Color white = Color(255, 255, 255, 255);
const Color red   = Color(255, 0,   0,   255);

/// if for is better than for if
/// it is better to factorize code in a function when it will be called once
/// else put the whole loop inside a function
/// Bresenham's line algorithmt
void line(int x0, int y0, int x1, int y1, Image &image, Color color){
    /// Version 1:

    // bool reverse = false; 
    // //slope is greater than 1
    // if (abs(x1-x0)<abs(y1-y0)) { 
    //     swap(x0, y0); 
    //     swap(x1, y1); 
    //     reverse = true; 
    // } 
    // //swap points if going right -> left
    // if (x0>x1) { 
    //     swap(x0, x1); 
    //     swap(y0, y1); 
    // } 
    // int dx = x1-x0; 
    // int dy = y1-y0; 
    // float slope = abs(dy/float(dx)); 
    // //distance to the best straight line from our current (x, y)
    // float error = 0; 
    // int y = y0; 
    // for (int x=x0; x<=x1; x++) { 
    //     if (reverse) { 
    //         image.set(y, x, color); 
    //     } else { 
    //         image.set(x, y, color); 
    //     } 
    //     error += slope; 
    //     if (error>.5) { 
    //         y += (y1>y0?1:-1); 
    //         error -= 1.; 
    //     } 
    // } 

    ///Version 2: (More optimized)

    if (x0>x1){
        swap(x0, x1);
        swap(y0, y1);
    }
    int dx=x1-x0;
    int dy=y1-y0;
    if (dx ==0){
        for (int y=y0; y<=y1; y++){
            image.set(x0, y, color);
        }
    } else if (dy == 0){
        for (int x=x0; x<=x1; x++){
            image.set(x, y0, color);
        }
    } else {
        float slope=dy/float(dx);
        if (abs(slope)>1){
            slope = 1/slope;
            if (y0>y1){
                swap(x0, x1);
                swap(y0, y1);
                }
            for (int y=y0; y<=y1; y++){
                // fast round
                int x = (int)(x0 + (y-y0)*slope + 0.5f);
                image.set(x, y, color);
            }
        } else {
            for (int x=x0; x<=x1; x++){
                // fast round
                int y = (int)(y0 + (x-x0)*slope + 0.5f);
                image.set(x, y, color);
            }
        }
    }
}
int main(int argc, char** argv) {
    Image image(100, 100, Image::RGB);
    for (int i=0; i<1000000; i++) {
        line(13, 20, 80, 40, image, white);
        line(20, 13, 40, 80, image, red);
        line(80, 40, 13, 20, image, red);
    }
    image.write_ima_file("output.ima");
    return 0;
}

