#pragma once
#include <OVR_CAPI.h>
#include <OVR.h>
#include <OgreRectangle2D.h>

namespace Ogre
{
	class SceneManager;
	class RenderWindow;
	class Camera;
	class SceneNode;
	class Viewport;
}
using namespace OVR;

class Oculus
{
public:
	Oculus(void);
	~Oculus(void);
	bool setupOculus();
	bool setupOgre(Ogre::SceneManager *sm, Ogre::RenderWindow *win, Ogre::Root *mRoot, Ogre::SceneNode *parent = 0);
    void shutDownOculus();
	void shutDownOgre();
	bool InitOculusVR();
	void setupOgreOculus( Ogre::SceneManager *sm, Ogre::RenderWindow* win,Ogre::Root* root);
	void setCameras(  );
	/// Reset orientation of the sensor.
	void resetOrientation();
	/// Retrieve the SceneNode that contains the two cameras used for stereo rendering.
	Ogre::SceneNode *getCameraNode();

	/// Retrieve the current orientation of the Oculus HMD.
	//Ogre::Quaternion getOrientation() const;


	/// Retrieve either of the two cameras.
	Ogre::Camera *getCamera(unsigned int i);

	/// Retrieve either of the two viewports.
	Ogre::Viewport *getViewport(unsigned int i);


	void setTexture( std::string tex );


	Ogre::Viewport *m_viewports[2];
	Ogre::Camera *m_cameras[2];
	ovrVector2f mUVScaleOffset[2][2];
	ovrHmd mHMD;
	float mIPD;
	Ogre::SceneManager* mSceneMgr;

	Ogre::TexturePtr mLeftEyeRenderTexture;
	Ogre::TexturePtr mRightEyeRenderTexture;
	                 
	Ogre::MaterialPtr mMatLeft;
	Ogre::MaterialPtr mMatRight;

	Ogre::Camera* mCamera;
	Ogre::Viewport* mViewport;

protected:
	Ogre::SceneManager *m_sceneManager;
	Ogre::RenderWindow *m_window;
	Ogre::SceneNode *m_cameraNode;
};
