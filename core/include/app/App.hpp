#ifndef LEARNOGRE3D_APP_HPP
#define LEARNOGRE3D_APP_HPP

#include <Ogre.h>
#include <OgreApplicationContext.h>

namespace og
{
/**
 * Represent the application
 *
 * @author Dany Pignoux <dany.pignoux@outlook.fr>
 */
class App : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:

    /**
     * Create a new application
     *
     * @param title The application title
     */
    explicit App(const std::string &title);

    /**
     * Executed on app initialization
     */
    void setup() override;

    /**
     * Executed on key pressed
     *
     * @param evt The event
     *
     * @return TRUE if no error, FALSE otherwise
     */
    bool keyPressed(const OgreBites::KeyboardEvent &evt) override;

private:

    /** @var The scene manager */
    Ogre::SceneManager *_sceneManager {nullptr};

    /** @var The shader generator */
    Ogre::RTShader::ShaderGenerator *_shaderGenerator {nullptr};

    /** @var The camera */
    Ogre::Camera *_camera {nullptr};

    /** @var The camera node */
    Ogre::SceneNode *_cameraNode {nullptr};

    /** @var The light */
    Ogre::Light *_light {nullptr};

    /** @var The light node */
    Ogre::SceneNode *_lightNode {nullptr};

    /** @var The mesh entity */
    Ogre::Entity *_meshEntity {nullptr};

    /** @var The mesh node */
    Ogre::SceneNode *_mesh {nullptr};
};
}

#endif //LEARNOGRE3D_APP_HPP
