# Geiger_tube_with_arduino
Geiger counter based on arduino

From P3 on circuit pin named VIN we getting information about event. There is a voltage drop at this pin, when ionize partical enters the tube. 
We wire that output to 2 digital pin on arduino board.
Code get number of counts and depending on the selected calibration radioactive element (chose conversion_factor_Co_60 or conversion_factor_Cs_137) calaculate the dose over the integration time and average dose from power on.
For clarity to arduino plugged in LCD LCM1602, to which information about dose is displayed.

File Geiger Counter circuit.pdf contain principal scheme of Geiger counter.
