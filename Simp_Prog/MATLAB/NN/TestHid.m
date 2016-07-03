% 用来遍历隐藏层大小，然后看效果

clc
clear
result = zeros([39, 43201]);

imagefiles = dir('*.jpg');
nfiles = length(imagefiles);
for ii=1:nfiles
   currentfilename = imagefiles(ii).name;
   currentimage = imread(currentfilename);
   graypic = rgb2gray(currentimage);
   [pathstr,name,ext] = fileparts(currentfilename);
   
   gen = str2num(name(end));
   v = reshape(graypic, [1 43200]);
   result(ii, :) = [v gen];
end

x = result(:, 1:end-1);
t = [result(:, end) abs(result(:, end) - 1)];
x = x';
t = t';

testnum = 100;
testX = x(:, 1:testnum);
testT = t(:, 1:testnum);
x = x(:, testnum+1:end);
t = t(:, testnum+1:end);

corr = [];
incorr = [];
hid_beg = 5;
hid_end = 100;
for ii= hid_beg:hid_end
    net = patternnet(ii);
    %view(net)
    [net,tr] = train(net,x,t);
    nntraintool;
    %plotperform(tr)
    testY = net(testX);
    %plotconfusion(testT,testY)
    [c,cm] = confusion(testT,testY);
    corr = [corr 100*(1-c)];
    incorr = [incorr 100*c];
end

hid_sizes = linspace(hid_beg, hid_end, length(corr));
plot(hid_sizes, corr, hid_sizes, incorr)
