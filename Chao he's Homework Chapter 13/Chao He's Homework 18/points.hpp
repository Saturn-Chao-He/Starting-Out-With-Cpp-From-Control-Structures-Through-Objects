//Specificaton file for the Mortgage class
#ifndef POINTS_H
#define POINTS_H

class Points
{
private:
    int temperature;

public:
    Points()
    { temperature = 0; }

    void setTemperature( int t )
    { temperature = t; }

    int getTemperature() const
    { return temperature; }
    
    bool isEthylFreezing();
    bool isEthylBoiling();
    bool isOxygenFreezing();
    bool isOxygenBoiling();
    bool isWaterFreezing();
    bool isWaterBoiling();

};
#endif