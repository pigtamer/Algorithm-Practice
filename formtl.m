a = 1:10;
b = randn(10,10);
c = im2double(rgb2gray(imread('X:/cvImg/berry.jpg')));
d = histeq(c);
mesh(c)
