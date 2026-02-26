//  Test Step 1, Timeout 99 [s]:
  {
     // Action: Set lever position to 2
     set CTRL.LeverPosition to 2

     // Set a trigger variable if the engine speed is high enough
     set trigger T1 when CTRL.MotorSpeed >= 1000

     // When the system is read for this test manipulate the sensor
     when T1:
       set CTRL.MotorSpeed to offset 110

     // Make sure the system detects this failure condition
     within T1 .. T1 & 100 : {
       expect CTRL.BakeState => ENGAGED
       expect CTRL.FailureWarning => 1
     }
  }
