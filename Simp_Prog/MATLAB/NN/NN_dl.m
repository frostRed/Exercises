% 一个简单的深度学习
% 两个autoencoder
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
inputSize = size(result);
inputSize= inputSize(2)-1;
% 制作样本集，x为样本，t为标签信息（0 1）女，（1 0）男
% 样本集都以列为单位
xTrain = result(:, 1:end-1);
tTrain = [result(:, end) abs(result(:, end) - 1)];
%xTrain = xTrain / 255.0;
xTrain = xTrain';
tTrain = tTrain';


% 第一个autoencoder网络
hiddenSize1 = 80;  % autoencoder隐藏层大小

% autoencoder参数设置 
autoenc1 = feedforwardnet(hiddenSize1);
autoenc1.trainFcn = 'trainscg';
autoenc2.trainParam.epochs = 100;  % 训练回合
autoenc1.inputs{1}.processFcns = {};
autoenc1.outputs{2}.processFcns = {};
autoenc1.layers{1}.transferFcn = 'logsig';
autoenc1.layers{2}.transferFcn = 'logsig';
autoenc1.divideFcn = 'dividetrain';

autoenc1.performFcn = 'msesparse';
autoenc1.performParam.L2WeightRegularization = 0.004;
autoenc1.performParam.sparsityRegularization = 4;
autoenc1.performParam.sparsity = 0.15;

% autoencoder用样本集训练
autoenc1 = train(autoenc1,xTrain,xTrain);
view(autoenc1);

%W1 = autoenc1.IW{1};
%weightsImage = helperWeightsToImageGallery(W1,imageHeight,imageWidth,10,10);
%imshow(weightsImage);


% 建立一个新的网络，就第一个autoencoder网络去除输出层后的一个复本
% 需要从第一个autoencoder网络中复制出权重和偏置
% 用这个新的网络对样本进行应用，看结果怎么样
autoencHid1 = network;

% Set the number of inputs and layers
autoencHid1.numInputs = 1;
autoencHid1.numlayers = 1;  % 网络只有一层

% Connect the 1st (and only) layer to the 1st input, and also connect the
% 1st layer to the output
autoencHid1.inputConnect(1,1) = 1;
autoencHid1.outputConnect = 1;

% Add a connection for a bias term to the first layer
autoencHid1.biasConnect = 1;

% Set the size of the input and the 1st layer
autoencHid1.inputs{1}.size = inputSize;
autoencHid1.layers{1}.size = hiddenSize1;

% Use the logistic sigmoid transfer function for the first layer
autoencHid1.layers{1}.transferFcn = 'logsig';

% 复制权重和偏置
autoencHid1.IW{1,1} = autoenc1.IW{1,1};
autoencHid1.b{1,1} = autoenc1.b{1,1};

view(autoencHid1);

% 应用在不带标签的样本上面
feat1 = autoencHid1(xTrain);


% 第二个autoencoder网络
hiddenSize2 = 40;

autoenc2 = feedforwardnet(hiddenSize2);
autoenc2.trainFcn = 'trainscg';
autoenc2.trainParam.epochs = 100;

% Do not use process functions at the input or output
autoenc2.inputs{1}.processFcns = {};
autoenc2.outputs{2}.processFcns = {};

% Set the transfer function for both layers to the logistic sigmoid
autoenc2.layers{1}.transferFcn = 'logsig';
autoenc2.layers{2}.transferFcn = 'logsig';

% Use all of the data for training
autoenc2.divideFcn = 'dividetrain';

% Use the mean squared error with L2 weight and sparsity regularizers for
% the performance function
autoenc2.performFcn = 'msesparse';

% You can experiment by altering these parameters
autoenc2.performParam.L2WeightRegularization = 0.002;
autoenc2.performParam.sparsityRegularization = 4;
autoenc2.performParam.sparsity = 0.1;

% 对第二个autoencoder进行训练
autoenc2 = train(autoenc2,feat1,feat1);
view(autoenc2);


% 同样需要得到第二个autoencoder去除输出层后的复本
autoencHid2 = network;

% Set the number of inputs and layers
autoencHid2.numInputs = 1;
autoencHid2.numlayers = 1;

% Connect the 1st (and only) layer to the 1st input, and also connect the
% 1st layer to the output
autoencHid2.inputConnect(1,1) = 1;
autoencHid2.outputConnect = 1;

% Add a connection for a bias term to the first layer
autoencHid2.biasConnect = 1;

% Set the size of the input and the 1st layer
autoencHid2.inputs{1}.size = hiddenSize1;
autoencHid2.layers{1}.size = hiddenSize2;

% Use the logistic sigmoid transfer function for the first layer
autoencHid2.layers{1}.transferFcn = 'logsig';

% 复制权重和偏置
autoencHid2.IW{1,1} = autoenc2.IW{1,1};
autoencHid2.b{1,1} = autoenc2.b{1,1};

view(autoencHid2);

% 应用网络
feat2 = autoencHid2(feat1);


% 最后一层使用Softmax去分类
finalSoftmax = network;

% Set the number of inputs and layers
finalSoftmax.numInputs = 1;
finalSoftmax.numLayers = 1;

% Connect the 1st (and only) layer to the 1st input, and connect the 1st
% layer to the output
finalSoftmax.inputConnect(1,1) = 1;
finalSoftmax.outputConnect = 1;

% Add a connection for a bias term to the first layer
finalSoftmax.biasConnect = 1;

% Set the size of the input and the 1st layer
finalSoftmax.inputs{1}.size = hiddenSize2;
finalSoftmax.layers{1}.size = 2;

% Use the softmax transfer function for the first layer
finalSoftmax.layers{1}.transferFcn = 'softmax';

% Use all of the data for training
finalSoftmax.divideFcn = 'dividetrain';

% Use the cross-entropy performance function
finalSoftmax.performFcn = 'crossentropy';

% You can experiment by the number of training epochs and the training
% function
finalSoftmax.trainFcn = 'trainscg';
finalSoftmax.trainParam.epochs = 400;

% 进行训练
finalSoftmax = train(finalSoftmax,feat2,tTrain);
view(finalSoftmax);


% 三个网络
view(autoencHid1);
view(autoencHid2);
view(finalSoftmax);


% 建立多层网络，权值和偏置从训练好的网络中直接复制
finalNetwork = network;

finalNetwork.numInputs = 1;
finalNetwork.numLayers = 3;

% Connect the 1st layer to the input
finalNetwork.inputConnect(1,1) = 1;

% Connect the 2nd layer to the 1st layer
finalNetwork.layerConnect(2,1) = 1;

% Connect the 3rd layer to the 2nd layer
finalNetwork.layerConnect(3,2) = 1;

% Connect the output to the 3rd layer
finalNetwork.outputConnect(1,3) = 1;

% Add a connection for a bias term for each layer
finalNetwork.biasConnect = [1; 1; 1];

% Set the size of the input
finalNetwork.inputs{1}.size = inputSize;

% Set the size of the first layer to the same as the layer in autoencHid1
finalNetwork.layers{1}.size = hiddenSize1;

% Set the size of the second layer to the same as the layer in autoencHid2
finalNetwork.layers{2}.size = hiddenSize2;

% Set the size of the third layer to the same as the layer in finalSoftmax
finalNetwork.layers{3}.size = 2;

% Set the transfer function for the first layer to the same as in
% autoencHid1
finalNetwork.layers{1}.transferFcn = 'logsig';

% Set the transfer function for the second layer to the same as in
% autoencHid2
finalNetwork.layers{2}.transferFcn = 'logsig';

% Set the transfer function for the third layer to the same as in
% finalSoftmax
finalNetwork.layers{3}.transferFcn = 'softmax';

% Use all of the data for training
finalNetwork.divideFcn = 'dividetrain';

% 从三个训练好的网络中复制权值和偏置
finalNetwork.IW{1,1} = autoencHid1.IW{1,1};
finalNetwork.b{1} = autoencHid1.b{1,1};
finalNetwork.LW{2,1} = autoencHid2.IW{1,1};
finalNetwork.b{2} = autoencHid2.b{1,1};
finalNetwork.LW{3,2} = finalSoftmax.IW{1,1};
finalNetwork.b{3} = finalSoftmax.b{1,1};

% Use the cross-entropy performance function
finalNetwork.performFcn = 'crossentropy';

% You can experiment by changing the number of training epochs and the
% training function
finalNetwork.trainFcn = 'trainscg';
finalNetwork.trainParam.epochs = 100;

view(finalNetwork);

% 对多层网络再训练一次效果更好
train(finalNetwork, xTrain, tTrain);

% 应用在样本上，看分类准确率如何
y = finalNetwork(xTrain);
plotconfusion(tTrain,y);
