% 从数据文件data.txt中读出数据
% 并用模式识别网络训练和应用


clc
clear

fid=fopen('data.txt','r');
chardata = [];
result = [];

resize_percent = 0.25;

while 1
    tline = fgetl(fid);
    if(~ischar(tline))
       break
    end


    chardata = strsplit(tline);
    tmp = str2double(chardata);
    tmp = tmp(:, 1:2701);
    %tmp = int8(tmp);
    result = [result; tmp];
   
end
fclose(fid);


% 制作样本集，x为样本，t为标签信息（0 1）女，（1 0）男
% 样本集都以列为单位
x = result(:, 1:end-1);
t = [result(:, end) abs(result(:, end) - 1)];
x = x';
t = t';

% 从样本集中取一部分（textX, testT）出来不训练 ，最后用来检验网络的准确率
testpercent = 0.3;
samptotal = size(t);
samptotal = samptotal(2);
testnum = samptotal * testpercent;
testX = x(:, 1:testnum);
testT = t(:, 1:testnum);
x = x(:, testnum+1:end);
t = t(:, testnum+1:end);

% 建立网络
net = patternnet(5);
view(net)
[net,tr] = train(net,x,t);  % 训练
nntraintool;
plotperform(tr)

% 用留出的样本集进行检验
testY = net(testX);
plotconfusion(testT,testY)
[c,cm] = confusion(testT,testY);
fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));
fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);

% 用全体样本集进行检验
testY = net(x);
plotconfusion(t,testY)
[c,cm] = confusion(t,testY);
fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));
fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);


% 保存训练好的网络
save net
copyfile('net.mat','~/图片/test/')
