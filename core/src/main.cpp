#include "app/App.hpp"

int main()
{
    og::App app {"Learn Ogre3D"};

    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();

    return 0;
}
