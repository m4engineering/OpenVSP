//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//
//////////////////////////////////////////////////////////////////////

#include "VSP_Node.H"

/*##############################################################################
#                                                                              #
#                              VSP_NODE constructor                            #
#                                                                              #
##############################################################################*/

VSP_NODE::VSP_NODE(void)
{

    // Nothing to do.... woohoo!

}

/*##############################################################################
#                                                                              #
#                                 VSP_NODE Copy                                #
#                                                                              #
##############################################################################*/

VSP_NODE::VSP_NODE(const VSP_NODE &VSPNode)
{

    // Just use operator = code
    
    *this = VSPNode;

}

/*##############################################################################
#                                                                              #
#                                 VSP_NODE Copy                                #
#                                                                              #
##############################################################################*/

VSP_NODE& VSP_NODE::operator=(const VSP_NODE &VSPNode)
{

    IsTrailingEdgeNode_   = VSPNode.IsTrailingEdgeNode_;
    IsLeadingEdgeNode_    = VSPNode.IsLeadingEdgeNode_;  
    IsBoundaryEdgeNode_   = VSPNode.IsBoundaryEdgeNode_;  
    IsBoundaryCornerNode_ = VSPNode.IsBoundaryCornerNode_;

    x_                    = VSPNode.x_;
    y_                    = VSPNode.y_;
    z_                    = VSPNode.z_;

    dGamma_               = VSPNode.dGamma_;
    Area_                 = VSPNode.Area_;
    
    CoarseGridNode_       = VSPNode.CoarseGridNode_;
    FineGridNode_         = VSPNode.FineGridNode_;  

    return *this;

}

/*##############################################################################
#                                                                              #
#                               VSP_NODE destructor                            #
#                                                                              #
##############################################################################*/

VSP_NODE::~VSP_NODE(void)
{

    // Nothing to do... double woohoo!

}

/*##############################################################################
#                                                                              #
#                       VSP_NODE UpdateGeometryLocation                        #
#                                                                              #
##############################################################################*/

void VSP_NODE::UpdateGeometryLocation(double *TVec, double *OVec, QUAT &Quat, QUAT &InvQuat)
{

    QUAT Vec;
    
    // Update location
    
    Vec(0) = x_ - OVec[0];
    Vec(1) = y_ - OVec[1];
    Vec(2) = z_ - OVec[2];

    Vec = Quat * Vec * InvQuat;

    x_ = Vec(0) + OVec[0] + TVec[0];
    y_ = Vec(1) + OVec[1] + TVec[1];
    z_ = Vec(2) + OVec[2] + TVec[2];    

}



