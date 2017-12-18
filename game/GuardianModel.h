//
//  GuardianModel.hpp
//  UntoldEngine
//
//  Created by Harold Serrano on 7/19/17.
//  Copyright © 2017 Untold Game Studio. All rights reserved.
//

#ifndef SoccerPlayer_hpp
#define SoccerPlayer_hpp

#include <stdio.h>
#include "U4DGameObject.h"
#include "UserCommonProtocols.h"

class GuardianStateInterface;
class GuardianStateManager;

class GuardianModel:public U4DEngine::U4DGameObject {
    
private:
    
    U4DEngine::U4DAnimation *jumpAnimation;
    U4DEngine::U4DAnimation *runAnimation;
    
    GuardianStateManager *stateManager;
    
    bool ateCoin;
    
public:
    
    GuardianModel();
    
    ~GuardianModel();
    
    bool init(const char* uModelName, const char* uBlenderFile);
    
    void update(double dt);
    
    void playAnimation();
    
    void stopAnimation();
    
    void changeState(GuardianStateInterface* uState);
    
    void setPlayerHeading(U4DEngine::U4DVector3n& uHeading);
    
    void applyForceToPlayer(float uVelocity, double dt);
    
    bool handleMessage(Message &uMsg);
    
    bool guardianAte();
    
    void resetAteCoin();
    
};
#endif /* SoccerPlayer_hpp */