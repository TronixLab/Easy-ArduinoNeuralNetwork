# Easy-ArduinoNeuralNetwork
Artificial Neural Network for Arduino called **Neurona**, tested on Arduino UNO, and MEGA.
[Neurona](https://www.arduino.cc/reference/en/libraries/neurona/) is an Arduino library which allows boards to feed Artificial Neural Network (ANN) structures in order to perform tasks such as pattern recognition (classification), non-linear regression, function approximation and time-series prediction from the [Multi-Layer Perceptron (MLP)](http://www.moretticb.com/blog/multilayer-perceptron-implementation-in-c/) architecture implementation.

In this example, it is a 2-bit binary classification using Neurona library. It is easy and simple to do.

The following steps to implement Neural Networks on Arduino are
1.  Download the [Neurona](https://github.com/MorettiCB/Neurona) library and add it to your Arduino IDE.
2.  Go to [MLP Topology Workbench](http://www.moretticb.com/MTW/).
3.  Click **TRAINING** tab and input the dataset like this

    ![alt tag](https://github.com/TronixLab/Easy-ArduinoNeuralNetwork/blob/main/results/dataSet.jpg?raw=true) 
    
4.  Click **TOPOLOGY** tab and make your neural netowrks of 2 inputs, 1 hidden layer with 4 neurons, and 4 outputs.

    ![alt tag](https://github.com/TronixLab/Easy-ArduinoNeuralNetwork/blob/main/results/networkTopology.jpg?raw=true) 
    
5.  Train your Neural Network model. Go back to **TOPOLOGY**, click *update parameters* then click *iterate*. Wait for a while, after training process, put some data at input nodes and see what will happen to output nodes.

    ![alt tag](https://github.com/TronixLab/Easy-ArduinoNeuralNetwork/blob/main/results/TrainedModel.jpg?raw=true) 

6.  Then click *save*, it will show the weights for each neurons. You will use this to Arduino sketch.

    ![alt tag](https://github.com/TronixLab/Easy-ArduinoNeuralNetwork/blob/main/results/weights.jpg?raw=true) 
    
7.  Prepaper your Arduino sketch. I already did this for your, just hit upload! Then input the data (00, 01, 10, 11) in the Arduino IDE serial monitor.

    ![alt tag](https://github.com/TronixLab/Easy-ArduinoNeuralNetwork/blob/main/results/OUT.jpg?raw=true) 

It so easy! You can implement it to complex data for classification for an example color recognition.
