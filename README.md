# Data Compression using Discrete Cosine Transform in TelosB Mote/Cooja #
The following exercieses, data compression using discrete cosine transform (DCT) time-series signals. For testing electrocardiogram (ECG) signals will be
used. DCT-II transform of a length N signal x is given as:

![Screenshot](images/formular.PNG)

<br/>
where y_k is the k'th DCT coefficient of the signal, x, for a particular k. 

<br/>
The ECG signal that the mote will be compression is the following signal of size N=512

![Screenshot](images/ecg.PNG)




## Goal for this exercise

* Implement and measure the execution time and energy consumption for the following cases, where N = Signal length, M = DCT coefficients 
  * N = 256 and M = 75
  * N = 512 and M = 120
*  Measure the mean square error between the original signal and reconstructed signal for both the cases.

*Optimization possibilities*
* Pi/N is a constant, and should only be calculated once (**Implemented**)
* When both n & k gets big, the compression wil have to take cosine of a big number meaning the algorithm will be slower and slower when we choose a higer signal size N. Instead of taking cosine of some big number, which is very slow. Take cosine of a number that are approximaly the same cosine output as the big number (**Not implemented**) 


## Build commands ##
Make and upload telos b
```
  make TARGET=sky MOTES=/dev/ttyUSB0 knockDetector.upload login
```
 Check serial port:
```
make TARGET=sky motelist
```
compile and upload program
```
make TARGET=sky PORT=/dev/ttyUSB0 knockDetector.upload
```
ssh on the sensor
```
make TARGET=sky PORT=/dev/ttyUSB0 login
```
Clean build
```
make TARGET=sky distclean
```
local sky build

```
 make TARGET=sky
```
