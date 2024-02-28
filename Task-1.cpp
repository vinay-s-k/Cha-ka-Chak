#include <iostream>
using namespace std;

class HomeOwner;

class ESensor {
public:
    static int getCurrentTemp() {
        return 20; 
    }
};

class WaterHeater {
private:
    int temp;

public:
    WaterHeater() : temp(0) {}

    void settemp(int temp) {
        temp = temp;
    }

    int gettemp() const {
        return temp;
    }
};

class SmartGeyser {
private:
    WaterHeater* heater;

public:
    SmartGeyser(WaterHeater* heater) : heater(heater) {}

    void activateGeyser() {
        int currentTemp = ESensor::getCurrentTemp();
        int requiredTemp = calculateRequiredtemp(currentTemp);
        adjustHeatingSystem(requiredTemp);
    }

private:
    int calculateRequiredtemp(int currentTemp) {
        
        if (currentTemp <= 10) {
            return 50;
        } else {
            return 40; 
        }
    }

    void adjustHeatingSystem(int requiredTemp) {
        heater->settemp(requiredTemp);
    }
};

int main() {
    WaterHeater heater;
    SmartGeyser geyser(&heater);
    cout << "Homeowner gets out of bed." << std::endl;
    geyser.activateGeyser();
    cout << "Heating temp of water: " << heater.gettemp() << "°C" << std::endl;
    return 0;
}


/* Homeowner] -> [Smart Home System]: Gets out of bed
 [Smart Home System] -> [Bathroom Geyser]: activateGeyser()
 [Bathroom Geyser] -> [temp Sensor]: Get current temp
 [temp Sensor] -> [Bathroom Geyser]: Current temp
 [Bathroom Geyser]->[HeatingSystem]: Calculate required temp
 [Heating System] --> [Bathroom Geyser]: Required temp
 [Bathroom Geyser] --> [Smart Home System]: Heating temp
 [Smart Home System] --> [Homeowner]: Geyser activated
 */
