% 将同文件夹下所有jpg格式的图像转为灰度图像后，
% 图像数据矩阵合为一行，在行末再加上标签信息0（女），1（男）
% 图像可以调整大小，以减少像素的数据量
% 最后的数据文件保存在data.txt


clc
clear

% 图像像素的保存比例
resize_percent = 0.25;

fid=fopen('data.txt','at');

imagefiles = dir('*.jpg');
nfiles = length(imagefiles);
for ii=1:nfiles
   currentfilename = imagefiles(ii).name;
   currentimage = imread(currentfilename);
   graypic = rgb2gray(currentimage);
   graypic = imresize(graypic, resize_percent);
   % 标签信息从文件名中读得，最后一个字符为0或1
   [pathstr,name,ext] = fileparts(currentfilename);
   gen = str2num(name(end));

   % 像素矩阵合为一行
   v = reshape( graypic.', 1, numel(graypic) );
   result = [v gen];
   
   fprintf(fid,'%d ', result);
   fprintf(fid, '\n');
end

fclose(fid);
