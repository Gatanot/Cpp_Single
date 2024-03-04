#include <iostream>
#include <cassert>
#include <map>

using namespace std;

class FMRadio
{
private:
    void checkFrequency(double freq);
    void checkPreset(int index);
    void initialize(double freq, int vol);

    double frequency;
    int volume;
    double presets[6];

public:
    FMRadio();
    FMRadio(double freq, int vol);

    double GetFrequency();
    void SetFrequency(double NewFreq);

    int GetVolume();
    void SetVolume(int NewVolume);

    void SetPreset(int index, double freq);
    bool PresetExists(int index);
    double GetPreset(int index);
};

int main(void)
{
    FMRadio myRadio;
    myRadio.SetVolume(8);
    cout << myRadio.GetVolume() << endl;
    double freq = myRadio.GetFrequency();
    cout << freq << endl;
    return 0;
}
void FMRadio::initialize(double freq, int vol)
{
    for (size_t i = 0; i < 6; i++)
    {
        presets[i] = 0.0;
    }
    frequency = freq;
    volume = vol;
}
void FMRadio::checkFrequency(double freq)
{
    assert(freq >= 87.5 && freq <= 108.8);
}
void FMRadio::checkPreset(int index)
{
    assert(index >= 1 && index <= 6);
}

FMRadio::FMRadio()
{
    initialize(87.5, 5);
}
FMRadio::FMRadio(double freq, int vol)
{
    initialize(freq, vol);
}
double FMRadio::GetFrequency()
{
    return frequency;
}
void FMRadio::SetFrequency(double NewFreq)
{
    checkFrequency(NewFreq);
    frequency = NewFreq;
}
int FMRadio::GetVolume()
{
    return volume;
}
void FMRadio::SetVolume(int NewVolume)
{
    assert(NewVolume >= 0 && NewVolume <= 10);
    volume = NewVolume;
}
void FMRadio::SetPreset(int index, double freq)
{
    checkPreset(index);
    checkFrequency(freq);
    presets[index] = freq;
}
bool FMRadio::PresetExists(int index)
{
    checkPreset(index);
    return presets[index - 1] == 0.0;
}
double FMRadio::GetPreset(int index)
{
    checkPreset(index);
    return presets[index - 1];
}