# Project Stratum
Project Stratum is project to build an embedded application platform on top of FreeRTOS that will provide hardware abstraction, system services, and an application framework for building complex embedded devices.

## Hardware Platform
STM32F769I-DISCO

## IDE
STM32CubeIDE V2.0.0

## Pin configuration
### Console (UART)

|Pin | Signal on Pin |
| :---: | :--- |
| PA9 | USART1_TX |
| PA10 | USART1_RX |

\* NOTE: A USB-UART bridge is required to view and interact with UART Console.

### SDRAM (FMC)

#### SDRAM Data Bus
|Pin | Signal on Pin |
| :---: | :--- |
| PD14 | FMC_D0 |
| PD15 | FMC_D1 |
| PD0 | FMC_D2 |
| PD1 | FMC_D3 |
| PE7 | FMC_D4 |
| PE8 | FMC_D5 |
| PE9 | FMC_D6 |
| PE10 | FMC_D7 |
| PE11 | FMC_D8 |
| PE12 | FMC_D9 |
| PE13 | FMC_D10 |
| PE14 | FMC_D11 |
| PE15 | FMC_D12 |
| PD8 | FMC_D13 |
| PD9 | FMC_D14 |
| PD10 | FMC_D15 |
| PH8 | FMC_D16 |
| PH9 | FMC_D17 |
| PH10 | FMC_D18 |
| PH11 | FMC_D19 |
| PH12 | FMC_D20 |
| PH13 | FMC_D21 |
| PH14 | FMC_D22 |
| PH15 | FMC_D23 |
| PI0 | FMC_D24 |
| PI1 | FMC_D25 |
| PI2 | FMC_D26 |
| PI3 | FMC_D27 |
| PI6 | FMC_D28 |
| PI7 | FMC_D29 |
| PI9 | FMC_D30 |
| PI10 | FMC_D31 |

#### SDRAM Address Bus
|Pin | Signal on Pin |
| :---: | :--- |
| PF0 | FMC_A0 |
| PF1 | FMC_A1 |
| PF2 | FMC_A2 |
| PF3 | FMC_A3 |
| PF4 | FMC_A4 |
| PF5 | FMC_A5 |
| PF12 | FMC_A6 |
| PF13 | FMC_A7 |
| PF14 | FMC_A8 |
| PF15 | FMC_A9 |
| PG0 | FMC_A10 |
| PG1 | FMC_A11 |

#### SDRAM Bank Address
|Pin | Signal on Pin |
| :---: | :--- |
| PG4 | FMC_BA0 |
| PG5 | FMC_BA1 |

#### SDRAM Byte mask
|Pin | Signal on Pin |
| :---: | :--- |
| PE0 | FMC_NBL0 |
| PE1 | FMC_NBL1 |
| PI4 | FMC_NBL2 |
| PI5 | FMC_NBL3 |

#### SDRAM Control Signals
|Pin | Signal on Pin |
| :---: | :--- |
| PG8 | FMC_SDCLK |
| PH2 | FMC_SDCKE0 |
| PH3 | FMC_SDNE0 |
| PF11 | FMC_SDNRAS |
| PG15 | FMC_SDNCAS |
| PH5 | FMC_SDNWE |