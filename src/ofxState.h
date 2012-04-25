/*
 *  State.h
 *
 *  Copyright (c) 2011, Neil Mendoza, http://www.neilmendoza.com
 *  All rights reserved. 
 *  
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions are met: 
 *  
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer. 
 *  * Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *  * Neither the name of 16b.it nor the names of its contributors may be used 
 *    to endorse or promote products derived from this software without 
 *    specific prior written permission. 
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 *  POSSIBILITY OF SUCH DAMAGE. 
 *
 */
#pragma once

#include "ofEvents.h"
#ifdef TARGET_WIN32
#include <memory>
#else
#include <tr1/memory>
#endif
#include "ofMain.h"

using namespace tr1;

namespace itg
{
	class ofxEmptyData
	{
	};
	
	template<class SharedData = ofxEmptyData>
	class ofxState
	{
	public:
		virtual void stateEnter() {}
		virtual void stateExit() {}
		virtual void setup() {}
		virtual void update() {}
		virtual void draw() {}
		virtual string getName() = 0;
		
		virtual void touchDown(ofTouchEventArgs& touch) {}
		virtual void touchMoved(ofTouchEventArgs& touch) {}
		virtual void touchUp(ofTouchEventArgs& touch) {}
		virtual void touchDoubleTap(ofTouchEventArgs& touch) {}
		virtual void touchCancelled(ofTouchEventArgs& touch) {}

#ifndef TARGET_OPENGLES
		/* Please use the functions below instead
        virtual void mouseReleased(ofMouseEventArgs& data) {}
		virtual void mousePressed(ofMouseEventArgs& data) {}
		virtual void mouseMoved(ofMouseEventArgs& data) {}
		virtual void mouseDragged(ofMouseEventArgs& data) {}
        */
        
		virtual void mouseMoved(int x, int y) {}
		virtual void mouseDragged(int x, int y, int button) {}
		virtual void mousePressed(int x, int y, int button) {}
		virtual void mouseReleased(int x, int y, int button) {}
		
		virtual void keyPressed(int key) {}
		virtual void keyReleased(int key) {}
#endif
		void changeState(string stateName)
		{
			ofNotifyEvent(changeStateEvent, stateName, this);
		}
		
		ofEvent<string> changeStateEvent;
	
		virtual ~ofxState() {}
		
        SharedData& getSharedData() { return *sharedData; }
		void setSharedData(SharedData* sharedData) { this->sharedData = sharedData; }
		
	private:
		SharedData* sharedData;
	};	
}

namespace Apex = itg;