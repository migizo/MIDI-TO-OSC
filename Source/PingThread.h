/*
  ==============================================================================

    PingThread.h
    Created: 30 Mar 2021 8:37:50am
    Author:  migizo
    reference: https://gist.github.com/stephanschulz/ce11d7e6e5734f74688d969f9c9fe86f

  ==============================================================================
*/

#pragma once

#include "CustomizableThread.h"
#include "SystemCommand.h"

class PingThread {
public:
    enum ConnectStatus {
        STANDBY,
        SUCCESS,
        ERROR
    };
    int cnt = 0;
    PingThread() {
        connectStatus = STANDBY;

        pingThread.onRun = [this](CustomizableThread &self) {
            for( ; self.threadShouldExit() == false ; ) {
                
                if (enable) {

                    juce::String command = "ping -c 1 -W 500 ";
                    command += hostName;
                    juce::String res(juceUtil::systemCommand(command.toRawUTF8()));
                    juce::String startReceiveMsg(" packets received");
                    juce::String endReceiveMsg(", ");
                    int startPos, endPos;
        
                    // check string end pos
                    endPos = res.indexOfIgnoreCase(startReceiveMsg);
                    if (endPos != -1) {
            
                        // check string start pos
                        juce::String sub = res.substring(0, endPos);
                        startPos = sub.lastIndexOf(endReceiveMsg);
                        if (startPos != -1) {
                
                            // check receivedNum
                            juce::String receivedNum = res.substring(startPos + endReceiveMsg.length() - 1, endPos);
                            if (receivedNum.getIntValue() > 0) connectStatus = SUCCESS;
                            else {connectStatus = ERROR;}
                        }
                        else connectStatus = ERROR;
                    }
                    else connectStatus = ERROR;
                }
          
                juce::Thread::sleep(500); // 0.5sec
            }

        };
        pingThread.startThread();
    }
    
    //--------------------------------------------------
    ~PingThread() {
        pingThread.signalThreadShouldExit();
        pingThread.stopThread(-1); // スレッドの終了を待機
    }
    
    //--------------------------------------------------
    ConnectStatus getConnectStatus() {return connectStatus;}
    //--------------------------------------------------
    void setHostName(const juce::String& hostName) {this->hostName = hostName;}
    //--------------------------------------------------
    void start() {
        connectStatus = STANDBY;
        enable = true;
    }
    //--------------------------------------------------
    void stop() {
        connectStatus = STANDBY;
        enable = false;
    }
    
    //--------------------------------------------------

private:
    juce::String hostName = juce::String("");
    CustomizableThread pingThread{"pingThread"};
    ConnectStatus connectStatus = STANDBY;
    bool enable = false;

};
