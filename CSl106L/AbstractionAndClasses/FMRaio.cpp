#include "FMRadio.h"

FMRadio::FMRadio()
{
    initialize(87.5, 5);
}
FMRadio::FMRadio(double freq, int vol)
{
    initialize(freq, vol);
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
