# Geiger_tube_with_arduino
Geiger counter based on arduino

  We receive information about the event from the p3 connector from the circuit pin named VIN. There is a voltage drop at this pin, when ionize partical enters the tube. We wire that output to 2 digital pin on arduino board.
  The code gets number of counts and calaculates the dose over the integration time and average dose from power on, depending on the selected calibration radioactive element (chose conversion_factor_Co_60 or conversion_factor_Cs_137). 
  For clarity, the LCD LCM1602 is plugged to arduino to display information about the dose.
  
File Geiger Counter circuit.pdf contains principal scheme of the Geiger counter.
