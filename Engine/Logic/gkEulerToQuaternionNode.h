/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 Xavier T.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/

#ifndef GKEULERTOQUATERNIONNODE_H
#define GKEULERTOQUATERNIONNODE_H

#include "gkLogicNode.h"

class gkEulerToQuaternionNode : public gkLogicNode
{
public:

	enum
	{
		EUL,
		QUAT
	};

	DECLARE_SOCKET_TYPE(EUL, gkVector3);
	DECLARE_SOCKET_TYPE(QUAT, gkQuaternion);

	gkEulerToQuaternionNode(gkLogicTree* parent, size_t id)
		: gkLogicNode(parent, id)
	{
		ADD_ISOCK(EUL, gkVector3::ZERO);
		ADD_OSOCK(QUAT, gkQuaternion::IDENTITY);
	}

	virtual ~gkEulerToQuaternionNode() {}

	void update(gkScalar tick)
	{
		gkQuaternion out = gkEuler(GET_SOCKET_VALUE(EUL)).toQuaternion();

		SET_SOCKET_VALUE(QUAT, out);
	}

};

#endif // GKEULERTOQUATERNIONNODE_H
