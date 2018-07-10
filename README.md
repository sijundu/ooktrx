# ooktrx
The file `OOKTRx_slides.pptx` is the slides of the design

## Test
To run the tester:
```sh
sbt 'testOnly ooktrx.{testblock}Spec'
```

## Top-level simulation:
The top level design block is `TopControl.scala`, which contains a RX control and a TX control. 

The top level simulator is `TopSimulator.scala`, which employs two `TopControl.scala`. One is used for TX and the other one is for RX. 

The top tester is `TopSimulatorSpec.scala`. Run the following to send a sequence of random frames. The frames will be encoded with CRC, added with frame bits and index and transformed to 1-bit signal. The data is then transmitted in air with a delay of 1 clock cycle and received by another TRX block. The received 1-bit data is reassembled, applied with CRC check and stored in memory.

```sh
sbt 'testOnly ooktrx.TopSimulatorSpec'
```

