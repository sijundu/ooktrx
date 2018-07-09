# ooktrx
The file `OOKTRx_slides.pptx` is the slides of the design

## Test
To run the tester:
```sh
sbt 'testOnly ooktrx.{testblock}Spec'
```

## Top-level simulation:
Run the following to send a sequence of random frames with block `TxControl.scala`. The frames will be encoded with CRC, added with frame bits and index and transformed to 1-bit signal. The data is then transmitted in air with a delay of 1 clock cycle and received by the block `RxControl.scala`. The received 1-bit data is reassembled, applied with CRC check and stored in memory.
```sh
sbt 'testOnly ooktrx.SimulatorSpec'
```
