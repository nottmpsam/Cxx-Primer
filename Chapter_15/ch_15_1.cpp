#include <iostream>
class Remote;
class Tv
{
public:
    friend class Remote;   // Remote can access Tv private parts
    enum {Off, On};
    enum {MinVal,MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() {state = (state == On)? Off : On;}
    bool ison() const {return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const; // display all settings
    void settings(const Remote &remote) const;
    void fdklsfdsl();
    bool change_mode(Remote &remote) const;
private: 
    int state;             // on or off
    int volume;            // assumed to be digitized
    int maxchannel;        // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;             // TV or DVD
};

class Remote
{
private:
    int mode;             
public:
    friend class Tv;
    enum  {Normal, Interactive};
    Remote() : mode(Normal) { }
    bool volup(Tv & t) { return t.volup();}
    bool voldown(Tv & t) { return t.voldown();}
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) {t.chanup();}
    void chandown(Tv & t) {t.chandown();}
    void set_chan(Tv & t, int c) {t.channel = c;}
    void set_mode(Tv & t) {t.set_mode();}
    void set_input(Tv & t) {t.set_input();}
    void change_mode() { mode ^= 1; }
    void settings() const;
    void settings(const Tv& tv) const;
};

void Remote::settings(const Tv &tv) const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (tv.state == tv.Off? "Off" : "On") << endl;
    if (tv.state == tv.On)
    {
        cout << "Volume setting = " << tv.volume << endl;
        cout << "Channel setting = " << tv.channel << endl;
        cout << "Mode = "
            << (tv.mode == tv.Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (tv.input == tv.TV? "TV" : "DVD") << endl;
        settings();
    }

}
void Remote::settings() const
{
    std::cout << "Mode(For Remote): "
        <<(mode == Interactive ? "Interactive" : "Normal") << std::endl;
}

bool Tv::change_mode(Remote &remote) const
{
    if (state == On) {
        remote.change_mode();
        return true;
    }
    return false;
}

void Tv::settings(const Remote &remote) const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
        remote.settings();
    }
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "TV is " << (state == Off? "Off" : "On") << endl;
    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}
bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

int
main()
{
    Tv hex;
    Remote hex_remote;
    hex.onoff();
    hex.change_mode(hex_remote);
    hex.settings(hex_remote);
    hex_remote.onoff(hex);
    hex.settings();
    return 0;
}
