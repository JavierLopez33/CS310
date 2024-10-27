#include <iostream>

using namespace std;


class VideoGamePlatform
{
public:
    VideoGamePlatform() {}

    void OwnedPlatform() const
    {
        cout << "\nI own a PS5 and a PC, but I prefer to play on the PC since I have more options for modding games." << endl;
    }
};

class PS5 :public VideoGamePlatform
{
public:
    PS5() : VideoGamePlatform() {}
};


class PC :public VideoGamePlatform
{
public:
    PC() : VideoGamePlatform() {}
};


int main()
{
    PC myPC;

    myPC.OwnedPlatform();

    cout << "\nPress any key to continue..." << endl;

    return 0;
}