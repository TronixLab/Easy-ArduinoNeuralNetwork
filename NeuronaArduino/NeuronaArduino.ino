#include "Neurona.h"
/************ DATASET ***************
   INPUT  |         OUTPUT
   BINARY | ZERO | ONE | TWO | THREE
    0 0       1     0     0     0
    0 1       0     1     0     0
    1 0       0     0     1     0
    1 1       0     0     0     1
*************************************/

#define NET_INPUTS 2
#define NET_OUTPUTS 4
#define NET_LAYERS 1

double netInput[] = { -1.0, 0.0, 0.0};
int layerSizes[] = {4, NET_OUTPUTS, -1};
int binaryInput;
int lastVal;

double PROGMEM const initW[] = {3.2541715429331592, -0.013970607047324737, 6.740929565586921, -1.8355388413760445,
                                -3.7909369465143423, - 0.994434991836918, - 0.2723735473042747, - 3.8541234711885344,
                                1.6445783467784258, 1.243128810601863, 4.441457678784524, - 1.1767692148731765,
                                0.8214350422948106, - 5.976065673049675, 4.079152052322569, 1.2492887266377122,
                                - 2.5929201417169176, 4.092464431790421, 4.320667806737825, 0.5464616888144275,
                                2.9374166509588178, - 4.164391116057608, 0.47760863499225975, - 5.423398301166093,
                                - 2.1145371156600645, - 2.8232644985779003, 3.796451614582073, 4.195875991373704,
                                5.741912350003685, - 3.179254475409881, - 2.654242747237009, 1.8886089972494804
                               };

MLP mlp(NET_INPUTS, NET_OUTPUTS, layerSizes, MLP::LOGISTIC, initW, true);

/************** MLP(inputs, outputs, topology, activFunc, weights, usingPGM); **************
  Parameters:
  Inputs - the number of inputs to feed the network.
  Outputs - the number of network outputs.
  Topology - an array indicating the size of each layer (including outputs), ending with -1.
  ActivFunc - indicates the activation function to be used.
              Sigmoidal functions:
                - MLP::LOGISTIC = 0 - Logistic function (from 0 to 1)
                - MLP::TANH = 1 - Hyperbolic Tangent function (from -1 to 1)
              Linear function:
                - MLP::LINEAR = 2 - Linear function 
  Weights - an array with the adjusted weights (obtained in training).
  UsingPGM flags - whether weights are a PROGMEM variable.
********************************************************************************************/

char *Number[] = {"ZERO", "ONE", "TWO", "THREE"};
String stringNum = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
  /******** GET INPUT DATA FROM SERIAL MONITOR **********/
  while (Serial.available() > 0) {
    char charNum = Serial.read();
    delay(10);
    stringNum += charNum;
  }

  if (stringNum.length() > 0) {
    binaryInput = stringNum.toInt();
    Serial.println("Input: " + String(binaryInput));
    stringNum = "";
  }

  /******** SET THE INPUT DATA TO NEURAL INPUT *********/
  if (binaryInput == 0) {
    netInput[1] = 0;
    netInput[2] = 0;
  }
  else if (binaryInput == 1) {
    netInput[1] = 0;
    netInput[2] = 1;
  }
  else if (binaryInput == 10) {
    netInput[1] = 1;
    netInput[2] = 0;
  }
  else if (binaryInput == 11) {
    netInput[1] = 1;
    netInput[2] = 1;
  }

  /************* CLASSIFIY THE INPUT DATA **************/
  if (binaryInput != lastVal) {
    Serial.print("OUTPUT: ");
    Serial.println(Number[mlp.getActivation(netInput)]);
  }
  lastVal = binaryInput;
}
