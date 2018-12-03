//
//  JointSensor.h
//  Stonefish
//
//  Created by Patryk Cieślak on 20/11/2018.
//  Copyright (c) 2018 Patryk Cieslak. All rights reserved.
//

#ifndef __Stonefish_JointSensor__
#define __Stonefish_JointSensor__

#include "sensors/ScalarSensor.h"

namespace sf
{
    class FeatherstoneEntity;
    class Joint;
    
    //!
    class JointSensor : public ScalarSensor
    {
    public:
        JointSensor(std::string uniqueName, Scalar frequency, int historyLength);
        
        virtual void InternalUpdate(Scalar dt) = 0;
        
        virtual void AttachToJoint(FeatherstoneEntity* multibody, unsigned int jointId);
        virtual void AttachToJoint(Joint* joint);
        SensorType getType();
        
    protected:
        FeatherstoneEntity* fe;
        unsigned int jId;
        Joint* j;
    };
}

#endif
