#include <iostream>
using namespace std;

class ESensor;

class HomeOwner {
private:
    string name;

public:
    HomeOwner(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};

class WaterHeater {
private:
    int temp;

public:
    WaterHeater() : temp(0) {}

    void setTemp(int temp) {
        temp = temp;
    }

    int gettemp() const {
        return temp;
    }
};

class ESensor {
public:
    int getCurrenttemp() const {
        return 20;
    }
};

class SmartGeyser {
private:
    ESensor* sensor;
    WaterHeater* heater;

public:
    SmartGeyser(ESensor* sensor, WaterHeater* heater) : sensor(sensor), heater(heater) {}

    void activateGeyser() {
        int currentTemp = sensor->getCurrenttemp();
        int requiredTemp = calculateRequiredtemp(currentTemp);
        heater->setTemp(requiredTemp);
    }

private:
    int calculateRequiredtemp(int currentTemp) {
        if (currentTemp <= 10) {
            return 50;
        } else {
            return 40;
        }
    }
};

int main() {
    HomeOwner owner("Guruji");
    ESensor sensor;
    WaterHeater heater;
    SmartGeyser geyser(&sensor, &heater);

    cout << owner.getName() << " gets out of bed." << endl;

    geyser.activateGeyser();

    cout << "Heating temp of water: " << heater.gettemp() << "�C" << endl;
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
