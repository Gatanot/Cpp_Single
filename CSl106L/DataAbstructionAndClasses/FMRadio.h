#ifndef FMRadio_Included
#define FMRadio_Included

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

#endif