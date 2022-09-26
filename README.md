# Traffic-light-control
A traffic lights system with an on-demand crosswalk button.  Crosswalk buttons let the signal operations know that someone is planning to cross the street, so the light adjusts, giving the pedestrian enough time to get across.
# Steps To Run successfully:
* After Downloading and unzipping the folders don't move or delete any files from `GccApplication 1` folder.
* Open Mictochip Studio and make a new project and select ATmega32 Microcontroller
* Import all the project folders in `GccApplication 1` as it is.
* build the project
# file structure
project is made using **Layered architecture** as follows:
* Application: in this layer we just call the functions in the below layers in the logical flow of the project
* Electronic Unit Abstraction Layer (ECUAL): has all the drivers of the prefrals we're interfacing.
* Microcontroller Abstraction Layer (MCAL): has drivers for the Microcontroller (DIOs, Interrupts, Timers,etc).
* main.c : where we call the Application layer Functions.
# Simulation in Proteus 8 Professional
* take a look at the `documents` floder and open the PDF in there
* apply the system design in Proteus as shown in the screenshot in th PDF
* double click the ATmega32 and choose the `.hex`file from the debug folder
* start simulation
