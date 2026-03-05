#include <iostream>

using namespace std;

class DisplayUnit
{
private:
    float screenSize;
    string resolution;
public:
    DisplayUnit() {
        screenSize = 14.0f;
        resolution = "1080p";
    }
    DisplayUnit(float ScreenSize, string Resolution) {
        screenSize = ScreenSize;
        resolution = Resolution;
    }

    float getScreenSize() const {
        return screenSize;
    };
    string getResolution() const {
        return resolution;
    };

    void setScreenSize(float ScreenSize) {
        screenSize = ScreenSize;
    };
    void setResolution(string Resolution) {
        resolution = Resolution;
    };

    void showVisuals() const {
        cout << "Displaying content at " << resolution << " on " << screenSize << " inches screen." << endl;
    }

    ~DisplayUnit() {
        cout << "Display Unit turned off." << endl;
    }
};

class ComputingUnit
{
private:
    string processorModel;
    int ramSize;
public:
    ComputingUnit() {
        processorModel = "i3";
        ramSize = 2;
    }
    ComputingUnit(string ProcessorModel, int RamSize) {
        processorModel = ProcessorModel;
        ramSize = RamSize;
    }

    string getProcessorModel() const {
        return processorModel;
    }
    int getRamSize() const {
        return ramSize;
    }

    void setProcessorModel(string ProcessorModel) {
        processorModel = ProcessorModel;
    }
    void setRamSize(int RamSize) {
        ramSize = RamSize;
    }

    void processStream() const {
        cout << "Decoding video stream using " << processorModel << " (" << ramSize << ") GB RAM." << endl;
    }

    ~ComputingUnit() {
        cout << "Computing Unit turned off" << endl;
    }
};

class Speaker
{
private:
    int wattage;
    string position;
public:
    Speaker() {
        wattage = 5;
        position = "Left";
    }
    Speaker(int Wattage, string Position) {
        wattage = Wattage;
        position = Position;
    }

    void emitSound() const {
        cout << "Boom! Sound coming from " << position << " speaker at " << wattage << " watts." << endl;
    }
    ~Speaker() {
        cout << position << "Speaker turned off." << endl;
    }
};

class SmartTV: public DisplayUnit, public ComputingUnit
{
private:
    string brandName;
    Speaker speakers[2];
public:
    SmartTV(float ScreenSize, string Resolution, string ProcessorModel, int RamSize, string BrandName, int SpeakerWattage):
    DisplayUnit(ScreenSize, Resolution), ComputingUnit(ProcessorModel, RamSize), brandName(BrandName), speakers{Speaker(SpeakerWattage, "Left"), Speaker(SpeakerWattage, "Right")} {}

    void watchMovie() const {
        cout << "\n\n";
        cout << "- - - Starting movie on " << brandName << " TV - - -" << endl;
        showVisuals();
        processStream();
        for (int i = 0; i < 10; i++)
        {
            speakers[i%2].emitSound();
        }
        cout << "\n\n";
    }

    ~SmartTV() {
        cout << brandName << "TV turned off." << endl;
    }
};

int main() {
    SmartTV newTV(48, "16k", "Snapdragon 840", 8, "ShiD", 300);

    newTV.watchMovie();
}
