% 使用已经训练好的网络来识别图像性别
% 根据识别结果在文件名最后添加0或1


clc
clear
load net;
resize_percent = 0.25;


imagefiles = dir('*.jpg');
tmpname = imagefiles(1).name;
tmpimage = imread(tmpname);
tmpgraypic = rgb2gray(tmpimage);
[picw pich] = size(tmpgraypic);

picsize = (picw*resize_percent)*(pich*resize_percent);
x = zeros(1, picsize);

nfiles = length(imagefiles);
for ii=1:nfiles
   currentfilename = imagefiles(ii).name;
   currentimage = imread(currentfilename);
   graypic = rgb2gray(currentimage);
   graypic = imresize(graypic, resize_percent);
   v = reshape( graypic.', 1, numel(graypic) );
   %v = reshape(graypic, [1 picsize]);
   x = [x ; v];
end

%x = x / 255.0;
x = x';


testY = net(x);

testY = round(testY);
% 标签信息
gen = testY(1, :);
for ii=1:nfiles
    currentfilename = imagefiles(ii).name;
    oldname = strsplit(currentfilename, '.');
    newname = [oldname{1} int2str(gen(ii)) '.' oldname{2}];
    movefile(currentfilename,newname)
end
