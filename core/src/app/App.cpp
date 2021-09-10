#include "app/App.hpp"

namespace og
{
App::App(const std::string &title)
    : ApplicationContextSDL(title)
{
}

void App::setup()
{
    // do not forget to call the base first
    OgreBites::ApplicationContext::setup();

    // register for input events
    addInputListener(this);

    // get a pointer to the already created root
    Ogre::Root *root = getRoot();
    _sceneManager = root->createSceneManager();

    // register our scene with the RTSS
    _shaderGenerator = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    _shaderGenerator->addSceneManager(_sceneManager);

    // without light we would just get a black screen
    _light = _sceneManager->createLight("MainLight");
    _lightNode = _sceneManager->getRootSceneNode()->createChildSceneNode();
    _lightNode->setPosition(0, 10, 15);
    _lightNode->attachObject(_light);

    // also need to tell where we are
    _cameraNode = _sceneManager->getRootSceneNode()->createChildSceneNode();
    _cameraNode->setPosition(0, 0, 15);
    _cameraNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

    // create the camera
    _camera = _sceneManager->createCamera("myCam");
    _camera->setNearClipDistance(5); // specific to this sample
    _camera->setAutoAspectRatio(true);
    _cameraNode->attachObject(_camera);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(_camera);

    // finally something to render
    _meshEntity = _sceneManager->createEntity("Sinbad.mesh");
    _mesh = _sceneManager->getRootSceneNode()->createChildSceneNode();
    _mesh->attachObject(_meshEntity);
}

bool App::keyPressed(const OgreBites::KeyboardEvent &evt)
{
    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }

    if (evt.keysym.sym == OgreBites::SDLK_UP)
    {
        _cameraNode->translate(Ogre::Vector3 {0, 0, -1}, Ogre::Node::TS_LOCAL);
    }
    else if (evt.keysym.sym == OgreBites::SDLK_DOWN)
    {
        _cameraNode->translate(Ogre::Vector3 {0, 0, 1}, Ogre::Node::TS_LOCAL);
    }

    if (evt.keysym.sym == OgreBites::SDLK_LEFT)
    {
        _cameraNode->rotate(Ogre::Vector3 {0, 1, 0}, Ogre::Radian {Ogre::Degree {15.0f}});
    }
    else if (evt.keysym.sym == OgreBites::SDLK_RIGHT)
    {
        _cameraNode->rotate(Ogre::Vector3 {0, -1, 0}, Ogre::Radian {Ogre::Degree {15.0f}});
    }

    return true;
}
}
