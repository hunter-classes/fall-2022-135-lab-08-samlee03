#include <iostream>
#include "imageio.h"
#include "funcs.h"
#include <cmath>
void invert(std::string input)
{
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);

  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      out[i][j] = std::abs(img[i][j] - 255);
    }
  }

  writeImage("taskA.pgm", out, h, w);
}

void invert_half(std::string input)
{
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (j >= (w / 2)){
	out[i][j] = std::abs(img[i][j] - 255);
      } else {
	out[i][j] = img[i][j];

      }
    }
  }
  writeImage("taskB.pgm", out, h, w);
}
void white_box(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
	if ((i > h/4 && i < h*3/4) && (j > w/4 && j < w*3/4)){
	  out[i][j] = 255;
	} else {
	  out[i][j] = img[i][j];
	}
      }
  }
  writeImage("taskC.pgm", out, h, w);
}

void white_frame(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (((i == h/4 || i == h/4*3) && (j >= w/4 && j<= w*3/4)) || ((j == w/4 || j == w/4*3) && (i > h/4 && i < h/4*3))){
	out[i][j] = 255;
      } else {
	out[i][j] = img[i][j];
      }
    }
  }
  writeImage("taskD.pgm", out, h, w);
}

void scale(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i += 2){
    for (int j = 0; j < w; j += 2){
      int orig_value = img[i/2][j/2];
      out[i][j] = orig_value;
      out[i+1][j] = orig_value;
      out[i][j+1] = orig_value;
      out[i+1][j+1] = orig_value;
    }
  }
  writeImage("taskE.pgm", out, h, w);
}
void pixel(std::string input){
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w);
  int out[MAX_H][MAX_W];
  for (int i = 0; i < h; i += 2){
    for (int j = 0; j < w; j += 2){
      int average = (img[i][j] + img[i+1][j] + img[i][j+1] + img[i+1][j+1])/ 4;
      out[i][j] = average;
      out[i+1][j] = average;
      out[i][j+1] = average;
      out[i+1][j+1] = average;
    }
  }
  writeImage("taskF.pgm", out, h, w);
}

