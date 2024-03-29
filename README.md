# Smart Home Project based on RTOS 🧩
##  System Architecture  
![Arcitecture](https://github.com/ahmed2-salah/SmartHome_RTOS/assets/90197922/ab6f799d-9f00-48cf-8f74-a96e517e181e)

## Systems Tasks
1. SwitchHandle ()
2. LED Control  ()
3. doorSensorRead ()
4. Buzzer Control ()
5. LCD display ()
6. Temperature Read()
7. UART communication ()

## System Shared resources
1. LED_sw_State
2. door_sw_State
3. Temp_value

## System design
* Creating Binary SemaphoreA to sychronize between  LED Control  () and SwitchHandle ().
* Creating Binary SemaphoreB to sychronize between  doorSensorRead () and Buzzer Control ().
* Creating counting Semaphore to protect LCD (Hardware shared resource) with intial cout = 3
![Tasks1](https://github.com/ahmed2-salah/SmartHome_RTOS/assets/90197922/384719a6-290d-49a0-a7b9-5dc1e3ef73cb)

## Tasks Table
![Task_Table](https://github.com/ahmed2-salah/SmartHome_RTOS/assets/90197922/ae9bee23-d315-46cf-b90f-c5956b86a35d)

## Tasks Simulation
![graph](https://github.com/ahmed2-salah/SmartHome_RTOS/assets/90197922/d0abadca-fc46-4f07-9148-6b9be714a1c5)

## Simulation
![Simulation](https://github.com/ahmed2-salah/SmartHome_RTOS/assets/90197922/3e656bb6-7fb9-4275-8c6b-8b54b2d6148b)

## Linkedin 
https://www.linkedin.com/in/ahmed2-salah/
