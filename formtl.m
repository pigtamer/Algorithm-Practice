clc,close all, clear all
img = imread('X:/cvImg/dim.fruit.tif');
[rows, cols, channels] = size(img);

if (channels > 1)
    img = rgb2gray(img);
    channels = 1;
end;
imgsrc = img;
figure(1),
imshow(img),title('Original image');

imgCDF = 0:255;

for i=1:256
	imgCDF(i) = sum(sum( (img == i-1 ))); % Original Hist
end;

figure(2),subplot(3,1,1)
stem(0:255, imgCDF/(rows*cols)),grid minor,title('Original Histogram PDF')

for i=2:256
	imgCDF(i) = (imgCDF(i)+ imgCDF(i-1)); %CDF
end;

for i=1:256
	imgCDF(i) = 255*(imgCDF(i)-1)/(rows*cols); %CDF
end;

imgDst = zeros(rows, cols,channels);
for i = 1:256
    imgDst = imgDst+ (img==(i-1)) *imgCDF(i);
end;

imgBalancedCDF = 0:255;

for i=1:256
	imgBalancedCDF(i) = sum(sum( (uint8(imgDst) == i-1 ))); % Original Hist
end;

figure(2),subplot(3,1,2)
stem(0:255, imgCDF),grid minor,title('Balancing Transformation(Original CDF)')
subplot(313)
stem(0:255, imgBalancedCDF/(rows*cols)),grid minor,title('Balanced Histogram PDF')

figure(3),
imshow(uint8(imgDst)),title('Balanced image')

sysEQ = histeq(img);
figure(4)
imshow(uint8(sysEQ)), title('System')
sysEQh = imhist(sysEQ);
BIAS = sum(sysEQh- imhist(imgDst))
figure(5)
subplot(211)
imhist(sysEQ)
subplot(212)
imhist(uint8(imgDst))
imwrite(uint8(imgDst),'Balanced.jpg');
