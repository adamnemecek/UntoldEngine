//
//  U4DJoyStick.h
//  UntoldEngine
//
//  Created by Harold Serrano on 8/17/13.
//  Copyright (c) 2013 Untold Engine Studios. All rights reserved.
//

#ifndef __UntoldEngine__U4DJoyStick__
#define __UntoldEngine__U4DJoyStick__

#include <iostream>
#include <vector>
#include "U4DDirector.h"
#include "U4DEntity.h"
#include "U4DImage.h"
#include "U4DTouches.h"
#include "U4DCallbackInterface.h"
#include "CommonProtocols.h"
#import <MetalKit/MetalKit.h>

namespace U4DEngine {
    class U4DControllerInterface;
    class U4DJoystickStateInterface;
    class U4DJoystickStateManager;
}

namespace U4DEngine {
    
class U4DJoyStick:public U4DEntity{
  
private:
    
    U4DJoystickStateManager *stateManager;
    
    float backgroundWidth;
    float backgroundHeight;
    
    float joyStickWidth;
    float joyStickHeight;
    
    
    TOUCHSTATE joyStickState;
    
public:
    
    U4DJoyStick(std::string uName, float xPosition,float yPosition,const char* uBackGroundImage,float uBackgroundWidth,float uBackgroundHeight,const char* uJoyStickImage,float uJoyStickWidth,float uJoyStickHeight);
    
    ~U4DJoyStick();
    
    U4DCallbackInterface *pCallback;
    
    U4DControllerInterface *controllerInterface;
    
    U4DImage backgroundImage;
    U4DImage joyStickImage;
    
    U4DVector3n dataPosition;
    float dataMagnitude;
    
    U4DVector3n originalPosition;
    
    U4DVector3n currentPosition;
    
    U4DVector3n centerBackgroundPosition;
    U4DVector3n centerImagePosition;
    
    float backgroundImageRadius;
    float joyStickImageRadius;
    
    bool isActive;
    
    bool directionReversal;
    
    
    void render(id <MTLRenderCommandEncoder> uRenderEncoder);
    void update(double dt);
    void action();
    
    void setJoyStickWidth(float uJoyStickWidth);
    void setJoyStickHeight(float uJoyStickHeight);
    float getJoyStickWidth();
    float getJoyStickHeight();
    
    
    void setJoyStickBackgroundWidth(float uJoyStickBackgroundWidth);
    void setJoyStickBackgroundHeight(float uJoyStickBackgroundHeight);
    
    float getJoyStickBackgroundWidth();
    float getJoyStickBackgroundHeight();
    
    void changeState(TOUCHSTATE &uTouchState,U4DVector3n &uNewPosition);
    
    TOUCHSTATE getState();
    
    void setDataPosition(U4DVector3n uData);
    U4DVector3n getDataPosition();
    
    void setDataMagnitude(float uValue);
    float getDataMagnitude();
    
    bool getIsActive();
    
    void setCallbackAction(U4DCallbackInterface *uAction);
    
    void setControllerInterface(U4DControllerInterface* uControllerInterface);
    
    bool getDirectionReversal();
};

}

#endif /* defined(__UntoldEngine__U4DJoyStick__) */
