clc
clear
[xTrainImages, tTrain] = digittrain_dataset;
imageWidth = 28;
imageHeight = 28;
inputSize = imageWidth*imageHeight;

% Turn the training images into vectors and put them in a matrix
xTrain = zeros(inputSize, numel(xTrainImages));
for i = 1:numel(xTrainImages)
    xTrain(:,i) = xTrainImages{i}(:);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

hiddenSize1 = 100;
autoenc1 = feedforwardnet(hiddenSize1);
autoenc1.trainFcn = 'trainscg';
autoenc1.trainParam.epochs = 40;
autoenc1.inputs{1}.processFcns = {};
autoenc1.outputs{2}.processFcns = {};
autoenc1.layers{1}.transferFcn = 'logsig';
autoenc1.layers{2}.transferFcn = 'logsig';
autoenc1.divideFcn = 'dividetrain';

autoenc1.performFcn = 'msesparse';
autoenc1.performParam.L2WeightRegularization = 0.004;
autoenc1.performParam.sparsityRegularization = 4;
autoenc1.performParam.sparsity = 0.15;

autoenc1 = train(autoenc1,xTrain,xTrain);
view(autoenc1);


W1 = autoenc1.IW{1};
weightsImage = helperWeightsToImageGallery(W1,imageHeight,imageWidth,10,10);
imshow(weightsImage);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Create an empty network
utoencHid1 = network;

% Set the number of inputs and layers
autoencHid1.numInputs = 1;
autoencHid1.numlayers = 1;

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

% Copy the weights and biases from the first layer of the trained
% autoencoder to this network
autoencHid1.IW{1,1} = autoenc1.IW{1,1};
autoencHid1.b{1,1} = autoenc1.b{1,1};

view(autoencHid1);

feat1 = autoencHid1(xTrain);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

hiddenSize2 = 50;
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

autoenc2 = train(autoenc2,feat1,feat1);
view(autoenc2);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Create an empty network
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

% Copy the weights and biases from the first layer of the second trained
% autoencoder to this network
autoencHid2.IW{1,1} = autoenc2.IW{1,1};
autoencHid2.b{1,1} = autoenc2.b{1,1};

view(autoencHid2);

feat2 = autoencHid2(feat1);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Create an empty network
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
finalSoftmax.layers{1}.size = 10;

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

finalSoftmax = train(finalSoftmax,feat2,tTrain);
view(finalSoftmax);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

view(autoencHid1);
view(autoencHid2);
view(finalSoftmax);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Create an empty network
finalNetwork = network;

% Specify one input and three layers
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
finalNetwork.layers{3}.size = 10;

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

% Copy the weights and biases from the three networks that have already
% been trained
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

view(finalNetwork);

y = finalNetwork(xTrain);
plotconfusion(tTrain,y);


